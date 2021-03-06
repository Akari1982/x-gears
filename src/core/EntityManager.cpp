#include "EntityManager.h"
#include "EntityManagerCommands.h"

#include <OgreEntity.h>
#include <OgreRoot.h>

#include "CameraManager.h"
#include "ConfigVar.h"
#include "DebugDraw.h"
#include "InputManager.h"
#include "Logger.h"
#include "Math.h"
#include "ScriptManager.h"
#include "Timer.h"



template<>EntityManager *Ogre::Singleton< EntityManager >::msSingleton = NULL;



ConfigVar cv_debug_grid( "debug_grid", "Draw debug grid", "false" );
ConfigVar cv_debug_axis( "debug_axis", "Draw debug axis", "false" );
ConfigVar cv_debug_walkmesh( "debug_walkmesh", "Draw walkmesh and walkmesh debug info", "0" );



float
SideOfVector( const Ogre::Vector2& point, const Ogre::Vector2& p1, const Ogre::Vector2& p2 )
{
    Ogre::Vector2 AB = p2 - p1;
    Ogre::Vector2 AP = point - p1;
    return AB.x * AP.y - AB.y * AP.x;
}

float
PointElevation( const Ogre::Vector2& point, const Ogre::Vector3& A, const Ogre::Vector3& B, const Ogre::Vector3& C )
{
    float _A = A.y * ( B.z - C.z ) + B.y * ( C.z - A.z ) + C.y * ( A.z - B.z );
    float _B = A.z * ( B.x - C.x ) + B.z * ( C.x - A.x ) + C.z * ( A.x - B.x );
    float _C = A.x * ( B.y - C.y ) + B.x * ( C.y - A.y ) + C.x * ( A.y - B.y );
    float _D = A.x * ( B.y * C.z - C.y * B.z ) + B.x * ( C.y * A.z - A.y * C.z ) + C.x * ( A.y * B.z - B.y * A.z );

    return ( _D - _C * point.y - _A * point.x ) / _B;
}



EntityManager::EntityManager():
    m_MoveMask( 0x00 ),
    m_Sprite( NULL )
{
    InitCmd();

    LOG_TRIVIAL( "EntityManager created." );

    m_SceneNode = Ogre::Root::getSingleton().getSceneManager( "Scene" )->getRootSceneNode()->createChildSceneNode( "EntityManager" );

    m_Grid = Ogre::Root::getSingleton().getSceneManager( "Scene" )->createEntity( "Grid", "system/grid.mesh" );
    m_SceneNode->attachObject( m_Grid );
    m_Axis = Ogre::Root::getSingleton().getSceneManager( "Scene" )->createEntity( "Axis", "system/axis.mesh" );
    m_SceneNode->attachObject( m_Axis );



    m_SceneNode->createChildSceneNode( "Sprite" );
}



EntityManager::~EntityManager()
{
    if( m_Sprite != NULL )
    {
        delete m_Sprite;
    }



    if( m_Grid != NULL )
    {
        Ogre::Root::getSingleton().getSceneManager( "Scene" )->destroyEntity( m_Grid );
    }
    if( m_Axis != NULL )
    {
        Ogre::Root::getSingleton().getSceneManager( "Scene" )->destroyEntity( m_Axis );
    }

    Clear();

    Ogre::Root::getSingleton().getSceneManager( "Scene" )->getRootSceneNode()->removeAndDestroyChild( "EntityManager" );

    LOG_TRIVIAL( "EntityManager destroyed." );
}



void
EntityManager::Input( const Event& event )
{
    if( event.type == ET_REPEAT )
    {
        if( event.event == "walk_left" )
        {
            m_MoveMask |= 0x08;
        }
        else if( event.event == "walk_right" )
        {
            m_MoveMask |= 0x02;
        }
        else if( event.event == "walk_down" )
        {
            m_MoveMask |= 0x04;
        }
        else if( event.event == "walk_up" )
        {
            m_MoveMask |= 0x01;
        }
    }
}



