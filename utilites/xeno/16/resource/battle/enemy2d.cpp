#include <string>

#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

#include "enemy2d.h"
#include "../file.h"
#include "../../log.h"



Enemy2D::Enemy2D(const std::string &fileName):
    File(fileName)
{
    loadFile();

    if (buffer == NULL)
    {
        logger->log("Warning: can't open archive file %s", file_name.c_str());
    }
    // <comment>
    logger->log(file_name.c_str());
    // </comment>
}



Enemy2D::~Enemy2D()
{
}



void
Enemy2D::loadEnemy2D()
{
    animation = NULL;

    // initialize variable
    struct ClutRow
    {
        Color *cell;
    };
    struct Clut
    {
        u16 height;
        ClutRow *row;
    } *clut = NULL;
    clut = (Clut *)malloc(sizeof(Clut));
    clut->height = 0;
    clut->row    = NULL;

    struct TempTileRow
    {
        u8 *cell;
    };
    struct TempTile
    {
        u16 height;
        u16 width;
        TempTileRow *row;
    } *temp_tile = NULL;



    // number of blocks
    u32 number_of_blocks = get_u32le(0x00);

    for (u32 block_number = 0; block_number < number_of_blocks; block_number++)
    {
        // palette
        u32 block_offset   = get_u32le(0x08 + block_number * 0x0C);
        u32 palette_offset = get_u32le(block_offset + 0x0C);
        u32 start = block_offset + palette_offset;

        clut->height = get_u16le(start) * (get_u16le(start + 0x02) + 1);
        clut->row = (ClutRow *)realloc(clut->row, sizeof(ClutRow) * clut->height);
        // initialize new rows
        for (u16 row = 0; row < clut->height; row++)
        {
            clut->row[row].cell = (Color *)malloc(sizeof(Color) * 16);
        }

        for (int y = 0; y < clut->height; y++)
        {
            for (int x = 0; x < 16; x++)
            {
                u16 src1 = get_u16le(start + 0x04 + x * 0x02 + y * 16 * 0x02);

                clut->row[y].cell[x].r = ((src1      ) & 31) * 255 / 31;
                clut->row[y].cell[x].g = ((src1 >>  5) & 31) * 255 / 31;
                clut->row[y].cell[x].b = ((src1 >> 10) & 31) * 255 / 31;
                clut->row[y].cell[x].a = ((src1 & 0x8000) || (src1 == 0)) ? 0 : 255;
            }
        }

#if 0
        BITMAPFILEHEADER bfh;
        BITMAPINFOHEADER bih;
        DWORD RW;
        BYTE Palette [1024];
        memset(Palette, 0, 1024);

        // Заполним их
        memset (&bfh, 0, sizeof(bfh));
        bfh.bfType = 0x4D42;
        bfh.bfOffBits = sizeof(bfh) + sizeof(bih) + 1024;
        bfh.bfSize = bfh.bfOffBits + 3 * 256 * clut->height + clut->height * (16 % 4);

        memset (&bih, 0, sizeof(bih));
        bih.biSize = sizeof(bih);
        bih.biBitCount = 24;
        bih.biCompression = BI_RGB;
        bih.biHeight = clut->height;
        bih.biWidth  = 16;
        bih.biPlanes = 1;

        TCHAR name[99];
        wsprintf(name, "%s_b%d_palette.bmp", file_name.c_str(), block_number);
        HANDLE hFile = CreateFile(name, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, 0, NULL);

        WriteFile (hFile, &bfh, sizeof (bfh), &RW, NULL);
        WriteFile (hFile, &bih, sizeof (bih), &RW, NULL);
        WriteFile (hFile, Palette, 1024, &RW, NULL);

        Color *temp = new Color;
        for (y = clut->height - 1; y >= 0; y--)
        {
            for (int x = 0; x < 16; x++)
            {
                temp->b = clut->row[y].cell[x].r;
                temp->g = clut->row[y].cell[x].g;
                temp->r = clut->row[y].cell[x].b;
                WriteFile(hFile, temp, 3, &RW, NULL);
            }

            WriteFile(hFile, Palette, 16 % 4, &RW, NULL);
        }
        delete temp;

        CloseHandle(hFile);
#endif


        // tileset
        block_offset = get_u32le(0x08 + block_number * 0x0C + 0x04);
        if (block_offset < get_u32le(0x04)) continue;
        start = block_offset;

        u32 number_of_tileset = get_u32le(start);

        temp_tile = (TempTile *)realloc(temp_tile, sizeof(TempTile) * number_of_tileset);
        for (u16 tile = 0; tile < number_of_tileset; tile++)
        {
            temp_tile[tile].height = 0;
            temp_tile[tile].width  = 0;
            temp_tile[tile].row    = NULL;
        }

        for (u32 tileset = 0; tileset < number_of_tileset; tileset++)
        {
            u32 tileset_offset = get_u32le(start + 0x04 + tileset * 0x04);

            temp_tile[tileset].width  = get_u32le(start + tileset_offset) * 4;
            temp_tile[tileset].height = get_u32le(start + tileset_offset + 0x02);

            temp_tile[tileset].row = (TempTileRow *)realloc(temp_tile[tileset].row, sizeof(TempTileRow) * temp_tile[tileset].height);
            // initialize new rows
            for (u16 row = 0; row < temp_tile[tileset].height; row++)
            {
                temp_tile[tileset].row[row].cell = (u8 *)malloc(sizeof(u8) * temp_tile[tileset].width);
            }



            for (int y = 0; y < temp_tile[tileset].height; y++)
            {
                for (int x = 0; x < temp_tile[tileset].width; x += 2)
                {
                    u8 src = *((u8*)buffer + start + tileset_offset + 0x04 + x / 2 + y * temp_tile[tileset].width / 2);

                    temp_tile[tileset].row[y].cell[x]     = src & 0x0F;
                    temp_tile[tileset].row[y].cell[x + 1] = src >> 4;
                }
            }
#if 0
            for (int z = 0; z < clut->height; z++)
            {
                BITMAPFILEHEADER bfh;
                BITMAPINFOHEADER bih;
                DWORD RW;
                BYTE Palette [1024];
                memset(Palette, 0, 1024);

                // Заполним их
                memset (&bfh, 0, sizeof(bfh));
                bfh.bfType = 0x4D42;
                bfh.bfOffBits = sizeof(bfh) + sizeof(bih) + 1024;
                bfh.bfSize = bfh.bfOffBits + 3 * temp_tile[tileset].width * temp_tile[tileset].height + temp_tile[tileset].height * (temp_tile[tileset].width % 4);

                memset (&bih, 0, sizeof(bih));
                bih.biSize = sizeof(bih);
                bih.biBitCount = 24;
                bih.biCompression = BI_RGB;
                bih.biHeight = temp_tile[tileset].height;
                bih.biWidth = temp_tile[tileset].width;
                bih.biPlanes = 1;

                TCHAR name[99];
                wsprintf(name, "%s_b%d_t%d_p%d.bmp", file_name.c_str(), block_number, tileset, z);
                HANDLE hFile = CreateFile(name, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, 0, NULL);

                WriteFile (hFile, &bfh, sizeof (bfh), &RW, NULL);
                WriteFile (hFile, &bih, sizeof (bih), &RW, NULL);
                WriteFile (hFile, Palette, 1024, &RW, NULL);

                Color *temp = new Color;
                for (y = temp_tile[tileset].height - 1; y >= 0; y--)
                {
                    for (int x = 0; x < temp_tile[tileset].width; x++)
                    {
                        temp->b = clut->row[z].cell[temp_tile[tileset].row[y].cell[x]].r;
                        temp->g = clut->row[z].cell[temp_tile[tileset].row[y].cell[x]].g;
                        temp->r = clut->row[z].cell[temp_tile[tileset].row[y].cell[x]].b;

                        WriteFile(hFile, temp, 3, &RW, NULL);
                    }

                    WriteFile(hFile, Palette, temp_tile[tileset].width % 4, &RW, NULL);
                }
                delete temp;

                CloseHandle(hFile);
            }
        #endif
        }



        // а теперь создадим анимационные кадры
        block_offset     = get_u32le(0x08 + block_number * 0x0C);
        u32 frame_offset = get_u32le(block_offset + 0x08);
        start            = block_offset + frame_offset;

        animation = (Animation*)realloc(animation, sizeof(Animation) * (block_number + 1));
        animation[block_number].number_of_frames = *((u8*)buffer + start);
        animation[block_number].frame = (Frame *)malloc(sizeof(Frame) * animation[block_number].number_of_frames);

        for (u8 frame_number = 0x00; frame_number < 0x01/*animation[block_number].number_of_frames*/; frame_number++)
        {
            animation[block_number].frame[frame_number].height = 255;
            animation[block_number].frame[frame_number].width = 255;
            animation[block_number].frame[frame_number].row = (FrameRow *)malloc(sizeof(FrameRow) * animation[block_number].frame[frame_number].height);

            for (u8 row = 0; row < animation[block_number].frame[frame_number].height; row++)
            {
                animation[block_number].frame[frame_number].row[row].cell = (Color *)malloc(sizeof(Color) * animation[block_number].frame[frame_number].width);
                memset(animation[block_number].frame[frame_number].row[row].cell, 0, sizeof(Color) * animation[block_number].frame[frame_number].width);
            }

            u32 frame_start = start + get_u16le(start + 0x02 + frame_number * 0x02);
            u8 number_of_tile = *((u8*)buffer + frame_start);
            // search for tile coords in frame
            u32 tile_in_frame_start = frame_start + 0x04 + number_of_tile * 0x02;

            for (u8 tile_number = 0; tile_number < number_of_tile; tile_number++)
            {
                for (u8 src = 0x00;;)
                {
                    src = *((u8*)buffer + tile_in_frame_start + tile_number * 0x03);
                    if ((src >> 4) == 0x0E)
                    {
                        tile_in_frame_start += 3;
                    }
                    else if ((src >> 4) == 0x0C)
                    {
                        tile_in_frame_start += 1;
                    }
                    else if (src == 0x00)
                    {
                        break;
                    }
                    else
                    {
                        logger->log("Hmm.... look at 284 row in file enemy2d.cpp Strange block are strange");
                        break;
                    }
                }
                u16 tile_start = start + get_u16le(frame_start + 0x04 + tile_number * 0x02);

                u8 z           = (*((u8*)buffer + tile_start + 0x00)) >> 1;
                u8 tile_x      = *((u8*)buffer + tile_start + 0x01);
                u8 tile_y      = *((u8*)buffer + tile_start + 0x02);
                u8 tile_width  = *((u8*)buffer + tile_start + 0x03);
                u8 tile_height = *((u8*)buffer + tile_start + 0x04);

                u8 tile_in_frame_x = (s8)*((u8*)buffer + tile_in_frame_start + tile_number * 0x03 + 0x01) + 127;
                u8 tile_in_frame_y = (s8)*((u8*)buffer + tile_in_frame_start + tile_number * 0x03 + 0x02) + 127;

                for (u8 y = tile_in_frame_y; y < tile_in_frame_y + tile_height; y++)
                {
                    for (u8 x = tile_in_frame_x; x < tile_in_frame_x + tile_width; x++)
                    {
                        if (clut->row[0].cell[temp_tile[z].row[tile_y + y - tile_in_frame_y].cell[tile_x + x - tile_in_frame_x]].r != 0 ||
                            clut->row[0].cell[temp_tile[z].row[tile_y + y - tile_in_frame_y].cell[tile_x + x - tile_in_frame_x]].g != 0 ||
                            clut->row[0].cell[temp_tile[z].row[tile_y + y - tile_in_frame_y].cell[tile_x + x - tile_in_frame_x]].b != 0)
                        {
                            animation[block_number].frame[frame_number].row[y].cell[x] = clut->row[0].cell[temp_tile[z].row[tile_y + y - tile_in_frame_y].cell[tile_x + x - tile_in_frame_x]];
                        }
                    }
                }
            }

#if 1
            BITMAPFILEHEADER bfh;
            BITMAPINFOHEADER bih;
            DWORD RW;
            BYTE Palette [1024];
            memset(Palette, 0, 1024);

            // Заполним их
            memset (&bfh, 0, sizeof(bfh));
            bfh.bfType = 0x4D42;
            bfh.bfOffBits = sizeof(bfh) + sizeof(bih) + 1024;
            bfh.bfSize = bfh.bfOffBits + 3 * animation[block_number].frame[frame_number].height * animation[block_number].frame[frame_number].width + animation[block_number].frame[frame_number].height * (animation[block_number].frame[frame_number].width % 4);

            memset (&bih, 0, sizeof(bih));
            bih.biSize = sizeof(bih);
            bih.biBitCount = 24;
            bih.biCompression = BI_RGB;
            bih.biHeight = animation[block_number].frame[frame_number].height;
            bih.biWidth = animation[block_number].frame[frame_number].width;
            bih.biPlanes = 1;

            TCHAR name[99];
            wsprintf(name, "%s_b%d_f%02x.bmp", file_name.c_str(), block_number, frame_number);
            HANDLE hFile = CreateFile(name, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, 0, NULL);

            WriteFile (hFile, &bfh, sizeof (bfh), &RW, NULL);
            WriteFile (hFile, &bih, sizeof (bih), &RW, NULL);
            WriteFile (hFile, Palette, 1024, &RW, NULL);

            Color *temp = new Color;
            for (y = animation[block_number].frame[frame_number].height - 1; y >= 0; y--)
            {
                for (int x = 0; x < animation[block_number].frame[frame_number].width; x++)
                {
                    temp->b = animation[block_number].frame[frame_number].row[y].cell[x].r;
                    temp->g = animation[block_number].frame[frame_number].row[y].cell[x].g;
                    temp->r = animation[block_number].frame[frame_number].row[y].cell[x].b;

                    WriteFile(hFile, temp, 3, &RW, NULL);
                }

                WriteFile(hFile, Palette, animation[block_number].frame[frame_number].width % 4, &RW, NULL);
            }
            delete temp;

            CloseHandle(hFile);
#endif
        }
    }


/*
    for (u16 row = 0; row < temp_tile[tile].height; row++)
    {
        free(temp_tile[tile].row[row].cell);
    }
*/
    free(temp_tile);
    for (u16 row = 0; row < clut->height; row++)
    {
        free(clut->row[row].cell);
    }
    free(clut);
}



void
Enemy2D::viewEnemy2D()
{
}