#include "PacketFile.h"
#include "SpriteFile.h"
#include "../../common/DebugDraw.h"
#include "../../common/Logger.h"
#include "../../common/OgreGenUtilites.h"

#include <OgreHardwareBufferManager.h>



SpriteFile::SpriteFile( File* file, Vram* vram ):
    File( file )
{
    Initialise();

    Logger* log = new Logger( "exported/sprite.txt" );

    MeshData data;
    data.name = "sprite";
    data.tex_width = 256;
    data.tex_height = 256;
    VectorTexForGen textures;

    PacketFile* sub_pack = new PacketFile( file );
    File* sprite0 = sub_pack->ExtractFile( 0 );
    delete sprite0;
    File* sprite1 = sub_pack->ExtractFile( 1 );

    u8 frame_id = 0;
    u16 frame_offset = sprite1->GetU16LE( 0x02 + frame_id * 0x02 );

    u8 number_of_tile = sprite1->GetU8( frame_offset ) & 0x3f;
    u8 double_size_tile = sprite1->GetU8( frame_offset ) & 0x80;

    log->Log( "number_of_tile = 0x" + HexToString( number_of_tile, 2, '0' ) + "\n" );
    log->Log( "double_size_tile = 0x" + HexToString( double_size_tile, 2, '0' ) + "\n" );

    u16 offset_to_tile_position = frame_offset + 0x04 + number_of_tile * 0x02;

    for( u8 i = 0; i < number_of_tile; ++i )
    {
        Tile tile;
        log->Log( "tile_" + HexToString( i, 2, '0' ) + "\n" );
        u16 offset_to_tile_desc = sprite1->GetU16LE( frame_offset + 0x04 + i * 0x02 );

        while( true )
        {
            u8 pos_flag = sprite1->GetU8( offset_to_tile_position );
            log->Log( "    pos_flag = 0x" + HexToString( pos_flag, 2, '0' ) + "\n" );

            if( pos_flag & 0x80 )
            {
                offset_to_tile_position += 1;
                if( pos_flag & 40 )
                {
                    if( pos_flag & 20 )
                    {
                        offset_to_tile_position += 2;
                    }

                    if( pos_flag & 10 )
                    {
                        offset_to_tile_position += 1;
                    }
                }
                else
                {
                    if( pos_flag & 01 ) // width increase
                    {
                        offset_to_tile_position += 1;
                    }
                    if( pos_flag & 02 ) // height increase
                    {
                        offset_to_tile_position += 1;
                    }
                }
            }
            else
            {
                break;
            }
        }



        int clut_x = 0x100;
        int clut_y = 0x1e3;
        int vram_x = 0x140;
        int vram_y = 0x100;
        TexForGen texture;
        texture.palette_x = ( clut_x + ( ( sprite1->GetU8( offset_to_tile_position ) & 0x0f ) << 4 ) ) / 2;
        texture.palette_y = clut_y;
        texture.texture_x = vram_x;
        texture.texture_y = vram_y;
        texture.bpp = BPP_8;
        AddTexture( texture, data, textures, log );



        if( double_size_tile == true )
        {
            tile.x = sprite1->GetU16LE( offset_to_tile_position + 1 );
            log->Log( "    x = 0x" + HexToString( tile.x, 4, '0' ) + "\n" );
            tile.y = sprite1->GetU16LE( offset_to_tile_position + 3 );
            log->Log( "    y = 0x" + HexToString( tile.y, 4, '0' ) + "\n" );
            offset_to_tile_position += 2;
        }
        else
        {
            tile.x = (s8)sprite1->GetU8( offset_to_tile_position + 1 );
            log->Log( "    x = 0x" + HexToString( tile.x, 4, '0' ) + "\n" );
            tile.y = (s8)sprite1->GetU8( offset_to_tile_position + 2 );
            log->Log( "    y = 0x" + HexToString( tile.y, 4, '0' ) + "\n" );
        }
        offset_to_tile_position += 3;



        u8 offset = 0;
        u8 flags = sprite1->GetU8( offset_to_tile_desc + offset ); ++offset;
        log->Log( "    flags = 0x" + HexToString( flags, 2, '0' ) + "\n" );
        if( flags & 0x10 )
        {
            u8 flags2 = sprite1->GetU8( offset_to_tile_desc + offset ); ++offset;
            log->Log( "    flags2 = 0x" + HexToString( flags2, 2, '0' ) + "\n" );
        }


        tile.tex_x = sprite1->GetU8( offset_to_tile_desc + offset ); ++offset;
        log->Log( "    tex_x = 0x" + HexToString( tile.tex_x, 2, '0' ) + "\n" );

        tile.tex_y = sprite1->GetU8( offset_to_tile_desc + offset ); ++offset;
        log->Log( "    tex_y = 0x" + HexToString( tile.tex_y, 2, '0' ) + "\n" );

        tile.width = sprite1->GetU8( offset_to_tile_desc + offset ); ++offset;
        log->Log( "    width = 0x" + HexToString( tile.width, 2, '0' ) + "\n" );

        tile.height = sprite1->GetU8( offset_to_tile_desc + offset ); ++offset;
        log->Log( "    height = 0x" + HexToString( tile.height, 2, '0' ) + "\n" );

        m_Sprite.frame.push_back( tile );
    }



    delete sprite1;
    File* sprite2 = sub_pack->ExtractFile( 2 );
    delete sprite2;
    delete sub_pack;



    // create and export textures for model
    if( textures.size() > 0 )
    {
        CreateTexture( vram, data, "exported/models/xeno/" + data.name + ".png", textures );
    }



    delete log;
}



