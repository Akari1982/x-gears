#ifndef MATH_H
#define MATH_H

#include <OgreVector2.h>
#include <OgreVector3.h>



float PointElevation( const Ogre::Vector2& point, const Ogre::Vector3& A, const Ogre::Vector3& B, const Ogre::Vector3& C );
float SideOfVector( const Ogre::Vector2& point, const Ogre::Vector2& p1, const Ogre::Vector2& p2 );
Ogre::Degree GetDirectionToPoint( const Ogre::Vector3& current_point, const Ogre::Vector3& direction_point );
float SquareDistanceToLine( const Ogre::Vector3& p, const Ogre::Vector3& p1, const Ogre::Vector3& p2, Ogre::Vector3& proj );



#endif // MATH_H
