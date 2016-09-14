#pragma once
#include "input/CommandBuilder.h"
#include "input/Command.h"
#include "input/InputManager.h"
#include "game/Game.h"

namespace Gravity {
	InputManager buildInputManager(Game &game);
}