SpriteFile::~SpriteFile()
{
    m_SceneManager->removeRenderQueueListener( this );

    delete m_RenderOp.vertexData;
    m_RenderOp.vertexData = 0;
    m_VertexBuffer.setNull();
}



void
SpriteFile::Initialise()
{
    m_SceneManager = Ogre::Root::getSingleton().getSceneManager( "Scene" );
    m_RenderSystem = Ogre::Root::getSingletonPtr()->getRenderSystem();

    m_MaxVertexCount = 64 * 6;
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

    m_Material = Ogre::MaterialManager::getSingleton().create( "sprite", "General" );
    Ogre::Pass* pass = m_Material->getTechnique( 0 )->getPass( 0 );
    pass->setVertexColourTracking( Ogre::TVC_AMBIENT );
    pass->setCullingMode( Ogre::CULL_NONE );
    pass->setDepthCheckEnabled( true );
    pass->setDepthWriteEnabled( true );
    pass->setLightingEnabled( false );
    pass->setSceneBlending( Ogre::SBT_TRANSPARENT_ALPHA );

    pass->setAlphaRejectFunction( Ogre::CMPF_GREATER );
    pass->setAlphaRejectValue( 0 );
    Ogre::TextureUnitState* tex = pass->createTextureUnitState();
    //tex->setTextureName( "system/blank.png" );
    tex->setNumMipmaps( -1 );
    tex->setTextureFiltering( Ogre::TFO_NONE );

    m_SceneManager->addRenderQueueListener( this );
}



void
SpriteFile::Update()
{
    s32 global_x = 100;
    s32 global_y = 100;

    DEBUG_DRAW.SetScreenSpace( true );
    DEBUG_DRAW.SetColour( Ogre::ColourValue( 1, 0, 0, 1 ) );

    for( u8 i = 0; i < m_Sprite.frame.size(); ++i )
    {
        s32 x1 = global_x + m_Sprite.frame[ i ].x;
        s32 x2 = global_x + m_Sprite.frame[ i ].x + m_Sprite.frame[ i ].width;
        s32 y1 = global_y + m_Sprite.frame[ i ].y;
        s32 y2 = global_y + m_Sprite.frame[ i ].y + m_Sprite.frame[ i ].height;

        DEBUG_DRAW.Line( x1, y1, x2, y1 );
        DEBUG_DRAW.Line( x1, y2, x2, y2 );
        DEBUG_DRAW.Line( x2, y1, x2, y2 );
        DEBUG_DRAW.Line( x1, y1, x1, y2 );
    }

    UpdateGeometry();
}



