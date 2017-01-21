#include <string>

#include <physfs.h>

#include "file.h"
#include "../log.h"



File::File(const std::string &fileName):
    buffer(NULL),
    size(0),
    file_pointer(NULL),
    file_name(fileName)
{
}



File::~File()
{
    free(buffer);
}



void
File::loadFile()
{
    // If the file doesn't exist indicate failure
    if (!PHYSFS_exists(file_name.c_str()))
    {
        logger->log("Warning: %s not found!", file_name.c_str());
        buffer = NULL;
        return;
    }

    // Attempt to open the specified file using PhysicsFS
    file_pointer = PHYSFS_openRead(file_name.c_str());
    // If the handler is an invalid pointer indicate failure
    if (file_pointer == NULL)
    {
        logger->log("Warning: %s failed to open for read! Error: %s", file_name.c_str(), PHYSFS_getLastError());
        buffer = NULL;
        return;
    }

    // Get the size of the file
    size = PHYSFS_fileLength(file_pointer);

    // Allocate memory and load the file
    buffer = malloc(size);
    if (PHYSFS_read(file_pointer, buffer, 1, size) == -1)
    {
        logger->log("Warning: %s failed to read! Error: %s", file_name.c_str(), PHYSFS_getLastError());
        buffer = NULL;
        return;
    }

    // Close the file and let the user deallocate the memory
    if (!PHYSFS_close(file_pointer))
    {
        logger->log("Warning: %s failed to close file pointer! Error: %s", file_name.c_str(), PHYSFS_getLastError());
        buffer = NULL;
        return;
    }
}



bool
File::writeFile(int &fileSize, void** data)
{
    // open file to write
    file_pointer = PHYSFS_openWrite(file_name.c_str());
    if (file_pointer == NULL)
    {
        logger->log("Warning: %s failed to open for write! Error: %s", file_name.c_str(), PHYSFS_getLastError());
        return false;
    }

    // write "fileSize" number of bytes from "data" pointer
    if (PHYSFS_write(file_pointer, *data, fileSize, 1) == -1)
    {
        logger->log("Warning: %s failed to write! Error: %s", file_name.c_str(), PHYSFS_getLastError());
        return false;
    }

    // close file pointer
    if (!PHYSFS_close(file_pointer))
    {
        logger->log("Warning: %s failed to close file pointer! Error: %s", file_name.c_str(), PHYSFS_getLastError());
        return false;
    }

    return true;
}



const std::string
File::getFileName()
{
    return file_name;
}



unsigned short
File::get_u16le(int offset)
{
    return ((unsigned char*)buffer + offset)[0] | (((unsigned char*)buffer + offset)[1] << 8);
}



unsigned long
File::get_u32le(int offset)
{
    return ((unsigned char*)buffer + offset)[0] | (((unsigned char*)buffer + offset)[1] << 8) | (((unsigned char*)buffer + offset)[2] << 16) | (((unsigned char*)buffer + offset)[3] << 24);
}