bool
EntityManager::InputToRotation( Ogre::Degree& rotation )
{
    switch( m_MoveMask )
    {
        case 0x00: return false;
        case 0x01: rotation = Ogre::Degree( 0 ); return true;
        case 0x02: rotation = Ogre::Degree( 90 ); return true;
        case 0x03: rotation = Ogre::Degree( 45 ); return true;
        case 0x04: rotation = Ogre::Degree( 180 ); return true;
        case 0x05: rotation = Ogre::Degree( 0 ); return false;
        case 0x06: rotation = Ogre::Degree( 135 ); return true;
        case 0x07: rotation = Ogre::Degree( 90 ); return true;
        case 0x08: rotation = Ogre::Degree( 270 ); return true;
        case 0x09: rotation = Ogre::Degree( 315 ); return true;
        case 0x0a: rotation = Ogre::Degree( 0 ); return false;
        case 0x0b: rotation = Ogre::Degree( 0 ); return true;
        case 0x0c: rotation = Ogre::Degree( 225 ); return true;
        case 0x0d: rotation = Ogre::Degree( 270 ); return true;
        case 0x0e: rotation = Ogre::Degree( 180 ); return true;
        case 0x0f: rotation = Ogre::Degree( 0 ); return false;
    }
    return false;
}



void
EntityManager::Update()
{
    if( m_Sprite != NULL )
    {
        m_Sprite->Update();
    }



    // update all entity scripts
    ScriptManager::getSingleton().Update( ScriptManager::ENTITY );



    UpdateMove();



    UpdateDebug();



    // reset currently active move events
    m_MoveMask = 0x00;
}



void
EntityManager::UpdateMove()
{
    // check auto movement
    for( size_t i = 0; i < m_Entity.size(); ++i )
    {
        if( m_Entity[ i ]->IsMove() == true )
        {
            EntityCalculateMove( m_Entity[ i ] );
        }
    }



    // check player move



    // perform move
}



void
EntityManager::UpdateDebug()
{
    m_Grid->setVisible( cv_debug_grid.GetB() );
    m_Axis->setVisible( cv_debug_axis.GetB() );

    for( size_t i = 0; i < m_Entity.size(); ++i )
    {
        m_Entity[ i ]->UpdateDebug();
    }

    for( size_t i = 0; i < m_Trigger.size(); ++i )
    {
        m_Trigger[ i ]->UpdateDebug();
    }

    int debug_w = cv_debug_walkmesh.GetI();
    for( size_t i = 0; i < m_Walkmesh.size(); ++i )
    {
        if( ( debug_w >> i ) & 1 )
        {
            m_Walkmesh[ i ]->UpdateDebug();
        }
    }

    for( size_t i = 0; i < m_SpawnPoint.size(); ++i )
    {
        m_SpawnPoint[ i ]->UpdateDebug();
    }
}



void
EntityManager::OnResize()
{
}



void
EntityManager::Clear()
{
    for( size_t i = 0; i < m_Walkmesh.size(); ++i )
    {
        delete m_Walkmesh[ i ];
    }
    m_Walkmesh.clear();

    for( size_t i = 0; i < m_SpawnPoint.size(); ++i )
    {
        delete m_SpawnPoint[ i ];
    }
    m_SpawnPoint.clear();

    for( unsigned int i = 0; i < m_Entity.size(); ++i )
    {
        delete m_Entity[ i ];
    }
    m_Entity.clear();


    for( unsigned int i = 0; i < m_Trigger.size(); ++i )
    {
        delete m_Trigger[ i ];
    }
    m_Trigger.clear();

    m_SceneNode->removeAndDestroyAllChildren();
}



void
EntityManager::AddWalkmesh( Walkmesh* walkmesh )
{
    m_Walkmesh.push_back( walkmesh );
}



void
EntityManager::AddSpawnPoint( SpawnPoint* spawn_point )
{
    m_SpawnPoint.push_back( spawn_point );
}



