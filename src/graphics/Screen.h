#pragma once

#include <iostream>
#include <stdio.h>
#include "SDL.h"
#include "graphics\Filter.h"
#include "graphics\Pixel.h"
#include "DoubleBuffer.h"

namespace Gravity {

	class Screen {
	public:
		static constexpr const char *  DEFAULT_NAME = "DEFAULT NAME";
		static const int DEFAULT_HEIGHT = 600;
		static const int DEFAULT_WIDTH = 800;
	private:
		int height;
		int width;
		const char * name;

		SDL_Window * window;
		SDL_Renderer * renderer;
		SDL_Texture * texture;
		DoubleBuffer doubleBuffer;
	public:
		Screen(const int width, const int height, const char * name);
		Screen();

		bool initialize();
		bool terminate();
		bool processEvents();
		void update();
		
		void clear();

		void setPixel(Pixel pixel);
		Point getSize() { return Point(width, height); };

	private:
		bool initializeComponents();
		void handleInitializeFailure();
		
		friend class Filter;
	};
}