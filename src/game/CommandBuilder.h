#pragma once

#include <vector>
#include "game/Command.h"
#include "game/World.h"

namespace Gravity {
	class CommandBuilder {
	public:
		std::vector<Command> buildCommands(World &world);
	};
}