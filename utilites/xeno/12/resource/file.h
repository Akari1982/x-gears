#ifndef FILE_H
#define FILE_H

#include <string>
#include <physfs.h>



class File
{
    public:
        typedef unsigned char u8;
        typedef unsigned short int u16;
        typedef unsigned long int u32;

        typedef signed char s8;
        typedef signed short int s16;
        typedef signed long int s32;

        // constructor
        File(const std::string &fileName);

        // destructor
        virtual ~File();

        // load file "fileName"
        // fill "fileSize" with size of readed data
        void
        loadFile();

        // write into file "fileName" "fileSize" number of bytes from pointer data
        bool
        writeFile(int &fileSize, void** data);

        // return "file_name"
        const std::string
        getFileName();

        // utility functions returns value with given offset
        unsigned short int
        get_u16le(int offset);
        unsigned long int
        get_u32le(int offset);

    public:
        // loaded file buffer
        void *buffer;
        // size of buffer
        int size;

    protected:
        // pointer to readed or written file
        PHYSFS_file *file_pointer;
        // filename
        const std::string file_name;
};



#endif // FILE_H
