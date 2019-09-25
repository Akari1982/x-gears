#include <Ogre.h>

#include "../../common/Logger.h"

#include "BszFile.h"
//#include "AnimationFile.h"
//#include "MeshFile.h"
//#include "SkeletonFile.h"



BszFile::BszFile( const Ogre::String& file ):
    LzsFile( file )
{
    ReadBSZTextureToVram();
}



BszFile::BszFile( File* file ):
    LzsFile( file )
{
    ReadBSZTextureToVram();
}



BszFile::BszFile( File* file, const u32 offset, const u32 length ):
    LzsFile( file, offset, length )
{
    ReadBSZTextureToVram();
}



BszFile::BszFile( u8* buffer, const u32 offset, const u32 length ):
    LzsFile( buffer, offset, length )
{
    ReadBSZTextureToVram();
}



BszFile::~BszFile()
{
}


/*
Ogre::Entity*
BszFile::GetModel( Ogre::Entity* entity, const Unit& unit, const DatModelData dat )
{
    u32 offset_to_model = GetU32LE( 0x10 ) - 0x8014a600;

    VectorTexForGenBsx textures;
    std::vector< s16 > skeleton_length;

    Ogre::MeshPtr mesh = Ogre::MeshManager::getSingleton().create( "export" + unit.name, "General" );
    Ogre::SkeletonPtr skeleton = Ogre::SkeletonManager::getSingleton().create( "export" + unit.name, "General" );

    // mesh
    u32 offset_to_parts = offset_to_model + GetU32LE( offset_to_model + 0x1c ) + GetU16LE( offset_to_model + 0x18 );
    MeshFile file_m( this );
    file_m.GetData( unit.name, offset_to_parts, GetU8( offset_to_model + 0x3 ), mesh, textures );

    // skeleton
    u32 offset_to_bones = offset_to_model + GetU32LE( offset_to_model + 0x1c );
    SkeletonFile file_s( this );
    file_s.GetData( skeleton_length, offset_to_bones, GetU8( offset_to_model + 0x2 ), skeleton );

    // animations
    u32 offset_to_animations = offset_to_model + GetU32LE( offset_to_model + 0x1c ) + GetU16LE( offset_to_model + 0x1a );
    AnimationFile file( this );
    file.GetData( skeleton_length, unit, offset_to_animations, GetU8( offset_to_model + 0x4 ), start_animation, skeleton );

    Ogre::SkeletonSerializer skeleton_serializer;
    skeleton_serializer.exportSkeleton( skeleton.getPointer(), "exported/" + unit.name + ".skeleton" );

    if( entity == NULL )
    {
        // Update bounds
        Ogre::AxisAlignedBox aabb( -999, -999, -999, 999, 999, 999 );
        mesh->_setBounds( aabb, false );
        mesh->_setBoundingSphereRadius( 999 );

        mesh->setSkeletonName( "" + unit.name + ".skeleton" );

        Ogre::MeshSerializer ser;
        ser.exportMesh( mesh.getPointer(), "exported/" + unit.name + ".mesh" );

        // create and export textures for model
        CreateTexture( unit.name, dat.face_id, textures );

        Ogre::MaterialPtr material = Ogre::MaterialManager::getSingleton().create( "" + unit.name, "General" );
        Ogre::Technique* tech = material->getTechnique( 0 );
        Ogre::Pass* pass1 = tech->getPass( 0 );
        pass1->setVertexColourTracking( Ogre::TVC_AMBIENT );
        pass1->setCullingMode( Ogre::CULL_NONE );
        Ogre::Pass* pass2 = tech->createPass();
        pass2->setCullingMode( Ogre::CULL_NONE );
        pass2->setAlphaRejectFunction( Ogre::CMPF_GREATER );
        pass2->setAlphaRejectValue( 0 );
        Ogre::TextureUnitState* tex = pass2->createTextureUnitState();
        //if( dat.face_id != 0x21 )
        //{
            //tex->setTextureScroll( 0.0625 * 2, 0 );
        //}
        tex->setTextureName( "" + unit.name + ".png" );
        tex->setNumMipmaps( 0 );
        tex->setTextureFiltering( Ogre::TFO_NONE );
        Ogre::MaterialSerializer mat;
        mat.exportMaterial( material, "exported/" + unit.name + ".material" );

        Ogre::SceneManager* scene_manager = Ogre::Root::getSingleton().getSceneManager( "Scene" );
        Ogre::Entity* thisEntity = scene_manager->createEntity( unit.name, "" + unit.name + ".mesh" );
        //thisEntity->setDisplaySkeleton(true);
        //thisEntity->setDebugDisplayEnabled(true);
        thisEntity->setVisible( false );
        thisEntity->getAnimationState( "Idle" )->setEnabled( true );
        thisEntity->getAnimationState( "Idle" )->setLoop( true );
        Ogre::SceneNode* thisSceneNode = scene_manager->getRootSceneNode()->createChildSceneNode();
        thisSceneNode->setPosition( 0, 0, 0 );
        thisSceneNode->roll( Ogre::Radian( Ogre::Degree( 180.0f ) ) );
        thisSceneNode->yaw( Ogre::Radian( Ogre::Degree( 120.0f ) ) );
        thisSceneNode->pitch( Ogre::Radian( Ogre::Degree( 90.0f ) ) );
        thisSceneNode->attachObject( thisEntity );

        return thisEntity;
    }
    else
    {
        entity->refreshAvailableAnimationState();
        return NULL;
    }
}
*/

