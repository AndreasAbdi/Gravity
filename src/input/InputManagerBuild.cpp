#include "input/InputManagerBuild.h"

namespace Gravity {
	//TODO return to pointer? shared pointer?
	InputManager buildInputManager(World &world) {
		InputManager inputManager;
		CommandBuilder commandBuilder;
		inputManager.setCommands(commandBuilder.buildCommands(world));
		return inputManager;
	}
}

