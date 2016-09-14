#pragma once

#include <vector>
#include "input/Command.h"
#include "engine/World.h"

namespace Gravity {
	class CommandBuilder {
	public:
		std::vector<Command> buildCommands(World &world);
	};
}