#include "SDLWrapper.h"

namespace SDL {
	bool initialize() {
		if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0) {
			return false;
		}
		return true;
	}
	void terminate() {
		SDL_Quit();
	}
}
