#include <algorithm>
#include <string>
#include <vector>

#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

#include <gl/gl.h>
#include <gl/glu.h>

#include "xg3d.h"
#include "../file.h"
#include "../../log.h"

//#define DUMP_3D_BLOCK_HEADERS
//#define DUMP_MESH_BLOCK_HEADERS
//#define DUMP_PACKET_HEADERS
//#define DUMP_PACKET



XG3D::XG3D(const std::string &fileName):
    File(fileName)
{
    loadFile();

    if (buffer == NULL)
    {
        logger->log("Warning: can't open archive file %s", file_name.c_str());
    }

    battle = (battle_background*)malloc(sizeof(battle_background));
    battle->block_count = 0;
    battle->block       = NULL;
}



XG3D::~XG3D()
{
    for (u32 i = 0; i < battle->block_count; i++)
    {
        free(battle->block[i].vertex);
        free(battle->block[i].triangle);
        free(battle->block[i].quad);
    }
    free(battle->block);
    free(battle);
}



void
XG3D::loadXG3D()
{
    /////////////////////////////////////////////
    // first block - 3D MESH
    /////////////////////////////////////////////
    // 3d mesh block offset
    u32 offset_3d = get_u32le(0x08);

    // numbers of subblock
    battle->block_count = get_u32le(offset_3d);
    battle->block = (Block*)malloc(battle->block_count * sizeof(Block));

    for (u32 i = 0; i < battle->block_count; i++)
    {
        battle->block[i].vertex         = NULL;
        battle->block[i].triangle_count = 0;
        battle->block[i].triangle       = NULL;
        battle->block[i].quad_count     = 0;
        battle->block[i].quad           = NULL;

        meshBlockHeader* mesh_block_header = (meshBlockHeader*)((u8*)buffer + offset_3d + 0x10 + i * 0x38);

#ifdef DUMP_3D_BLOCK_HEADERS
        logger->log("unknown1:                 0x%04x", mesh_block_header->unknown1);
        logger->log("number_of_vertex:         %d",     mesh_block_header->number_of_vertex);
        logger->log("number_of_mesh:           %d",     mesh_block_header->number_of_mesh);
        logger->log("number_of_mesh_block:     %d",     mesh_block_header->number_of_mesh_block);
        logger->log("offset_to_vertex_block:   0x%08x", mesh_block_header->offset_to_vertex_block);
        logger->log("offset_to_normal_block:   0x%08x", mesh_block_header->offset_to_normal_block);
        logger->log("offset_to_mesh_block:     0x%08x", mesh_block_header->offset_to_mesh_block);
        logger->log("offset_to_texture_coords: 0x%08x", mesh_block_header->offset_to_texture_coords);
        logger->log("Unknown row: %08x %08x %08x %08x %08x %08x %08x %04x", mesh_block_header->unknown2, mesh_block_header->unknown3, mesh_block_header->unknown4, mesh_block_header->unknown5, mesh_block_header->unknown6, mesh_block_header->unknown7, mesh_block_header->unknown8, mesh_block_header->unknown9);
#endif

        // start position of vertex
        u32 start            = mesh_block_header->offset_to_vertex_block;
        // number of vertex
        u16 number_of_vertex = mesh_block_header->number_of_vertex;

        battle->block[i].vertex = (Vertex *)realloc(battle->block[i].vertex, number_of_vertex * sizeof(Vertex));
        // add all vertex to structure
        for (int j = 0; j < number_of_vertex; j++)
        {
            battle->block[i].vertex[j].x = -get_u16le(offset_3d + start + 0);
            battle->block[i].vertex[j].y = -get_u16le(offset_3d + start + 2);
            battle->block[i].vertex[j].z = get_u16le(offset_3d + start + 4);

            // go to the next vertex
            start += 8;
        }



        // start position of first mesh block
        start                    = mesh_block_header->offset_to_mesh_block;
        // number of mesh block
        u16 number_of_mesh_block = mesh_block_header->number_of_mesh_block;
        // start position of texture coords block
        u32 start_tex = get_u32le(offset_3d + 0x10 + i * 0x38 + 0x14);

        // current texture index
        u8 tex_index = 0;
        // if monochrome polygon
        bool monochrome = false;
        // color for monochrome polygon
        Color color;

        for (int k = 0; k < number_of_mesh_block; k++)
        {
            commandPacket* command_packet = (commandPacket*)((u8*)buffer + offset_3d + start + 0x00);

#ifdef DUMP_MESH_BLOCK_HEADERS
            logger->log("Command packet & 77 - %02x%02x", *((u8*)buffer + offset_3d + start + 0x00), *((u8*)buffer + offset_3d + start + 0x01));
#endif

            // number of mesh
            u16 number_of_mesh = get_u16le(offset_3d + start + 0x02);
            start += 0x04;

            for (int j = 0; j < number_of_mesh; j++)
            {
                // if monochrome quad or triangle
                if (*((u8*)buffer + offset_3d + start_tex + 0x03) == 0x20 ||
                    *((u8*)buffer + offset_3d + start_tex + 0x03) == 0x22 ||
                    *((u8*)buffer + offset_3d + start_tex + 0x03) == 0x28)
                {
#ifdef DUMP_PACKET_HEADERS
                logger->log("0x%02x", *((u8*)buffer + offset_3d + start_tex + 0x03));
#endif
#ifdef DUMP_PACKET
                logger->log("0x%02x", get_u32le(offset_3d + start_tex));
#endif
                    monochrome = true;
                    color.b = *((u8*)buffer + offset_3d + start_tex + 0x02);
                    color.g = *((u8*)buffer + offset_3d + start_tex + 0x01);
                    color.r = *((u8*)buffer + offset_3d + start_tex + 0x00);

                    start_tex += 4;
                }

                // if texture page settings
                if (*((u8*)buffer + offset_3d + start_tex + 0x03) == 0xC4)
                {
#ifdef DUMP_PACKET_HEADERS
                logger->log("0x%02x", *((u8*)buffer + offset_3d + start_tex + 0x03));
#endif
#ifdef DUMP_PACKET
                logger->log("0x%02x", get_u32le(offset_3d + start_tex));
#endif

                    start_tex += 4;
                }
                // if CLUT settings
                if (*((u8*)buffer + offset_3d + start_tex + 0x03) == 0xC8)
                {
#ifdef DUMP_PACKET_HEADERS
                logger->log("0x%02x", *((u8*)buffer + offset_3d + start_tex + 0x03));
#endif
#ifdef DUMP_PACKET
                logger->log("0x%02x", get_u32le(offset_3d + start_tex));
#endif
                    start_tex += 4;
                }

#ifdef DUMP_PACKET_HEADERS
                logger->log("0x%02x", *((u8*)buffer + offset_3d + start_tex + 0x03));
#endif
#ifdef DUMP_PACKET
                logger->log("0x%02x", get_u32le(offset_3d + start_tex));
#endif

                // if command packet vertex data == 1 then this is quad
                if (command_packet->vertex == 1)
                {
                    int id = battle->block[i].quad_count++;
                    battle->block[i].quad = (Quad *)realloc(battle->block[i].quad, battle->block[i].quad_count * sizeof(Quad));

                    if (monochrome == true)
                    {
                        battle->block[i].quad[id].monochrome    = monochrome;
                        battle->block[i].quad[id].color         = color;
                        monochrome = false;
                    }
                    else
                    {
                        battle->block[i].quad[id].monochrome    = monochrome;
                        battle->block[i].quad[id].texture_index = tex_index;

                        battle->block[i].quad[id].ax = *((u8*)buffer + offset_3d + start_tex + 0x04);
                        battle->block[i].quad[id].ay = *((u8*)buffer + offset_3d + start_tex + 0x05);
                        battle->block[i].quad[id].bx = *((u8*)buffer + offset_3d + start_tex + 0x06);
                        battle->block[i].quad[id].by = *((u8*)buffer + offset_3d + start_tex + 0x07);
                        battle->block[i].quad[id].cx = *((u8*)buffer + offset_3d + start_tex + 0x08);
                        battle->block[i].quad[id].cy = *((u8*)buffer + offset_3d + start_tex + 0x09);
                        battle->block[i].quad[id].dx = *((u8*)buffer + offset_3d + start_tex + 0x0A);
                        battle->block[i].quad[id].dy = *((u8*)buffer + offset_3d + start_tex + 0x0B);

                        start_tex += 0x0C;
                    }

                    battle->block[i].quad[id].a = get_u16le(offset_3d + start + 0x00);
                    battle->block[i].quad[id].b = get_u16le(offset_3d + start + 0x02);
                    battle->block[i].quad[id].c = get_u16le(offset_3d + start + 0x04);
                    battle->block[i].quad[id].d = get_u16le(offset_3d + start + 0x06);
                }
                else
                {
                    int id = battle->block[i].triangle_count++;
                    battle->block[i].triangle = (Triangle *)realloc(battle->block[i].triangle, battle->block[i].triangle_count * sizeof(Triangle));

                    if (monochrome == true)
                    {
                        battle->block[i].triangle[id].monochrome    = monochrome;
                        battle->block[i].triangle[id].color         = color;
                        monochrome = false;
                    }
                    else
                    {
                        battle->block[i].triangle[id].monochrome    = monochrome;
                        battle->block[i].triangle[id].texture_index = tex_index;

                        battle->block[i].triangle[id].cx = *((u8*)buffer + offset_3d + start_tex + 0x00);
                        battle->block[i].triangle[id].cy = *((u8*)buffer + offset_3d + start_tex + 0x01);
                        battle->block[i].triangle[id].ax = *((u8*)buffer + offset_3d + start_tex + 0x04);
                        battle->block[i].triangle[id].ay = *((u8*)buffer + offset_3d + start_tex + 0x05);
                        battle->block[i].triangle[id].bx = *((u8*)buffer + offset_3d + start_tex + 0x06);
                        battle->block[i].triangle[id].by = *((u8*)buffer + offset_3d + start_tex + 0x07);

                        start_tex += 0x08;
                    }

                    battle->block[i].triangle[id].a = get_u16le(offset_3d + start + 0);
                    battle->block[i].triangle[id].b = get_u16le(offset_3d + start + 2);
                    battle->block[i].triangle[id].c = get_u16le(offset_3d + start + 4);
                }

                // go to the next mesh
                start += 0x08;
            }
        }
    }
}