/*
void
BszFile::CreateTexture( const Ogre::String& name, const int face_id, const VectorTexForGenBsx& textures )
{
    int tex_width = 512;
    int tex_height = 256;

    Ogre::TexturePtr ptex;
    Ogre::HardwarePixelBufferSharedPtr buffer;
    ptex = Ogre::TextureManager::getSingleton().createManual( "DynaTex", "General", Ogre::TEX_TYPE_2D, tex_width, tex_height, 0, Ogre::PF_R8G8B8A8, Ogre::TU_STATIC );
    buffer = ptex->getBuffer( 0, 0 );
    buffer->lock( Ogre::HardwareBuffer::HBL_DISCARD );
    const Ogre::PixelBox& pb = buffer->getCurrentLock();

    for( int i = 0; i < textures.size(); ++i )
    {
        CreateTextureFromVram( pb, &m_Vram, textures[ i ].start_x, textures[ i ].start_y, textures[ i ].palette_x, textures[ i ].palette_y, textures[ i ].texture_x, textures[ i ].texture_y, textures[ i ].bpp, true );
    }

    Ogre::Image image;
    image.loadDynamicImage((Ogre::uchar*)pb.data, tex_width, tex_height, Ogre::PF_R8G8B8A8);
    image.save( "exported/" + name + ".png" );
    buffer->unlock();

    return;
}
*/


void
BszFile::ReadBSZTextureToVram()
{
    u32 offset_to_texture = 0x4 + GetU32LE( 0x08 );

    u8 number_of_texture = GetU8( offset_to_texture + 0x04 );

    for( int i = 0; i < number_of_texture; ++i )
    {
        u16 width     = GetU16LE( offset_to_texture + 0x08 + i * 0x0c + 0x00 ) * 2;
        u16 height    = GetU16LE( offset_to_texture + 0x08 + i * 0x0c + 0x02 );
        u16 vram_x    = GetU16LE( offset_to_texture + 0x08 + i * 0x0c + 0x04 ) * 2;
        u16 vram_y    = GetU16LE( offset_to_texture + 0x08 + i * 0x0c + 0x06 );
        u32 start     = offset_to_texture + GetU32LE( offset_to_texture + 0x08 + i * 0x0c + 0x08 );

        for( int y = 0; y < height; ++y )
        {
            for( int x = 0; x < width; ++x )
            {
                m_Vram.PutU8( vram_x + x, vram_y + y, GetU8( start + y * width + x ) );
            }
        }
    }

    m_Vram.Save( "ex.png" );
}
