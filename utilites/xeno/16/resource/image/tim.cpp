#include <memory.h>
#include <malloc.h>

#include "tim.h"
#include "../../log.h"



Tim::Tim(void* buffer, int buffer_size):
	input_size(0),
	output_size(0),
	input(NULL),
	output(NULL)
{
	input = malloc(buffer_size);
	memset(input, 0, buffer_size);
	if (input == NULL)
	{
		logger->log("Warning: insufficient memory available, try to malloc %d bytes for 'input'", buffer_size);
	}

	memcpy((unsigned char*)input, (unsigned char*)buffer, buffer_size);
	input_size = buffer_size;

	// get number of palette
	tim_header = (timHeader*)(input);
	clut_count = tim_header->number_of_clut;
}



Tim::~Tim()
{
	free(input);
	free(output);
}



void
Tim::convert(unsigned int clut_number)
{
	if (clut_number > clut_count)
	{
		logger->log("Warning: 'clut_number' is greater than number of clut in file.");
		return;
	}
	unsigned char palette [1024];
	// set palette to zero
	memset(palette, 0, 1024);

	tim_header  = (timHeader*)(input);



	// convert 4BPP tim
	if (tim_header->id_tag == 0x10 && tim_header->id_tag_clut == 0x08)
	{
		tim_header2 = (timHeader2*)((unsigned char*)input + sizeof(timHeader) + tim_header->number_of_colors * tim_header->number_of_clut * 2);

		int width  = tim_header2->width * 4;
		int height = tim_header2->height;

		clut = (CLUT*)malloc(sizeof(CLUT) * tim_header->number_of_colors * tim_header->number_of_clut);

		for (int i = 0; i < tim_header->number_of_colors; i++)
		{
			unsigned short col = (((unsigned char*)input + sizeof(timHeader) + clut_number * tim_header->number_of_colors * 2 + i * 2 + 1)[0] << 8) | ((unsigned char*)input + sizeof(timHeader) + clut_number * tim_header->number_of_colors * 2 + i * 2)[0];
			clut[i].r = (((col      ) & 31) * 255 + 15) / 31;
			clut[i].g = (((col >>  5) & 31) * 255 + 15) / 31;
			clut[i].b = (((col >> 10) & 31) * 255 + 15) / 31; 
			clut[i].a = ((col & 0x8000) || (col == 0)) ? 0 : 255;
		}



		// set if to zero by default
		memset(&bmp_file_header, 0, sizeof(bmpFileHeader));
		// set type to 'BM'
		bmp_file_header.bfType        = 0x4D42;
		// set size of palette to 1Kb
		bmp_file_header.bfOffBits     = sizeof(bmpFileHeader) + sizeof(bmpInfoHeader) + sizeof(palette);
		// count size of the file
		bmp_file_header.bfSize        = bmp_file_header.bfOffBits + 4 * width * height + height * (width % 4);

		memset(&bmp_info_header, 0, sizeof(bmpInfoHeader));
		bmp_info_header.biSize        = sizeof(bmpInfoHeader);
		bmp_info_header.biBitCount    = 32;     // 32 bit per pixel
		bmp_info_header.biCompression = 0;      // without compression
		bmp_info_header.biHeight      = height;
		bmp_info_header.biWidth       = width;
		bmp_info_header.biPlanes      = 1;
												// all other field are 0


		output_size = bmp_file_header.bfSize;
		output = malloc(output_size);

		if (output == NULL)
		{
			logger->log("Warning: insufficient memory available, try to malloc %d bytes for 'output'", bmp_file_header.bfSize);
		}
		int offset = 0;
		memset(output, 0, output_size);
		memcpy((unsigned char*)output, &bmp_file_header, sizeof(bmpFileHeader));
		offset += sizeof(bmpFileHeader);
		memcpy((unsigned char*)output + offset, &bmp_info_header, sizeof(bmpInfoHeader));
		offset += sizeof(bmpInfoHeader);
		memcpy((unsigned char*)output + offset, palette, sizeof(palette));
		offset +=sizeof(palette);

		for (int y = height - 1; y >= 0; y--)
		{
			for (int x = 0; x < width / 2; x++)
			{
				memcpy(((unsigned char*)output + offset), &clut[((((unsigned char*)input + sizeof(timHeader) + tim_header->number_of_colors * tim_header->number_of_clut * 2 + sizeof(timHeader2) + y * width / 2 + x)[0]) & 0x0F)], sizeof(CLUT));
				offset += sizeof(CLUT);

				memcpy(((unsigned char*)output + offset), &clut[(((((unsigned char*)input + sizeof(timHeader) + tim_header->number_of_colors * tim_header->number_of_clut * 2 + sizeof(timHeader2) + y * width / 2 + x)[0]) & 0xF0) >> 4)], sizeof(CLUT));
				offset += sizeof(CLUT);
			}

			offset += width % 4;
		}

		free(clut);
	}
	else
	{
		logger->log("Warning: unknown format! (tim_header->id_tag = %02x) (tim_header->id_tag_clut = %02x)", tim_header->id_tag, tim_header->id_tag_clut);
		logger->log("8BPP TIM, 16BPP TIM, 24BPP TIM left");
	}

	return;
}



int
Tim::getNumberOfCLUT()
{
	return clut_count;
}