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

    void GetU8Variable( u32& script_pointer, const Ogre::String& name );
    void GetS16Variable( u32& script_pointer, const Ogre::String& name );
    void GetU16Variable( u32& script_pointer, const Ogre::String& name );

    void GetVF40Variable( u32& script_pointer, const Ogre::String& name );
    void GetVF80Variable( u32& script_pointer, const Ogre::String& name );
    void GetVVariable( u32& script_pointer, const Ogre::String& name );
    void GetV80Variable( u32& script_pointer, const Ogre::String& name );
};



#endif // ScriptFILE_H
