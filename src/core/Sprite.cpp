#include "Sprite.h"

#include "CameraManager.h"
#include "ConfigVar.h"
#include "DebugDraw.h"
#include "Logger.h"
#include "Timer.h"
#include "XmlSpriteFile.h"

#include <OgreHardwareBufferManager.h>



ConfigVar cv_debug_sprite( "debug_sprite", "Draw sprite info", "true" );
ConfigVar cv_debug_sprite_frame_id( "debug_sprite_frame_id", "Select frame id to draw", "1" );



Sprite::Sprite( const Ogre::String& name, Ogre::SceneNode* node ):
    m_Name( name ),
    m_SceneNode( node ),
    m_FrameId( 0 )
{
    Initialise();

    m_SceneNode->setPosition( Ogre::Vector3( 10, 0, 0 ) );

    XmlSpriteFile* sprite_file = new XmlSpriteFile( "./data/sprites/field/unknown.xml" );
    sprite_file->Load( this );
    delete sprite_file;
}



Sprite::~Sprite()
{
    m_SceneManager->removeRenderQueueListener( this );

    delete m_RenderOp.vertexData;
    m_RenderOp.vertexData = 0;
    m_VertexBuffer.setNull();
}



void
Sprite::AddFrame( const Frame& frame, const unsigned int id )
{
    if( id == m_Frame.size() )
    {
        m_Frame.push_back( frame );
    }
    else if( id < m_Frame.size() )
    {
        m_Frame[ id ] = frame;
    }
    else if( id > m_Frame.size() )
    {
        m_Frame.resize( id + 1 );
        m_Frame[ id ] = frame;
    }
}



void
Sprite::AddAnimFrameStart( const unsigned int frame_id )
{
}



void
Sprite::SetImage( const Ogre::String& image )
{
    Ogre::Pass* pass = m_Material->getTechnique( 0 )->getPass( 0 );
    Ogre::TextureUnitState* tex = pass->getTextureUnitState( 0 );
    tex->setTextureName( image );
}



void
Sprite::Initialise()
{
    m_SceneManager = Ogre::Root::getSingleton().getSceneManager( "Scene" );
    m_RenderSystem = Ogre::Root::getSingletonPtr()->getRenderSystem();

    m_MaxVertexCount = 128 * 6;
    m_RenderOp.vertexData = new Ogre::VertexData;
    m_RenderOp.vertexData->vertexStart = 0;

    Ogre::VertexDeclaration* vDecl = m_RenderOp.vertexData->vertexDeclaration;

    size_t offset = 0;
    vDecl->addElement( 0, 0, Ogre::VET_FLOAT3, Ogre::VES_POSITION );
    offset += Ogre::VertexElement::getTypeSize( Ogre::VET_FLOAT3 );
    vDecl->addElement( 0, offset, Ogre::VET_FLOAT4, Ogre::VES_DIFFUSE );
    offset += Ogre::VertexElement::getTypeSize( Ogre::VET_FLOAT4 );
    vDecl->addElement( 0, offset, Ogre::VET_FLOAT2, Ogre::VES_TEXTURE_COORDINATES );

    m_VertexBuffer = Ogre::HardwareBufferManager::getSingletonPtr()->createVertexBuffer( vDecl->getVertexSize( 0 ), m_MaxVertexCount, Ogre::HardwareBuffer::HBU_DYNAMIC_WRITE_ONLY, false );

    m_RenderOp.vertexData->vertexBufferBinding->setBinding( 0, m_VertexBuffer );
    m_RenderOp.operationType = Ogre::RenderOperation::OT_TRIANGLE_LIST;
    m_RenderOp.useIndexes = false;

    m_Material = Ogre::MaterialManager::getSingleton().create( "xeno/sprite", "General" );
    Ogre::Pass* pass = m_Material->getTechnique( 0 )->getPass( 0 );
    //pass->setVertexColourTracking( Ogre::TVC_AMBIENT );
    pass->setCullingMode( Ogre::CULL_NONE );
    //pass->setDepthCheckEnabled( true );
    //pass->setDepthWriteEnabled( true );
    pass->setLightingEnabled( false );
    //pass->setSceneBlending( Ogre::SBT_TRANSPARENT_ALPHA );

    //pass->setAlphaRejectFunction( Ogre::CMPF_GREATER );
    //pass->setAlphaRejectValue( 0 );
    Ogre::TextureUnitState* tex = pass->createTextureUnitState();
    tex->setTextureName( "system/blank.png" );
    tex->setNumMipmaps( -1 );
    tex->setTextureFiltering( Ogre::TFO_NONE );

    m_SceneManager->addRenderQueueListener( this );
}



void
Sprite::Update()
{
    float delta = Timer::getSingleton().GetGameTimeDelta();
    static float timer = 0;
    timer += delta;
    if( timer > 1 )
    {
        timer = 0;

        m_FrameId += 1;
        if( m_FrameId >= m_Frame.size() )
        {
            m_FrameId = 0;
        }
    }
    m_FrameId = cv_debug_sprite_frame_id.GetI();
    if( m_FrameId >= m_Frame.size() )
    {
        m_FrameId = 0;
    }



    UpdateGeometry();

    if( cv_debug_sprite.GetB() )
    {
        UpdateDebug();
    }
}



void
Sprite::UpdateDebug()
{
    DEBUG_DRAW.SetScreenSpace( true );
    DEBUG_DRAW.SetColour( Ogre::ColourValue( 1, 0, 0, 1 ) );

    DEBUG_DRAW.Text( 100, 100, "Frame Id:" + Ogre::StringConverter::toString( m_FrameId ) );
}



