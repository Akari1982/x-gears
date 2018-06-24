#include <Ogre.h>
#include <Overlay/OgreOverlayManager.h>
#include <Overlay/OgreOverlaySystem.h>
#include <Overlay/OgreTextAreaOverlayElement.h>
#include <OIS.h>

#include "DebugDraw.h"
#include "FileSystem.h"
#include "Logger.h"



Ogre::Root*                     root;
Ogre::RenderWindow*             window;
std::vector< Ogre::Entity* >    entitys;
Ogre::Camera*                   camera;

DebugDraw* debug_draw;


void Update( float delta );



class DisplayFrameListener : public Ogre::FrameListener, public Ogre::WindowEventListener, public OIS::KeyListener, public OIS::MouseListener
{
public:
    // Constructor takes a RenderWindow because it uses that to determine input context
    DisplayFrameListener( Ogre::RenderWindow* win ):
        m_Window(win),
        m_InputManager( 0 ),
        m_Keyboard( 0 ),
        m_Mouse( 0 ),
        m_MouseRotate( false ),
        m_Exit( false )
    {
        OIS::ParamList pl;
        size_t windowHnd = 0;
        std::ostringstream windowHndStr;

        win->getCustomAttribute( "WINDOW", &windowHnd );
        windowHndStr << windowHnd;
        pl.insert( std::make_pair( std::string( "WINDOW" ), windowHndStr.str() ) );

        pl.insert( std::make_pair( std::string( "w32_mouse" ), std::string( "DISCL_FOREGROUND" ) ) );
        pl.insert( std::make_pair( std::string( "w32_mouse" ), std::string( "DISCL_NONEXCLUSIVE" ) ) );

        using namespace OIS;


        m_InputManager = OIS::InputManager::createInputSystem( pl );

        m_Keyboard = static_cast< OIS::Keyboard* >( m_InputManager->createInputObject( OIS::OISKeyboard, true ) );
        m_Keyboard->setEventCallback( this );

        m_Mouse = static_cast< OIS::Mouse* >( m_InputManager->createInputObject( OIS::OISMouse, true ) );
        m_Mouse->setEventCallback( this );

        //Register as a Window listener
        Ogre::WindowEventUtilities::addWindowEventListener( m_Window, this );



        // debug info
        info_text = static_cast< Ogre::TextAreaOverlayElement* >( Ogre::OverlayManager::getSingleton().createOverlayElement( "TextArea", "DebugText" ) );
        info_text->setCaption( "" );
        info_text->setMetricsMode( Ogre::GMM_PIXELS );
        info_text->setPosition( 5, 5 );
        info_text->setFontName( "BlueHighway" );
        info_text->setCharHeight( 18 );

        Ogre::OverlayContainer* panel = static_cast< Ogre::OverlayContainer* >( Ogre::OverlayManager::getSingleton().createOverlayElement( "Panel", "DebugPanel" ) );
        panel->addChild( info_text );

        info_overlay = Ogre::OverlayManager::getSingleton().create( "DebugOverlay" );
        info_overlay->setZOrder( 1 );
        info_overlay->add2D( panel );
        info_overlay->show();
    }

    virtual
    ~DisplayFrameListener()
    {
        m_InputManager->destroyInputObject( m_Keyboard );

        OIS::InputManager::destroyInputSystem( m_InputManager );

        //Remove ourself as a Window listener
        Ogre::WindowEventUtilities::removeWindowEventListener( m_Window, this );
        windowClosed( m_Window );
    }

    //Unattach OIS before window shutdown (very important under Linux)
    virtual void
    windowClosed( Ogre::RenderWindow* rw )
    {
        m_Exit = true;
    }

