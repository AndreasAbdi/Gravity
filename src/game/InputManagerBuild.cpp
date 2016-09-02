#include "game/InputManagerBuild.h"

namespace Gravity {
	InputManager buildInputManager(World &world) {
		InputManager inputManager;
		CommandBuilder commandBuilder;
		inputManager.setCommands(commandBuilder.buildCommands(world));
		return inputManager;
	}
}

