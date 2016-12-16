#ifndef TextFILE_H
#define TextFILE_H

#include "../../common/File.h"



class TextFile : public File
{
public:
    TextFile( File* pFile );
    virtual ~TextFile();

    void GetTexts( const int file_id );
};



#endif // TextFILE_H
