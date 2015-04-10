#ifndef SPRITE_FILE_H
#define SPRITE_FILE_H



#include <OgreRenderQueueListener.h>
#include <OgreHardwareVertexBuffer.h>
#include <OgreRoot.h>

#include "../../common/File.h"
#include "../../common/Vram.h"



struct Tile
{
    u8 tex_x;
    u8 tex_y;
    s16 x;
    s16 y;
    s8 width;
    s8 height;
};

struct Sprite
{
    std::vector< Tile > frame;
};



class SpriteFile : public File, public Ogre::RenderQueueListener
{
public:
    SpriteFile( File* file, Vram* vram );
    virtual ~SpriteFile();

    void Initialise();

    void Update();
    void UpdateGeometry();

    void CreateVertexBuffer();
    void DestroyVertexBuffer();

    void renderQueueStarted( Ogre::uint8 queueGroupId, const Ogre::String& invocation, bool& skipThisInvocation );

private:
    Sprite m_Sprite;

    Ogre::MaterialPtr                   m_Material;
    Ogre::SceneManager*                 m_SceneManager;
    Ogre::RenderSystem*                 m_RenderSystem;

    unsigned int                        m_MaxVertexCount;
    Ogre::RenderOperation               m_RenderOp;
    Ogre::HardwareVertexBufferSharedPtr m_VertexBuffer;
};



#endif // SPRITE_FILE_H