void
XG3D::viewXG3D(u32 mesh)
{
    u32 block_number = mesh;

        for (u32 triangle_number = 0; triangle_number < battle->block[block_number].triangle_count; triangle_number++)
        {
            glBegin(GL_TRIANGLES);
                glVertex3d(battle->block[block_number].vertex[battle->block[block_number].triangle[triangle_number].a].x,
                           battle->block[block_number].vertex[battle->block[block_number].triangle[triangle_number].a].y,
                           battle->block[block_number].vertex[battle->block[block_number].triangle[triangle_number].a].z);
                glVertex3d(battle->block[block_number].vertex[battle->block[block_number].triangle[triangle_number].b].x,
                           battle->block[block_number].vertex[battle->block[block_number].triangle[triangle_number].b].y,
                           battle->block[block_number].vertex[battle->block[block_number].triangle[triangle_number].b].z);
                glVertex3d(battle->block[block_number].vertex[battle->block[block_number].triangle[triangle_number].c].x,
                           battle->block[block_number].vertex[battle->block[block_number].triangle[triangle_number].c].y,
                           battle->block[block_number].vertex[battle->block[block_number].triangle[triangle_number].c].z);
            glEnd();
        }

        for (u32 quad_number = 0; quad_number < battle->block[block_number].quad_count; quad_number++)
        {
            glBegin(GL_QUADS);
                glVertex3d(battle->block[block_number].vertex[battle->block[block_number].quad[quad_number].a].x,
                           battle->block[block_number].vertex[battle->block[block_number].quad[quad_number].a].y,
                           battle->block[block_number].vertex[battle->block[block_number].quad[quad_number].a].z);
                glVertex3d(battle->block[block_number].vertex[battle->block[block_number].quad[quad_number].b].x,
                           battle->block[block_number].vertex[battle->block[block_number].quad[quad_number].b].y,
                           battle->block[block_number].vertex[battle->block[block_number].quad[quad_number].b].z);
                glVertex3d(battle->block[block_number].vertex[battle->block[block_number].quad[quad_number].d].x,
                           battle->block[block_number].vertex[battle->block[block_number].quad[quad_number].d].y,
                           battle->block[block_number].vertex[battle->block[block_number].quad[quad_number].d].z);
                glVertex3d(battle->block[block_number].vertex[battle->block[block_number].quad[quad_number].c].x,
                           battle->block[block_number].vertex[battle->block[block_number].quad[quad_number].c].y,
                           battle->block[block_number].vertex[battle->block[block_number].quad[quad_number].c].z);
            glEnd();
        }
}
