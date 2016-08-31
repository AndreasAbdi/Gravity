#include "InputManager.h"
namespace Gravity {
	void InputManager::handleInput() {
		SDL_PumpEvents();
		keyboardState = SDL_GetKeyboardState(&numberKeysPressed);

		if (keyboardState[SDLK_a]) {

		}
	}
}