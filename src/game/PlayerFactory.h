#pragma once
#include "engine/World.h"
#include "game/Player.h"
#include "game/SquareGraphicComponent.h"
#include "game/SquarePhysicsComponent.h"

namespace Gravity {
	class PlayerFactory {
	public:
		Player * createPlayer(World &world);
	};
};