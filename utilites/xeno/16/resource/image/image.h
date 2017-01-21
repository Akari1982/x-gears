#ifndef _IMAGE_H
#define _IMAGE_H

#include <SDL/SDL.h>



class Image
{
	public:
		// constructor from image buffer
		Image(void* buffer, unsigned int bufferSize);

		// destructor
		virtual
		~Image();

		// Returns the width of the image.
		virtual int
		getWidth() const;

		// Returns the height of the image.
		virtual int
		getHeight() const;

		// Creates a new image with the desired clipping rectangle.
		// @return NULL if creation failed and a valid object otherwise.
		virtual Image*
		getSubImage(int x, int y, int width, int height);

		// Blits the image onto the screen.
		// @return true if the image was blitted properly, false otherwise.
		virtual bool
		draw(SDL_Surface *screen, int srcX, int srcY, int dstX, int dstY, int width, int height);

		// Blits the image onto the screen.
		// @return true if the image was blitted properly, false otherwise.
		virtual bool
		draw(SDL_Surface *screen, int x, int y);

		// Does a pattern fill on the given area.
		virtual bool
		drawPattern(SDL_Surface *screen, int x, int y, int w, int h);

		// Sets the alpha value of this image.
		void
		setAlpha(float alpha);

		// Returns the alpha value of this image.
		float
		getAlpha();


	protected:
		Image(SDL_Surface *image);

	protected:
		bool loaded;

		SDL_Surface *image;
		float alpha;
};



// A clipped version of a larger image.
class SubImage : public Image
{
	public:
		// Constructor.
		SubImage(Image *parent, SDL_Surface *image, int x, int y, int width, int height);

		// Destructor.
		virtual
		~SubImage();

		// Returns the width of the image.
		virtual int
		getWidth() const;

		// Returns the height of the image.
		virtual int
		getHeight() const;

		// Creates a new image with the desired clipping rectangle.
		// @return NULL if creation failed and a valid image otherwise.
		virtual Image*
		getSubImage(int x, int y, int width, int height);

		// Draws this image.
		virtual bool
		draw(SDL_Surface *screen, int srcX, int srcY, int dstX, int dstY, int width, int height);

		// Draws the clipped image onto the screen.
		// @return true if drawing was succesful, false otherwise.
		virtual bool
		draw(SDL_Surface *screen, int x, int y);

	private:
		Image *parent;
		SDL_Rect rect;
};

#endif