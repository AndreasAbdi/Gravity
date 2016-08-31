#pragma once

#include <iostream>
#include <stdio.h>
#include "SDL.h"
#include "graphics\Filter.h"
#include "graphics\Pixel.h"
#include "DoubleBuffer.h"

namespace Gravity {

	class Screen {
	private:
		int height;
		int width;
		const char * name;

		SDL_Window * window;
		SDL_Renderer * renderer;
		SDL_Texture * texture;
		DoubleBuffer doubleBuffer;
	public:
		bool initialize(const int width, const int height, const char * name);
		bool terminate();
		bool processEvents();
		void update();
		
		void clear();

		void setPixel(Pixel pixel);
		Point getSize() { return Point(width, height); };

	private:
		bool initializeComponents();
		void initializeParameters(const int width, const int height, const char * name);
		void handleInitializeFailure();
		
		friend class Filter;
	};
}