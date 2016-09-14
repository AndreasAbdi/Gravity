#include "input/InputManagerBuild.h"

namespace Gravity {
	//TODO return to pointer? shared pointer?
	InputManager buildInputManager(Game &game) {
		InputManager inputManager;
		CommandBuilder commandBuilder;
		inputManager.setCommands(commandBuilder.buildCommands(game));
		return inputManager;
	}
}

