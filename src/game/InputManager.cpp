#include "InputManager.h"
namespace Gravity {
	void InputManager::setCommands(std::vector<Command> commands) {
		this->commands = commands;
	}

	void InputManager::handleInput() {
		SDL_PumpEvents();
		keyboardState = SDL_GetKeyboardState(&numberKeysPressed);
		
		
		for (auto commandIter = commands.begin(); commandIter != commands.end(); ++commandIter) {
			Command command = *commandIter;
			if (keyboardState[command.keyToInvoke]) {
				command.action();
			}
		}
	}
}