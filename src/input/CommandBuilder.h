#pragma once

#include <vector>
#include "input/Command.h"
#include "game/Game.h"

namespace Gravity {
	class CommandBuilder {
	public:
		std::vector<Command> buildCommands(Game &game);
	};
}