#ifndef _ENEMY2D_H
#define _ENEMY2D_H

#include "../file.h"



class Enemy2D : public File
{
    public:
        typedef unsigned char u8;
        typedef unsigned short int u16;
        typedef unsigned long int u32;

        typedef signed char s8;
        typedef signed short int s16;
        typedef signed long int s32;

        // constructor
        Enemy2D(const std::string &fileName);

        // destructor
        virtual
        ~Enemy2D();

        void
        loadEnemy2D();

        void
        viewEnemy2D();

    public:
        // structure where we save color
        struct Color
        {
            u8 r, g, b, a;
        };

        struct FrameRow
        {
            Color *cell;
        };

        struct Frame
        {
            u8 height;
            u8 width;
            FrameRow *row;
        };

        struct Animation
        {
            Frame* frame;
            u8     number_of_frames;
        } *animation;
};

#endif