    bool
    frameStarted( const Ogre::FrameEvent& evt )
    {
        if( m_Exit == true )
        {
            return false;
        }

        if( m_Keyboard )
        {
            m_Keyboard->capture();
        }

        if( m_Mouse )
        {
            m_Mouse->capture();
        }

        Update( evt.timeSinceLastFrame );

        for( int i = 0; i < entitys.size(); ++i )
        {
            if( entitys[ i ]->isVisible() == true )
            {
                Ogre::AnimationStateIterator animations = entitys[ i ]->getAllAnimationStates()->getAnimationStateIterator();

                while( animations.hasMoreElements() == true )
                {
                    Ogre::AnimationState* state = animations.getNext();

                    if( state->getEnabled() == true )
                    {
                        state->addTime( evt.timeSinceLastFrame );

                        info_text->setCaption( entitys[ i ]->getName() + ": " + state->getAnimationName() );
                    }
                }

                break;
            }
        }

        if( m_Keyboard->isKeyDown( OIS::KC_A ) )
        {
            camera->moveRelative( Ogre::Vector3( -0.1, 0, 0 ) );
        }
        if( m_Keyboard->isKeyDown( OIS::KC_D ) )
        {
            camera->moveRelative( Ogre::Vector3( 0.1, 0, 0 ) );
        }
        if( m_Keyboard->isKeyDown( OIS::KC_W ) )
        {
            camera->moveRelative( Ogre::Vector3( 0, 0, -0.1 ) );
        }
        if( m_Keyboard->isKeyDown( OIS::KC_S ) )
        {
            camera->moveRelative( Ogre::Vector3( 0, 0,  0.1 ) );
        }
        if( m_MouseRotate == true )
        {
            camera->rotate( Ogre::Vector3::UNIT_Y, Ogre::Radian( Ogre::Degree( -m_MouseMoveX * 0.13 ) ) );
            camera->pitch( Ogre::Degree( -m_MouseMoveY * 0.13 ) );
            m_MouseMoveX = 0;
            m_MouseMoveY = 0;
        }

        return true;
    }

    // KeyListener
    bool
    keyPressed( const OIS::KeyEvent& e )
    {
        switch( e.key )
        {
            case OIS::KC_RIGHT:
            {
                bool change = false;
                for( int i = 0; i < entitys.size(); ++i )
                {
                    if( change == true )
                    {
                        entitys[ i ]->setVisible( true );
                        break;
                    }
                    if( entitys[ i ]->isVisible() == true && ( i != entitys.size() - 1 ) )
                    {
                        entitys[ i ]->setVisible( false );
                        change = true;
                    }
                }
            }
            break;

            case OIS::KC_LEFT:
            {
                bool change = false;
                for( int i = entitys.size() - 1; i >= 0; --i )
                {
                    if( change == true )
                    {
                        entitys[ i ]->setVisible( true );
                        break;
                    }
                    if( entitys[ i ]->isVisible() == true && i != 0 )
                    {
                        entitys[ i ]->setVisible( false );
                        change = true;
                    }
                }
            }
            break;

            case OIS::KC_UP:
            {
                bool change = false;
                for( int i = 0; i < entitys.size(); ++i )
                {
                    if( entitys[ i ]->isVisible() == true )
                    {
                        Ogre::AnimationStateIterator animations = entitys[ i ]->getAllAnimationStates()->getAnimationStateIterator();

                        Ogre::AnimationState* old_state;
                        Ogre::AnimationState* new_state = animations.getNext();

                        while( animations.hasMoreElements() == true )
                        {
                            old_state = new_state;
                            new_state = animations.getNext();

                            if( new_state->getEnabled() == true )
                            {
                                new_state->setEnabled( false );
                                new_state->setLoop( false );
                                old_state->setEnabled( true );
                                old_state->setLoop( true );
                            }
                        }

                        break;
                    }
                }
            }
            break;

            case OIS::KC_DOWN:
            {
                bool change = false;
                for( int i = 0; i < entitys.size(); ++i )
                {
                    if( entitys[ i ]->isVisible() == true )
                    {
                        Ogre::AnimationStateIterator animations = entitys[ i ]->getAllAnimationStates()->getAnimationStateIterator();

                        while( animations.hasMoreElements() == true )
                        {
                            Ogre::AnimationState* state = animations.getNext();

                            if( change == true )
                            {
                                state->setEnabled( true );
                                state->setLoop( true );
                                break;
                            }
                            if( state->getEnabled() == true && animations.hasMoreElements() != false )
                            {
                                state->setEnabled( false );
                                state->setLoop( false );
                                change = true;
                            }
                        }

                        break;
                    }
                }
            }
            break;
        }

        return true;
    }

