#ifndef _XG3D_H
#define _XG3D_H

#include <gl/gl.h>

#include <algorithm>
#include <string>
#include <vector>

#include "../file.h"



class XG3D : public File
{
    public:
        // constructor
        XG3D(const std::string &fileName);

        // destructor
        virtual
        ~XG3D();

        // and write it to battle
        void
        loadXG3D();

        void
        viewXG3D(u32 mesh = 0xFFFFFFFF);

    private:
        struct meshBlockHeader
        {
            u16 unknown1;
            u16 number_of_vertex;
            u16 number_of_mesh;
            u16 number_of_mesh_block;
            u32 offset_to_vertex_block;
            u32 offset_to_normal_block;
            u32 offset_to_mesh_block;
            u32 offset_to_texture_coords;
            u32 unknown2;
            u32 unknown3;
            u32 unknown4;
            u32 unknown5;
            u32 unknown6;
            u32 unknown7;
            u32 unknown8;
            u32 unknown9;
        };

        struct commandPacket
        {
            u8 :1;
            u8 :1;
            u8 :1;
            u8 vertex:1;
        };



        // structure where we save color
        struct Color
        {
            u8 r, g, b, a;
        };

        struct Vertex
        {
            s16 x, y, z;
        };

        struct Triangle
        {
            u16 a;
            u8 ax, ay;
            u16 b;
            u8 bx, by;
            u16 c;
            u8 cx, cy;
            u8 texture_index;
            bool monochrome;
            Color color;
        };

        struct Quad
        {
            u16 a;
            u8 ax, ay;
            u16 b;
            u8 bx, by;
            u16 d;
            u8 dx, dy;
            u16 c;
            u8 cx, cy;
            u8 texture_index;
            bool monochrome;
            Color color;
        };

        struct Block
        {
            Vertex *vertex;
            int triangle_count;
            Triangle *triangle;
            int quad_count;
            Quad *quad;
        };

        struct battle_background
        {
            u32 block_count;
            Block *block;
        } *battle;

        u16 *index_buffer;
};

#endif // _XG3D_H