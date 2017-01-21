#ifndef _ANIMATION3D_H
#define _ANIMATION3D_H

#include <gl/gl.h>

#include <vector>

#include "../file.h"



class Animation3D : public File
{
    public:
        // constructor
        Animation3D(const std::string &fileName);

        // destructor
        virtual
        ~Animation3D();

        void
        loadAnimation3D();



    protected:
        struct BonePosition
        {
            u16 r_x;
            u16 r_y;
            u16 r_z;
            s16 t_x;
            s16 t_y;
            s16 t_z;
        };

        std::vector<BonePosition> animation;
};

#endif // _ANIMATION3D_H