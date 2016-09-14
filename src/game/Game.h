#pragma once
#include "game/Character.h"
#include "engine/World.h"
#include "game/SquareGraphicComponent.h"
#include "game/SquarePhysicsComponent.h"

namespace Gravity {
	class Game {
	public:
		Character player;
		World world;
		Game();
	private:
		void createPlayer();
	};
}