#ifndef ScriptFILE_H
#define ScriptFILE_H

#include "../../common/File.h"



class ScriptFile : public File
{
public:
    ScriptFile( File* pFile );
    virtual ~ScriptFile();

    void GetScripts();
    void GetEVariable( u32& script_pointer );
    void GetFVariable( u32& script_pointer );

    Ogre::String GetU8Variable( const u32 script_pointer );
    Ogre::String GetS16Variable( const u32 script_pointer );
    Ogre::String GetU16Variable( const u32 script_pointer );

    void GetVF40Variable( u32& script_pointer, const Ogre::String& name );
    void GetVF80Variable( u32& script_pointer, const Ogre::String& name );
    Ogre::String GetVVariable( const u32 script_pointer );
    Ogre::String GetV80Variable( const u32 script_pointer );
};



#endif // ScriptFILE_H
