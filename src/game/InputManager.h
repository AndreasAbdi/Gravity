#pragma once
#include "SDL.h"
#include <map>
#include <vector>
#include "game/Command.h"

namespace Gravity {
	class InputManager {
	private:
		std::map<Uint8, bool> keysPressed;
		std::vector<Command> commands;
		const Uint8 * keyboardState;
		int numberKeysPressed;
	public:
		void setCommands(std::vector<Command> commands);
		void handleInput();
	};
}