    bool
    keyReleased( const OIS::KeyEvent& e )
    {
        return true;
    }

    bool
    mouseMoved( const OIS::MouseEvent& e )
    {
        m_MouseMoveX = e.state.X.rel;
        m_MouseMoveY = e.state.Y.rel;
        return true;
    }

    bool
    mousePressed( const OIS::MouseEvent& e, OIS::MouseButtonID id )
    {
        if( id == OIS::MB_Right )
        {
            m_MouseRotate = true;
        }
        return true;
    }

    bool
    mouseReleased( const OIS::MouseEvent& e, OIS::MouseButtonID id )
    {
        if( id == OIS::MB_Right )
        {
            m_MouseRotate = false;
        }

        return true;
    }

public:
    Ogre::TextAreaOverlayElement*   info_text;
    Ogre::Overlay*                  info_overlay;

private:
    Ogre::RenderWindow* m_Window;

    //OIS Input devices
    OIS::InputManager*  m_InputManager;
    OIS::Keyboard*      m_Keyboard;
    OIS::Mouse*         m_Mouse;
    float               m_MouseMoveX;
    float               m_MouseMoveY;
    bool                m_MouseRotate;
    bool                m_Exit;
};



DisplayFrameListener* frame_listener;



void
InitializeOgreBase( const Ogre::String& name )
{
    root = new Ogre::Root( "", "" );
    root->loadPlugin( "RenderSystem_Direct3D9.dll" );
    root->setRenderSystem( root->getAvailableRenderers()[ 0 ] );
    root->initialise( false );
    Ogre::NameValuePairList misc;
    misc[ "title" ] = name;
    window = root->createRenderWindow( "QGearsWindow", 1280, 720, false, &misc );



    Ogre::SceneManager* scene_manager;
    Ogre::Viewport*     viewport;

    scene_manager = root->createSceneManager( Ogre::ST_GENERIC, "Scene" );
    scene_manager->clearScene();
    scene_manager->setAmbientLight( Ogre::ColourValue( 1.0, 1.0, 1.0 ) );

    Ogre::OverlaySystem* overlay_system = new Ogre::OverlaySystem();
    scene_manager->addRenderQueueListener( overlay_system );



    // initialize resource
    Ogre::ResourceGroupManager::getSingleton().addResourceLocation( "./data", "FileSystem", "General" );
    Ogre::ResourceGroupManager::getSingleton().addResourceLocation( "./exported", "FileSystem", "General" );
    Ogre::ResourceGroupManager::getSingleton().addResourceLocation( "./data/OgreCore.zip", "Zip", "Bootstrap" );
    Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();



    frame_listener = new DisplayFrameListener( window );
    root->addFrameListener( frame_listener );

    camera = scene_manager->createCamera( "Camera" );
    camera->setNearClipDistance( 0.01f );
    camera->setPosition( 10, 5, 10 );
    camera->lookAt( 0, 0, 0 );

    viewport = window->addViewport( camera );
    viewport->setBackgroundColour( Ogre::ColourValue( 0, 0, 0 ) );
    camera->setAspectRatio( Ogre::Real( viewport->getActualWidth() ) / Ogre::Real( viewport->getActualHeight() ) );



    FILESYSTEM = new FileSystem();
    LOGGER = new Logger( "x-gears.log" );

    debug_draw = new DebugDraw();
};



void
DeinitializeOgreBase()
{
    delete debug_draw;

    delete LOGGER;
    delete FILESYSTEM;

    delete root;
    delete frame_listener;
};
