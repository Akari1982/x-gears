#include <gl/gl.h>

#include "animation3d.h"
#include "model3d.h"
#include "xg3d.h"
#include "../file.h"
#include "../../log.h"



Model3D::Model3D(const std::string &fileName, const std::string &aniName):
    XG3D(fileName),
    Animation3D(aniName)
{
}



Model3D::~Model3D()
{
}



void
Model3D::loadModel3D()
{
    // load 3d model itself
    loadXG3D();

    // load animation
    loadAnimation3D();
}



void
Model3D::viewModel3D(u16 level)
{
    std::vector<cell>::iterator block = hrc.begin();
    std::vector<BonePosition>::iterator bone = animation.begin();

    u16 i = 0;
    for (; block != hrc.end(); block++, i++)
    {
        if ((*block).second == level)
        {
if ((level == 0 && i == 1) || level != 0)
{
//logger->log("level %d", level);
//logger->log("T %d %d %d     I = %d", (*(bone + i)).t_x, (*(bone + i)).t_y, (*(bone + i)).t_z, i);

//logger->log("Rotate %f %f %f", (float)(((*(bone + i)).r_x) * 360) / 65536, (float)(((*(bone + i)).r_y) * 360) / 65536, (float)(((*(bone + i)).r_z) * 360) / 65536);

            glPushMatrix();

            glRotatef((float)(((*(bone + i)).r_z) * 360) / 65536, 1.0f, 0.0f, 0.0f);
            glRotatef((float)(((*(bone + i)).r_x) * 360) / 65536, 0.0f, 1.0f, 0.0f);
            glRotatef((float)(((*(bone + i)).r_y) * 360) / 65536, 0.0f, 0.0f, 1.0f);

            glTranslatef((float)((*(bone + i)).t_y), -(float)((*(bone + i)).t_x), (float)((*(bone + i)).t_y));

            if ((*block).first != 0xFFFF)
            {
//logger->log("V %d", (*block).first);
                viewXG3D((*block).first);
            }

            viewModel3D(i);
            glPopMatrix();
        }
}
    }
}
