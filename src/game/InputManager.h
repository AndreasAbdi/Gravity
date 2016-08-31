#pragma once
#include "SDL.h"
#include <map>
namespace Gravity {
	class InputManager {
	private:
		std::map<Uint8, bool> keysPressed;
		const Uint8 * keyboardState;
		int numberKeysPressed;
	public:
		void handleInput();
	};
}