void
Sprite::UpdateGeometry()
{
    if( m_Frame[ m_FrameId ].tile.size() * 6 > m_MaxVertexCount )
    {
        LOG_ERROR( "Max number of tiles for sprite reached. Max number of tiles is " + Ogre::StringConverter::toString( m_MaxVertexCount / 6 ) + "." );
        return;
    }

    float* writeIterator = ( float* ) m_VertexBuffer->lock( Ogre::HardwareBuffer::HBL_NORMAL );
    writeIterator += m_RenderOp.vertexData->vertexCount * 9;

    float width = Ogre::Root::getSingleton().getRenderTarget( "QGearsWindow" )->getViewport( 0 )->getActualWidth();
    float height = Ogre::Root::getSingleton().getRenderTarget( "QGearsWindow" )->getViewport( 0 )->getActualHeight();

    int global_x = 200;
    int global_y = 500;
    float scale = 8.0f;

    Frame frame = m_Frame[ m_FrameId ];
    for( size_t i = 0; i < frame.tile.size(); ++i )
    {
        float new_x1 = ( global_x + frame.tile[ i ].x * scale ) / width * 2 - 1;
        float new_y1 = -( ( global_y + frame.tile[ i ].y * scale ) / height * 2 - 1 );
        float new_x2 = ( global_x + frame.tile[ i ].x * scale +frame.tile[ i ].width * scale ) / width * 2 - 1;
        float new_y2 = -( ( global_y + frame.tile[ i ].y * scale + frame.tile[ i ].height * scale ) / height * 2 - 1 );

        float tex_x1 = frame.tile[ i ].u / 256.0f;
        float tex_x2 = ( frame.tile[ i ].u + frame.tile[ i ].width ) / 256.0f;
        float tex_y1 = frame.tile[ i ].v / 256.0f;
        float tex_y2 = ( frame.tile[ i ].v + frame.tile[ i ].height ) / 256.0f;

        *writeIterator++ = new_x1;
        *writeIterator++ = new_y1;
        *writeIterator++ = 0;
        *writeIterator++ = 1;
        *writeIterator++ = 1;
        *writeIterator++ = 1;
        *writeIterator++ = 1;
        *writeIterator++ = tex_x1;
        *writeIterator++ = tex_y1;

        *writeIterator++ = new_x2;
        *writeIterator++ = new_y1;
        *writeIterator++ = 0;
        *writeIterator++ = 1;
        *writeIterator++ = 1;
        *writeIterator++ = 1;
        *writeIterator++ = 1;
        *writeIterator++ = tex_x2;
        *writeIterator++ = tex_y1;

        *writeIterator++ = new_x2;
        *writeIterator++ = new_y2;
        *writeIterator++ = 0;
        *writeIterator++ = 1;
        *writeIterator++ = 1;
        *writeIterator++ = 1;
        *writeIterator++ = 1;
        *writeIterator++ = tex_x2;
        *writeIterator++ = tex_y2;

        *writeIterator++ = new_x1;
        *writeIterator++ = new_y1;
        *writeIterator++ = 0;
        *writeIterator++ = 1;
        *writeIterator++ = 1;
        *writeIterator++ = 1;
        *writeIterator++ = 1;
        *writeIterator++ = tex_x1;
        *writeIterator++ = tex_y1;

        *writeIterator++ = new_x2;
        *writeIterator++ = new_y2;
        *writeIterator++ = 0;
        *writeIterator++ = 1;
        *writeIterator++ = 1;
        *writeIterator++ = 1;
        *writeIterator++ = 1;
        *writeIterator++ = tex_x2;
        *writeIterator++ = tex_y2;

        *writeIterator++ = new_x1;
        *writeIterator++ = new_y2;
        *writeIterator++ = 0;
        *writeIterator++ = 1;
        *writeIterator++ = 1;
        *writeIterator++ = 1;
        *writeIterator++ = 1;
        *writeIterator++ = tex_x1;
        *writeIterator++ = tex_y2;

        m_RenderOp.vertexData->vertexCount += 6;
    }



    m_VertexBuffer->unlock();
}



void
Sprite::renderQueueStarted( Ogre::uint8 queueGroupId, const Ogre::String& invocation, bool& skipThisInvocation )
{
    if( queueGroupId == Ogre::RENDER_QUEUE_OVERLAY )
    {
        Ogre::Root::getSingletonPtr()->getRenderSystem()->clearFrameBuffer( Ogre::FBT_DEPTH );

        if( m_RenderOp.vertexData->vertexCount != 0 )
        {
            //m_RenderSystem->_setWorldMatrix( m_SceneNode->_getFullTransform() );
            //m_RenderSystem->_setViewMatrix( CameraManager::getSingleton().GetCurrentCamera()->getViewMatrix( true ) );
            //m_RenderSystem->_setProjectionMatrix( CameraManager::getSingleton().GetCurrentCamera()->getProjectionMatrixRS() );
            m_RenderSystem->_setWorldMatrix( Ogre::Matrix4::IDENTITY );
            m_RenderSystem->_setViewMatrix( Ogre::Matrix4::IDENTITY );
            Ogre::Matrix4 mat;
            m_RenderSystem->_convertProjectionMatrix( Ogre::Matrix4::IDENTITY, mat );
            m_RenderSystem->_setProjectionMatrix( mat );

            m_SceneManager->_setPass( m_Material->getTechnique( 0 )->getPass( 0 ), true, false );
            m_RenderSystem->_render( m_RenderOp );

            m_RenderOp.vertexData->vertexCount = 0;
        }
    }
}
