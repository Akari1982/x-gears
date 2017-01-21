#ifndef _TIM_H
#define _TIM_H



class Tim
{
	public:
		// constructor from file buffer
		Tim(void* input, int bufferSize);

		// destructor
		virtual
		~Tim();

		void
		convert(unsigned int clut_number);

		int
		getNumberOfCLUT();

	public:
		struct bmpFileHeader
		{
			unsigned short bfType;
			unsigned long  bfSize;
			unsigned short bfReserved1;
			unsigned short bfReserved2;
			unsigned long  bfOffBits;
		} bmp_file_header;

		struct bmpInfoHeader
		{
			unsigned long  biSize;
			long           biWidth;
			long           biHeight;
			unsigned short biPlanes;
			unsigned short biBitCount;
			unsigned long  biCompression;
			unsigned long  biSizeImage;
			long           biXPelsPerMeter;
			long           biYPelsPerMeter;
			unsigned long  biClrUsed;
			unsigned long  biClrImportant;
		} bmp_info_header;

		struct timHeader
		{
			unsigned long  id_tag;
			unsigned long  id_tag_clut;
			unsigned long  clut_size; // Size of CLUT + 12 (accounting for 12 bytes before the CLUT block starts)
			unsigned short x;
			unsigned short y;
			unsigned short number_of_colors;
			unsigned short number_of_clut;
		} *tim_header;

		struct timHeader2
		{
			unsigned long  data_size;
			unsigned short x;
			unsigned short y;
			unsigned short width;
			unsigned short height;
		} *tim_header2;

		struct CLUT
		{
			unsigned char r;
			unsigned char g;
			unsigned char b;
			unsigned char a;
		} *clut;

		// loaded tim buffer
		void *input;
		// size of buffer
		int input_size;

		// loaded tim buffer
		void *output;
		// size of buffer
		int output_size;

	protected:
		// number of clut
		int clut_count;
};
#endif