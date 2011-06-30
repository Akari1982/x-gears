#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <OgreString.h>
#include <vector>



class UiWidget
{
public:
    UiWidget( const Ogre::String& name );
    UiWidget( const Ogre::String& name, const Ogre::String& path_name, UiWidget* parent );
    virtual ~UiWidget();

    void Initialise();
    virtual void Update();
    virtual void OnResize();
    virtual void Render();
    void Show();
    void Hide();

    const Ogre::String& GetName() const;

    void AddChild( UiWidget *widget );
    UiWidget* GetChild( const Ogre::String& name );
    void RemoveAllChildren();

    enum Align
    {
        LEFT,
        RIGHT,
        CENTER
    };

    enum VerticalAlign
    {
        TOP,
        BOTTOM,
        MIDDLE
    };

    void SetAlign( const UiWidget::Align align );
    void SetVerticalAlign( const UiWidget::VerticalAlign valign );
    void SetOriginX( const float x, const float add, const bool percent );
    void SetOriginY( const float y, const float add, const bool percent );
    void SetX( const float x, const float add, const bool percent );
    float GetScreenX() const;
    void SetY( const float y, const float add, const bool percent );
    float GetScreenY() const;
    void SetWidth( const float width, const float add, const bool percent );
    float GetScreenWidth() const;
    void SetHeight( const float height, const float add, const bool percent );
    float GetScreenHeight() const;

private:
    UiWidget();

protected:
    Ogre::String             m_Name;
    Ogre::String             m_PathName;

    UiWidget*                m_Parent;
    std::vector< UiWidget* > m_Children;

    bool                     m_Visible;

    Align                    m_Align;
    VerticalAlign            m_VerticalAlign;
    float                    m_OriginX;
    float                    m_OriginXAdd;
    bool                     m_OriginXPercent;
    float                    m_OriginY;
    float                    m_OriginYAdd;
    bool                     m_OriginYPercent;
    float                    m_X;
    float                    m_XAdd;
    bool                     m_XPercent;
    float                    m_Y;
    float                    m_YAdd;
    bool                     m_YPercent;
    float                    m_Width;
    float                    m_WidthAdd;
    bool                     m_WidthPercent;
    float                    m_Height;
    float                    m_HeightAdd;
    bool                     m_HeightPercent;
};



#endif // UI_WIDGET_H
