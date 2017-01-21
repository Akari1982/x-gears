#ifndef _MODEL3D_H
#define _MODEL3D_H

#include "animation3d.h"
#include "xg3d.h"



class Model3D: public Animation3D, public XG3D
{
    public:
        // constructor
        Model3D(const std::string &fileName, const std::string &aniName);

        // destructor
        virtual
        ~Model3D();

        void
        loadModel3D();

        void
        viewModel3D(u16 level = 0xFFFF);
};



#endif // _MODEL3D_H