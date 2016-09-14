#pragma once
#include "input/CommandBuilder.h"
#include "input/Command.h"
#include "input/InputManager.h"
#include "engine/World.h"

namespace Gravity {
	InputManager buildInputManager(World &world);
}