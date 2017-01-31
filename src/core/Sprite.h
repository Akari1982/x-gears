#ifndef SPRITE_H
#define SPRITE_H

#include <OgreRenderQueueListener.h>
#include <OgreHardwareVertexBuffer.h>
#include <OgreRoot.h>
#include <OgreString.h>
#include <vector>


class Sprite : public Ogre::RenderQueueListener
{
public:
    struct Tile
    {
        int x;
        int y;
        int u;
        int v;
        int width;
        int height;
    };
    struct Frame
    {
        std::vector< Tile > tile;
    };

public:
    Sprite( const Ogre::String& name, Ogre::SceneNode* node );
    virtual ~Sprite();

    void AddFrame( const Frame& frame );
    void SetImage( const Ogre::String& image );

    void Initialise();

    void Update();
    void UpdateGeometry();
    void UpdateDebug();

    void CreateVertexBuffer();
    void DestroyVertexBuffer();

    void renderQueueStarted( Ogre::uint8 queueGroupId, const Ogre::String& invocation, bool& skipThisInvocation );

protected:
    Ogre::String m_Name;

    Ogre::SceneNode* m_SceneNode;

    unsigned int m_FrameId;
    std::vector< Frame > m_Frame;

    Ogre::MaterialPtr m_Material;
    Ogre::SceneManager* m_SceneManager;
    Ogre::RenderSystem* m_RenderSystem;

    unsigned int m_MaxVertexCount;
    Ogre::RenderOperation m_RenderOp;
    Ogre::HardwareVertexBufferSharedPtr m_VertexBuffer;
};



#endif // SPRITE_H