void
SpriteFile::UpdateGeometry()
{
    if( m_Sprite.frame.size() * 6 > m_MaxVertexCount )
    {
        LOG_ERROR( "Max number of tiles reached. Max number of tiles is " + Ogre::StringConverter::toString( m_MaxVertexCount / 6 ) + "." );
        return;
    }

    float* writeIterator = ( float* ) m_VertexBuffer->lock( Ogre::HardwareBuffer::HBL_NORMAL );
    writeIterator += m_RenderOp.vertexData->vertexCount * 9;

    float width = Ogre::Root::getSingleton().getRenderTarget( "QGearsWindow" )->getViewport( 0 )->getActualWidth();
    float height = Ogre::Root::getSingleton().getRenderTarget( "QGearsWindow" )->getViewport( 0 )->getActualHeight();

    s32 global_x = 100;
    s32 global_y = 100;

    for( u8 i = 0; i < m_Sprite.frame.size(); ++i )
    {
        float new_x1 = ( global_x + m_Sprite.frame[ i ].x ) / width * 2 - 1;
        float new_y1 = -( ( global_y + m_Sprite.frame[ i ].y ) / height * 2 - 1 );

        float new_x2 = ( global_x + m_Sprite.frame[ i ].x + m_Sprite.frame[ i ].width ) / width * 2 - 1;
        float new_y2 = -( ( global_y + m_Sprite.frame[ i ].y ) / height * 2 - 1 );

        float new_x3 = ( global_x + m_Sprite.frame[ i ].x + m_Sprite.frame[ i ].width ) / width * 2 - 1;
        float new_y3 = -( ( global_y + m_Sprite.frame[ i ].y + m_Sprite.frame[ i ].height ) / height * 2 - 1 );

        float new_x4 = ( global_x + m_Sprite.frame[ i ].x ) / width * 2 - 1;
        float new_y4 = -( ( global_y + m_Sprite.frame[ i ].y + m_Sprite.frame[ i ].height ) / height * 2 - 1 );

        const Ogre::Font::UVRect uv;

        *writeIterator++ = new_x1;
        *writeIterator++ = new_y1;
        *writeIterator++ = 0;
        *writeIterator++ = 1;
        *writeIterator++ = 1;
        *writeIterator++ = 1;
        *writeIterator++ = 1;
        *writeIterator++ = uv.left;
        *writeIterator++ = uv.top;

        *writeIterator++ = new_x2;
        *writeIterator++ = new_y2;
        *writeIterator++ = 0;
        *writeIterator++ = 1;
        *writeIterator++ = 1;
        *writeIterator++ = 1;
        *writeIterator++ = 1;
        *writeIterator++ = uv.right;
        *writeIterator++ = uv.top;

        *writeIterator++ = new_x3;
        *writeIterator++ = new_y3;
        *writeIterator++ = 0;
        *writeIterator++ = 1;
        *writeIterator++ = 1;
        *writeIterator++ = 1;
        *writeIterator++ = 1;
        *writeIterator++ = uv.right;
        *writeIterator++ = uv.bottom;

        *writeIterator++ = new_x1;
        *writeIterator++ = new_y1;
        *writeIterator++ = 0;
        *writeIterator++ = 1;
        *writeIterator++ = 1;
        *writeIterator++ = 1;
        *writeIterator++ = 1;
        *writeIterator++ = uv.left;
        *writeIterator++ = uv.top;

        *writeIterator++ = new_x3;
        *writeIterator++ = new_y3;
        *writeIterator++ = 0;
        *writeIterator++ = 1;
        *writeIterator++ = 1;
        *writeIterator++ = 1;
        *writeIterator++ = 1;
        *writeIterator++ = uv.right;
        *writeIterator++ = uv.bottom;

        *writeIterator++ = new_x4;
        *writeIterator++ = new_y4;
        *writeIterator++ = 0;
        *writeIterator++ = 1;
        *writeIterator++ = 1;
        *writeIterator++ = 1;
        *writeIterator++ = 1;
        *writeIterator++ = uv.left;
        *writeIterator++ = uv.bottom;

        m_RenderOp.vertexData->vertexCount += 6;
    }

    m_VertexBuffer->unlock();
}



void
SpriteFile::renderQueueStarted( Ogre::uint8 queueGroupId, const Ogre::String& invocation, bool& skipThisInvocation )
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
