/*
-----------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2013-08-29 Tobias Peters <tobias.peters@kreativeffekt.at>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
-----------------------------------------------------------------------------
*/
#include "data/QGearsFLevelBackground2DLoader.h"

#include "data/QGearsFLevelFile.h"
#include "map/QGearsBackground2DFile.h"

namespace QGears
{
    //-------------------------------------------------------------------------
    FLevelBackground2DLoader::FLevelBackground2DLoader( FLevelFile &flevel_file ) :
        m_flevel_file( flevel_file )
    {
    }

    //-------------------------------------------------------------------------
    FLevelBackground2DLoader::~FLevelBackground2DLoader()
    {
    }

    //-------------------------------------------------------------------------
    void
    FLevelBackground2DLoader::loadResource( Ogre::Resource *resource )
    {
        Background2DFile *background_2d( static_cast<Background2DFile *>(resource) );
        assert( background_2d );

        m_flevel_file.load();
        background_2d->_notifyOrigin( m_flevel_file.getName() );
        background_2d->setTextureName( m_flevel_file.getBackgroundTextureName() );

        Ogre::Vector3 position( 28.4846, 210.83, 3.10751 );
        background_2d->setPosition( position );

        Ogre::Quaternion orientation( 0.742188, 0.667516, -0.0403783, -0.0450658 );
        background_2d->setOrientation( orientation );

        background_2d->setFov( Ogre::Radian( Ogre::Degree( 34.5389 ) ) );

        Ogre::Vector4 range( 0, 0, 0, 0 );

        TileList& tiles( background_2d->getTiles() );
        BackgroundFilePtr background( m_flevel_file.getBackground() );
        Layer *layers( background->getLayers() );
        Layer &layer( layers[0] );
        if( layer.enabled )
        {
            SpriteList::const_iterator it    ( layer.sprites.begin() );
            SpriteList::const_iterator it_end( layer.sprites.end() );
            Ogre::Real step( BackgroundFile::SPRITE_WIDTH / 1024.0 );
            Ogre::Vector4   uv( 0, 0, step, step );
            Ogre::Vector4   col( step, 0, step, 0 );
            Ogre::Vector4   row( 0, step, 0, step );
            while( it != it_end )
            {
                const SpriteData& sprite( *it );
                Tile tile;
                tile.width  = BackgroundFile::SPRITE_WIDTH;
                tile.height = BackgroundFile::SPRITE_HEIGHT;
                tile.blending = B_ALPHA;
                tile.depth = 999;
                tile.destination.x = sprite.dst.x;
                tile.destination.y = sprite.dst.y;
                tile.uv = uv;
                range.x = std::min( tile.destination.x, range.x );
                range.y = std::min( tile.destination.y, range.y );
                range.z = std::max( tile.destination.x + tile.width , range.z );
                range.w = std::max( tile.destination.y + tile.height, range.w );
                tiles.push_back( tile );

                uv += col;
                if( uv.x >= 1 )
                {
                    uv.x = 0;
                    uv.z = step;
                    uv += row;
                }
                ++it;
            }
        }
        background_2d->setRange( range );
    }

    //-------------------------------------------------------------------------
}
