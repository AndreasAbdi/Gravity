#pragma once
#include "game/CommandBuilder.h"
#include "game/Command.h"
#include "game/InputManager.h"
#include "game/World.h"

namespace Gravity {
	InputManager buildInputManager(World &world);
}