void
EntityManager::AddEntity( const Ogre::String& name, const Ogre::String& file_name, const Ogre::Vector3& position, const Ogre::Degree& rotation, const bool script )
{
    Ogre::SceneNode* node = m_SceneNode->createChildSceneNode( "Model_" + name );
    Entity* entity = new Entity( name, node );

    if( file_name != "" )
    {
        entity->SetModel( file_name );
    }

    if( script == true )
    {
        ScriptManager::getSingleton().AddEntity( ScriptManager::ENTITY, name, entity );
    }

    entity->SetPosition( position );
    entity->SetRotation( rotation );
    m_Entity.push_back( entity );
}



void
EntityManager::AddSprite( const Ogre::String& name )
{
    if( m_Sprite != NULL )
    {
        delete m_Sprite;
    }

    m_Sprite = new Sprite( name, ( Ogre::SceneNode* )m_SceneNode->getChild( "Sprite" ) );
}



void
EntityManager::AddSquareTrigger( const Ogre::String& name, const Ogre::Vector3& point1, const Ogre::Vector3& point2, const Ogre::Vector3& point3, const Ogre::Vector3& point4, const bool enabled )
{
    Trigger* trigger = new Trigger( name );
    trigger->SetSquareTrigger( point1, point2, point3, point4 );
    m_Trigger.push_back( trigger );
}



void
EntityManager::EntityToSpawnPoint( Entity* entity, const Ogre::String& point_name )
{
    for( size_t i = 0; i < m_SpawnPoint.size(); ++i )
    {
        if( m_SpawnPoint[ i ]->GetName() == point_name )
        {
            entity->SetWalkmeshId( m_SpawnPoint[ i ]->GetWalkmeshId() );
            EntityToWalkmeshByXZ( entity, m_SpawnPoint[ i ]->GetPosition() );
            break;
        }
    }
}



void
EntityManager::EntityToWalkmeshByXZ( Entity* entity, const Ogre::Vector2& position )
{
    int walkmesh_id = entity->GetWalkmeshId();
    if( ( walkmesh_id == -1 ) || ( walkmesh_id >= ( int )m_Walkmesh.size() ) )
    {
        LOG_ERROR( "Wrong walkmesh id to place entity \"" + entity->GetName() + "\" on walkmesh." );
        return;
    }

    // we search for posible triangles
    for( unsigned int i = 0; i < m_Walkmesh[ walkmesh_id ]->GetNumberOfTriangles(); ++i )
    {
        Ogre::Vector3 A3 = m_Walkmesh[ walkmesh_id ]->GetA( i );
        Ogre::Vector3 B3 = m_Walkmesh[ walkmesh_id ]->GetB( i );
        Ogre::Vector3 C3 = m_Walkmesh[ walkmesh_id ]->GetC( i );

        Ogre::Vector2 A2( A3.x, A3.z );
        Ogre::Vector2 B2( B3.x, B3.z );
        Ogre::Vector2 C2( C3.x, C3.z );

        if( Ogre::Math::pointInTri2D( position, A2, B2, C2 ) == true )
        {
            entity->SetPosition( Ogre::Vector3( position.x, PointElevation( position, A3, B3, C3 ), position.y ) );
            entity->SetTriangleId( i );
            return;
        }
    }

    LOG_ERROR( "Can't find any triangle to place entity \"" + entity->GetName() + "\" on walkmesh." );
}



