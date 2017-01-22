#include "Sprite.h"

#include "DebugDraw.h"
#include "Logger.h"
#include "XmlSpriteFile.h"

#include <OgreHardwareBufferManager.h>



Sprite::Sprite( const Ogre::String& name ):
    m_Name( name ),
    m_FrameId( 1 )
{
    Initialise();

    XmlSpriteFile* sprite_file = new XmlSpriteFile( "./data/sprites/field/dan.xml" );
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
Sprite::AddFrame( const Frame& frame )
{
    m_Frame.push_back( frame );
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
    tex->setTextureName( "sprites/field/dan.png" );
    tex->setNumMipmaps( -1 );
    tex->setTextureFiltering( Ogre::TFO_NONE );

    m_SceneManager->addRenderQueueListener( this );
}



void
Sprite::Update()
{
    UpdateGeometry();
    UpdateDebug();
}



void
Sprite::UpdateDebug()
{
    int global_x = 100;
    int global_y = 300;
    float scale = 4.0f;

    DEBUG_DRAW.SetScreenSpace( true );
    DEBUG_DRAW.SetColour( Ogre::ColourValue( 1, 0, 0, 1 ) );

    Frame frame = m_Frame[ m_FrameId ];
    for( size_t i = 0; i < frame.tile.size(); ++i )
    {
        int x1 = global_x + frame.tile[ i ].x * scale;
        int x2 = global_x + frame.tile[ i ].x * scale + frame.tile[ i ].width * scale;
        int y1 = global_y + frame.tile[ i ].y * scale;
        int y2 = global_y + frame.tile[ i ].y * scale + frame.tile[ i ].height * scale;

        DEBUG_DRAW.Line( x1, y1, x2, y1 );
        DEBUG_DRAW.Line( x1, y2, x2, y2 );
        DEBUG_DRAW.Line( x2, y1, x2, y2 );
        DEBUG_DRAW.Line( x1, y1, x1, y2 );
    }

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

    int global_x = 100;
    int global_y = 300;
    float scale = 4.0f;

    Frame frame = m_Frame[ m_FrameId ];
    for( size_t i = 0; i < frame.tile.size(); ++i )
    {
        float new_x1 = ( global_x + frame.tile[ i ].x * scale ) / width * 2 - 1;
        float new_y1 = -( ( global_y + frame.tile[ i ].y * scale ) / height * 2 - 1 );
        float new_x2 = ( global_x + frame.tile[ i ].x * scale +frame.tile[ i ].width * scale ) / width * 2 - 1;
        float new_y2 = -( ( global_y + frame.tile[ i ].y * scale + frame.tile[ i ].height * scale ) / height * 2 - 1 );

        float tex_x1 = frame.tile[ i ].u / 255.0f;
        float tex_x2 = ( frame.tile[ i ].u + frame.tile[ i ].width ) / 255.0f;
        float tex_y1 = frame.tile[ i ].v / 255.0f;
        float tex_y2 = ( frame.tile[ i ].v + frame.tile[ i ].height ) / 255.0f;

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



    float new_x1 = 0;
    float new_y1 = 0;
    float new_x2 = 1;
    float new_y2 = 0;
    float new_x3 = 1;
    float new_y3 = -1;
    float new_x4 = 0;
    float new_y4 = -1;

    float tex_x1 = 0;
    float tex_x2 = 1;
    float tex_y1 = 0;
    float tex_y2 = 1;


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
    *writeIterator++ = tex_y1;

    *writeIterator++ = new_x3;
    *writeIterator++ = new_y3;
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

    *writeIterator++ = new_x3;
    *writeIterator++ = new_y3;
    *writeIterator++ = 0;
    *writeIterator++ = 1;
    *writeIterator++ = 1;
    *writeIterator++ = 1;
    *writeIterator++ = 1;
    *writeIterator++ = tex_x2;
    *writeIterator++ = tex_y2;

    *writeIterator++ = new_x4;
    *writeIterator++ = new_y4;
    *writeIterator++ = 0;
    *writeIterator++ = 1;
    *writeIterator++ = 1;
    *writeIterator++ = 1;
    *writeIterator++ = 1;
    *writeIterator++ = tex_x1;
    *writeIterator++ = tex_y2;

    m_RenderOp.vertexData->vertexCount += 6;



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
            m_RenderSystem->_setWorldMatrix( Ogre::Matrix4::IDENTITY );
            m_RenderSystem->_setProjectionMatrix( Ogre::Matrix4::IDENTITY );
            m_RenderSystem->_setViewMatrix( Ogre::Matrix4::IDENTITY );
            m_SceneManager->_setPass( m_Material->getTechnique( 0 )->getPass( 0 ), true, false );
            m_RenderSystem->_render( m_RenderOp );

            m_RenderOp.vertexData->vertexCount = 0;
        }
    }
}
