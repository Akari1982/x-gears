#ifndef WALKMESHFILE_H
#define WALKMESHFILE_H



#include "Walkmesh.h"
#include "../../common/File.h"



class WalkmeshFile : public File
{
public:
    WalkmeshFile( const Ogre::String& file );
    virtual ~WalkmeshFile();

    void GetWalkmesh( Walkmesh* walkmesh );
};



#endif // WALKMESHFILE_H
