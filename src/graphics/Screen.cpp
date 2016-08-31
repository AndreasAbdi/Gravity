#include "Screen.h"

namespace Gravity {
	bool Screen::initialize(const int width, const int height, const char * name) {
		initializeParameters(width, height, name);
		if (initializeComponents() == false) {
			handleInitializeFailure();
			return false;
		}
		doubleBuffer = DoubleBuffer(width, height);
		update();
		return true;
	};

	bool Screen::terminate() {
		SDL_DestroyTexture(texture);
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		return true;
	};

	void Screen::setPixel(Pixel pixel) {
		doubleBuffer.setPixel(pixel);
	};

	bool Screen::initializeComponents() {
		window = SDL_CreateWindow(name,
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
		texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888,
			SDL_TEXTUREACCESS_STATIC, width, height);
		return (window != NULL && renderer != NULL && texture != NULL);
	}

	void Screen::initializeParameters(const int width, const int height, const char * name) {
		this->name = name;
		this->height = height;
		this->width = width;
	};

	void Screen::handleInitializeFailure() {
		if (texture != NULL) {
			SDL_DestroyTexture(texture);
		}
		if (renderer != NULL) {
			SDL_DestroyRenderer(renderer);
		}
		if (window != NULL) {
			SDL_DestroyWindow(window);
		}
	}

	void Screen::update() {
		SDL_UpdateTexture(texture, NULL, doubleBuffer.getFrontBuffer(), width*sizeof(Uint32));
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, texture, NULL, NULL);
		SDL_RenderPresent(renderer);
	}

	void Screen::clear(){
		doubleBuffer.clearFrontBuffer();
		update();
	}

	bool Screen::processEvents() {
		SDL_Event event;

		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				return false;
			}
		}
		return true;
	};
	


}