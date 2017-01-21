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
        struct Vertex
        {
            s16 x, y, z;
        };

        struct battle_background
        {
            Vertex *vertex;
            int vertex_count;
        } *battle;
};

#endif // _XG3D_H