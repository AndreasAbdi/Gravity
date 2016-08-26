#include "Screen.h"

namespace Gravity {
	Screen::Screen(const int width, const int height, const char * name) 
		: window(NULL), renderer(NULL), texture(NULL), buffer(NULL) {
		this->name = name;
		this->height = height;
		this->width = width;
	};

	Screen::Screen() : Screen(DEFAULT_WIDTH, DEFAULT_HEIGHT, DEFAULT_NAME) {};

	bool Screen::initialize() {
		if (SDL_Init(SDL_INIT_VIDEO) < 0) {
			return false;
		}

		if (initializeComponents() == false) {
			handleInitializeFailure();
			return false;
		}

		buffer = new Uint32[width*height];
		updateScreenToBlack();
		return true;
	};

	bool Screen::terminate() {
		delete[] buffer;
		SDL_DestroyTexture(texture);
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		return true;
	};

	void Screen::setPixel(Pixel pixel) {

		int position = pixel.point.y*width + pixel.point.x;
		buffer[position] = pixel.rgb.rgbaRepresentation;
	};

	bool Screen::initializeComponents() {
		window = SDL_CreateWindow(name,
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
		texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888,
			SDL_TEXTUREACCESS_STATIC, width, height);
		return (window != NULL && renderer != NULL && texture != NULL);
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
		SDL_Quit();
	}

	void Screen::update() {
		SDL_UpdateTexture(texture, NULL, buffer, width*sizeof(Uint32));
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, texture, NULL, NULL);
		SDL_RenderPresent(renderer);
	}

	void Screen::updateScreenToBlack() {
		memset(buffer, 0, width*height*sizeof(Uint32));
		update();
	};

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