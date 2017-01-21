#include "../../log.h"
#include "image.h"
#include <iostream>
#include <cassert>
#include <SDL/SDL_image.h>



Image::Image(SDL_Surface *image):
	image(image)
{
	// Default to opaque
	alpha = 1.0f;
}



Image::Image(void* buffer, unsigned int bufferSize):
	// Default to opaque
	alpha(1.0f)
{
	// Load the raw file data from the buffer in an RWops structure
	SDL_RWops *rw = SDL_RWFromMem(buffer, bufferSize);

	// Use SDL_Image to load the raw image data and have it free the data
	SDL_Surface* tmpImage = IMG_Load_RW(rw, 1);

	if (tmpImage == NULL)
	{
		logger->log("Warning: error, image load failed.");
	}

	// Determine 32-bit masks based on byte order
	Uint32 rmask, gmask, bmask, amask;
#if SDL_BYTEORDER == SDL_BIG_ENDIAN
	rmask = 0xff000000;
	gmask = 0x00ff0000;
	bmask = 0x0000ff00;
	amask = 0x000000ff;
#else
	rmask = 0x000000ff;
	gmask = 0x0000ff00;
	bmask = 0x00ff0000;
	amask = 0xff000000;
#endif

	// Convert the image to a 32 bit software surface for processing
	SDL_Surface *formatImage = SDL_CreateRGBSurface(SDL_SWSURFACE, 0, 0, 32, rmask, gmask, bmask, amask);

	if (formatImage == NULL)
	{
		logger->log("Warning: error, image load failed: not enough memory.");
		SDL_FreeSurface(tmpImage);
	}

	image = SDL_ConvertSurface(tmpImage, formatImage->format, SDL_SWSURFACE);

	SDL_FreeSurface(formatImage);

	if (image == NULL)
	{
		logger->log("Warning: error, image load failed: not enough memory.");
	}

	bool hasAlpha = false;
	int i;
	Uint32 pink = SDL_MapRGB(image->format, 255, 0, 255);

	// Figure out whether the image uses its alpha layer
	for (i = 0; i < image->w * image->h; ++i)
	{
		Uint8 r, g, b, a;
		SDL_GetRGBA(((Uint32*)image->pixels)[i], image->format, &r, &g, &b, &a);

		if (a != 255)
		{
			hasAlpha = true;
			break;
		}
	}

	SDL_FreeSurface(image);

	if (hasAlpha)
	{
		SDL_SetAlpha(tmpImage, SDL_SRCALPHA | SDL_RLEACCEL, SDL_ALPHA_OPAQUE);
	}

	// Set color key and alpha blending optins, and convert the surface to the
	// current display format
	SDL_Surface *prevImage = tmpImage;
	if (hasAlpha)
	{
		image = SDL_DisplayFormatAlpha(tmpImage);
	}
	else
	{
		image = SDL_DisplayFormat(tmpImage);
	}
	SDL_FreeSurface(prevImage);

	if (image == NULL)
	{
		logger->log("Warning: wrror: Image convert failed.");
	}
}



Image::~Image()
{
	// Free the image surface.
	if (image != NULL)
	{
		SDL_FreeSurface(image);
	}
}

int
Image::getWidth() const
{
	if (image != NULL)
	{
		return image->w;
	}
	return 0;
}



int
Image::getHeight() const
{
	if (image != NULL)
	{
		return image->h;
	}
	return 0;
}



Image*
Image::getSubImage(int x, int y, int width, int height)
{
	// Create a new clipped sub-image
	return new SubImage(this, image, x, y, width, height);
}




bool
Image::draw(SDL_Surface *screen, int srcX, int srcY, int dstX, int dstY, int width, int height)
{
	// Check that preconditions for blitting are met.
	if (screen == NULL || image == NULL) return false;

	SDL_Rect dstRect;
	SDL_Rect srcRect;
	dstRect.x = dstX; dstRect.y = dstY;
	srcRect.x = srcX; srcRect.y = srcY;
	srcRect.w = width;
	srcRect.h = height;

	if (SDL_BlitSurface(image, &srcRect, screen, &dstRect) < 0)
	{
		logger->log("Warning: The SDL_BlitSurface was unsuccessful. Draw has failed.");
		return false;
	}
	SDL_UpdateRects(screen, 1, &dstRect);
	return true;
}



bool
Image::draw(SDL_Surface *screen, int x, int y)
{
	return draw(screen, 0, 0, x, y, getWidth(), getHeight());
}



bool
Image::drawPattern(SDL_Surface *screen, int x, int y, int w, int h)
{
	int iw = getWidth();  // Width of image
	int ih = getHeight(); // Height of image
	if (iw == 0 || ih == 0)
	{
		logger->log("Warning: no need for drawPattern because iw == 0 || ih == 0");
		return true;
	}

	int px = 0;           // X position on pattern plane
	int py = 0;           // Y position on pattern plane

	while (py < h)
	{
		while (px < w)
		{
			int dw = (px + iw >= w) ? w - px : iw;
			int dh = (py + ih >= h) ? h - py : ih;
			if(!draw(screen, 0, 0, x + px, y + py, dw, dh))
			{
				logger->log("Warning: Draw part in x = '%d' and y = '%d' with width = '%d' and height = '%d' of pattern failed.", x + px, y + py, dw, dh);
				return false;
			}
			px += iw;
		}
		py += ih;
		px = 0;
	}
	return true;
}



void
Image::setAlpha(float a)
{
	alpha = a;

	// Set the alpha value this image is drawn at
	SDL_SetAlpha(image, SDL_SRCALPHA | SDL_RLEACCEL, (int)(255 * alpha));
}



float
Image::getAlpha()
{
	return alpha;
}



// SubImage Class
SubImage::SubImage(Image *parent, SDL_Surface *image, int x, int y, int width, int height):
	Image(image),
	parent(parent)
{
	// Set up the rectangle.
	rect.x = x;
	rect.y = y;
	rect.w = width;
	rect.h = height;
}



SubImage::~SubImage()
{
	image = NULL;
}



int
SubImage::getWidth() const
{
	return rect.w;
}



int
SubImage::getHeight() const
{
	return rect.h;
}



Image*
SubImage::getSubImage(int x, int y, int w, int h)
{
	return NULL;
}



bool
SubImage::draw(SDL_Surface *screen, int srcX, int srcY, int dstX, int dstY, int width, int height)
{
	// Check that preconditions for blitting are met.
	if (screen == NULL || image == NULL) return false;

	SDL_Rect dstRect;
	SDL_Rect srcRect;
	dstRect.x = dstX; dstRect.y = dstY;
	srcRect.x = rect.x + srcX;
	srcRect.y = rect.y + srcY;
	srcRect.w = width;
	srcRect.h = height;

	if (SDL_BlitSurface(image, &srcRect, screen, &dstRect) < 0)
	{
		return false;
	}

	return true;
}



bool
SubImage::draw(SDL_Surface *screen, int x, int y)
{
	return draw(screen, 0, 0, x, y, getWidth(), getHeight());
}