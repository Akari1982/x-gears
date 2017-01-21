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
}



XG3D::~XG3D()
{
    free(battle->vertex);
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

    // start position of vertex
    u32 start            = 0x800;
    // number of vertex
    battle->vertex_count = 10;//0x6D3;

    battle->vertex = (Vertex *)malloc(battle->vertex_count * sizeof(Vertex));
    // add all vertex to structure
    for (int j = 0; j < battle->vertex_count; j++)
    {
        battle->vertex[j].x = -get_u16le(offset_3d + start + 0);
        battle->vertex[j].y = -get_u16le(offset_3d + start + 2);
        battle->vertex[j].z = get_u16le(offset_3d + start + 4);

        // go to the next vertex
        start += 8;
    }
}



void
XG3D::viewXG3D(u32 mesh)
{
    glPointSize(2);
    glBegin(GL_POINTS);
    for (u32 vertex_number = 0; vertex_number < battle->vertex_count; vertex_number++)
    {
        glColor3f(1.0f, 1.0f, 1.0f);
logger->log("%d, %d, %d", battle->vertex[vertex_number].x , battle->vertex[vertex_number].y, battle->vertex[vertex_number].z);
        glVertex3d(battle->vertex[vertex_number].x,
                   battle->vertex[vertex_number].y,
                   battle->vertex[vertex_number].z);
    }
    glEnd();
    glPointSize(2);
}