void
EntityManager::EntityCalculateMove( Entity* entity )
{
    Ogre::Vector3 move_vector = Ogre::Vector3( 0, 0, -1 );

    Ogre::Quaternion q;
    q.FromAngleAxis( Ogre::Radian( entity->GetRotation() ), Ogre::Vector3::UNIT_Y );
    move_vector = q * move_vector;

    if( ( entity->GetWalkmeshId() != -1 ) && ( entity->GetTriangleId() != -1 ) )
    {
        Ogre::Vector3 final_point;

        // check first rotation
        Ogre::Vector3 add_vector = Ogre::Vector3( 0, 0, -1 );
        Ogre::Vector3 check_vector = move_vector;
        q.FromAngleAxis( Ogre::Radian( entity->GetRotation() + Ogre::Degree( 22.5f ) ), Ogre::Vector3::UNIT_Y );
        add_vector = q * add_vector;
        check_vector += add_vector;
        bool check = EntityWalkmeshCheck( entity, check_vector / 50.0f, final_point );

        if( check == true )
        {
            // check second rotation
            add_vector = Ogre::Vector3( 0, 0, -1 );
            check_vector = move_vector;
            q.FromAngleAxis( Ogre::Radian( entity->GetRotation() - Ogre::Degree( 22.5f ) ), Ogre::Vector3::UNIT_Y );
            add_vector = q * add_vector;
            check_vector += add_vector;
            check = EntityWalkmeshCheck( entity, check_vector / 50.0f, final_point );

            if( check == true )
            {
                // check straight
                add_vector = Ogre::Vector3( 0, 0, -1 );
                check_vector = move_vector;
                q.FromAngleAxis( Ogre::Radian( entity->GetRotation() ), Ogre::Vector3::UNIT_Y );
                add_vector = q * add_vector;
                check_vector += add_vector;
                check = EntityWalkmeshCheck( entity, check_vector / 50.0f, final_point );

                if( check == true )
                {
                    entity->SetPosition( entity->GetPosition() + move_vector / 50.0f );
                }
            }
        }
    }
}



bool
EntityManager::EntityWalkmeshCheck( Entity* entity, const Ogre::Vector3& move_vector, Ogre::Vector3& final_point )
{
    int triangle_id = entity->GetTriangleId();
    int walkmesh_id = entity->GetWalkmeshId();
    if( ( walkmesh_id == -1 ) || ( triangle_id == -1 ) )
    {
        return false;
    }

    Walkmesh* walkmesh = m_Walkmesh[ walkmesh_id ];

    Ogre::Vector3 position = entity->GetPosition();
    Ogre::Vector2 start = Ogre::Vector2( position.x, position.z );
    Ogre::Vector2 end = Ogre::Vector2( position.x + move_vector.x, position.z + move_vector.z );
    final_point.x = end.x;
    final_point.z = end.y;

    int i = 0;
    int i_max = 32;
    int check = 0;
    for( ; i < i_max; ++i )
    {
        Ogre::Vector3 A3 = walkmesh->GetA( triangle_id );
        Ogre::Vector3 B3 = walkmesh->GetB( triangle_id );
        Ogre::Vector3 C3 = walkmesh->GetC( triangle_id );
        Ogre::Vector2 A( A3.x, A3.z );
        Ogre::Vector2 B( B3.x, B3.z );
        Ogre::Vector2 C( C3.x, C3.z );

        check = 0;

        if( SideOfVector( end, B, A ) < 0 )
        {
            check |= 1;
        }
        if( SideOfVector( end, C, B ) < 0 )
        {
            check |= 2;
        }
        if( SideOfVector( end, A, C ) < 0 )
        {
            check |= 4;
        }

        switch( check )
        {
            case 0:
            {
                final_point.y = PointElevation( end, A3, B3, C3 );
                return true;
            }
            break;

            case 1:
            {
                triangle_id = walkmesh->GetAccessSide( triangle_id, 0 );
            }
            break;

            case 2:
            case 3:
            {
                triangle_id = walkmesh->GetAccessSide( triangle_id, 1 );
            }
            break;

            case 4:
            case 5:
            case 6:
            {
                triangle_id = walkmesh->GetAccessSide( triangle_id, 2 );
            }
            break;

            case 7:
            {
                triangle_id = -1;
            }
            break;
        }

        if( triangle_id == -1 )
        {
            break;
        }
    }

    return false;
}
