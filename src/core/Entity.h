#ifndef ENTITY_H
#define ENTITY_H

#include <OgreString.h>

#include "EntityCollision.h"
#include "EntityDirection.h"
#include "ScriptManager.h"



enum EntityAnimation
{
    EA_DEFAULT,
    EA_ONCE
};



enum MoveState
{
    MS_NONE,
    MS_WALKMESH,
    MS_LINEAR,
    LS_JUMP
};



enum ActionType
{
    AT_NONE,
    AT_LINEAR,
    AT_SMOOTH
};



enum TurnDirection
{
    TD_CLOCKWISE,
    TD_ANTICLOCKWISE,
    TD_CLOSEST
};



class Entity
{
public:
                        Entity( const Ogre::String& name, Ogre::SceneNode* node );
    virtual             ~Entity();

    virtual void        Update();

    const Ogre::String& GetName() const;

    void                SetPosition( const Ogre::Vector3& position );
    void                ScriptSetPosition( const float x, const float y, const float z );
    const Ogre::Vector3 GetPosition() const;

    void                SetOffset( const Ogre::Vector3& position );
    const Ogre::Vector3 GetOffset() const;

    void                SetDirection( const Ogre::Degree& direction );
    void                ScriptSetDirection( const float direction );
    const Ogre::Degree  GetDirection() const;

    // height related
    const float         GetHeight() const;

    // solid related
    void                SetSolidRadius( const float radius );
    const float         GetSolidRadius() const;
    void                SetSolid( const bool solid );
    const bool          IsSolid() const;

    // talk related
    void                SetTalkRadius( const float radius );
    const float         GetTalkRadius() const;
    void                SetTalkable( const bool talkable );
    const bool          IsTalkable() const;

    // model related
    virtual void        SetVisible( const bool visible ) = 0;
    virtual const bool  IsVisible() const = 0;

    // movement related
    void                SetMoveState( const MoveState state );
    const MoveState     GetMoveState() const;
    void                SetMoveSpeed( const float speed );
    const float         GetMoveSpeed() const;
    void                SetMoveSpeedRun( const float speed );
    const float         GetMoveSpeedRun() const;
    void                SetMovePosition( const Ogre::Vector3& target );
    const Ogre::Vector3 GetMovePosition() const;
    void                SetMoveTriangleId( const int triangle );
    const int           GetMoveTriangleId() const;
    void                SetMoveAutoRotation( const bool rotate );
    const bool          GetMoveAutoRotation() const;
    void                SetMoveAutoAnimation( const bool animate );
    const bool          GetMoveAutoAnimation() const;
    const Ogre::String& GetMoveAnimationIdleName() const;
    const Ogre::String& GetMoveAnimationWalkName() const;
    const Ogre::String& GetMoveAnimationRunName() const;
    void                ScriptMoveToPosition( const float x, const float y );
    void                ScriptMoveToEntity( Entity* entity );
    const int           ScriptMoveSync();
    void                UnsetMove();

    // offset related
    void                ScriptOffsetToPosition( const float x, const float y, const float z, const ActionType type, const float seconds );
    const int           ScriptOffsetSync();
    void                UnsetOffset();
    const Ogre::Vector3 GetOffsetPositionStart() const;
    const Ogre::Vector3 GetOffsetPositionEnd() const;
    const ActionType    GetOffsetType() const;
    const float         GetOffsetStepSeconds() const;
    void                SetOffsetCurrentStepSeconds( const float seconds );
    const float         GetOffsetCurrentStepSeconds() const;

    // turn related
    void                ScriptTurnToDirection( const float direction, const TurnDirection turn_direction, const ActionType turn_type, const float seconds );
    void                ScriptTurnToEntity( Entity* entity, const TurnDirection turn_direction, const float seconds );
    const int           ScriptTurnSync();
    void                SetTurn( const Ogre::Degree& direction_to, Entity* entity, const TurnDirection turn_direction, const ActionType turn_type, const float seconds );
    void                UnsetTurn();
    const Ogre::Degree  CalculateTurnAngle( const Ogre::Degree& start, const Ogre::Degree& end ) const;
    const Ogre::Degree  GetTurnDirectionStart() const;
    const Ogre::Degree  GetTurnDirectionEnd() const;
    const ActionType    GetTurnType() const;
    const float         GetTurnStepSeconds() const;
    void                SetTurnCurrentStepSeconds( const float seconds );
    const float         GetTurnCurrentStepSeconds() const;

    // animation related
    const Ogre::String& GetCurrentAnimationName() const;
    virtual void        PlayAnimation( const Ogre::String& animation, EntityAnimation state, const float start, const float end ) = 0;
    virtual void        PlayAnimationLooped( const Ogre::String& animation ) = 0;
    void                ScriptPlayAnimation( const char* name );
    void                ScriptPlayAnimationStop( const char* name );
    void                ScriptPlayAnimation( const char* name, const float start, const float end );
    void                ScriptPlayAnimationStop( const char* name, const float start, const float end );
    void                ScriptSetDefaultAnimation( const char* animation );
    const int           ScriptAnimationSync();

private:
    Entity();
    const Ogre::Degree  GetDirectionToEntity( Entity* entity ) const;

protected:
    Ogre::String            m_Name;

    Ogre::SceneNode*        m_SceneNode;
    Ogre::SceneNode*        m_ModelNode;

    // height related
    float                   m_Height;

    Ogre::SceneNode*        m_DirectionNode;
    EntityDirection*        m_Direction;

    // collision related
    Ogre::SceneNode*        m_SolidCollisionNode;
    EntityCollision*        m_SolidCollision;
    float                   m_SolidRadius;
    bool                    m_Solid;

    // talk related
    Ogre::SceneNode*        m_TalkCollisionNode;
    EntityCollision*        m_TalkCollision;
    float                   m_TalkRadius;
    bool                    m_Talkable;

    // move related
    MoveState               m_MoveState;
    float                   m_MoveSpeed;
    float                   m_MoveSpeedRun;
    Ogre::Vector3           m_MovePosition;
    Entity*                 m_MoveEntity;
    float                   m_MoveStopDistance;
    int                     m_MoveTriangleId;
    bool                    m_MoveAutoRotation;
    bool                    m_MoveAutoAnimation;
    Ogre::String            m_MoveAnimationIdle;
    Ogre::String            m_MoveAnimationWalk;
    Ogre::String            m_MoveAnimationRun;
    std::vector< ScriptId > m_MoveSync;

    // offset related
    Ogre::Vector3           m_OffsetPositionStart;
    Ogre::Vector3           m_OffsetPositionEnd;
    ActionType              m_OffsetType;
    float                   m_OffsetStepSeconds;
    float                   m_OffsetCurrentStepSeconds;
    std::vector< ScriptId > m_OffsetSync;

    // turn related
    TurnDirection           m_TurnDirection;
    Ogre::Degree            m_TurnDirectionStart;
    Ogre::Degree            m_TurnDirectionEnd;
    Entity*                 m_TurnEntity;
    ActionType              m_TurnType;
    float                   m_TurnStepSeconds;
    float                   m_TurnCurrentStepSeconds;
    std::vector< ScriptId > m_TurnSync;

    // animation
    Ogre::String            m_AnimationCurrentName;
    std::vector< ScriptId > m_AnimationSync;
    EntityAnimation         m_AnimationState;
    Ogre::String            m_AnimationDefault;
    float                   m_AnimationEndTime;
};



#endif // ENTITY_H
