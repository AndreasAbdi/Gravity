#pragma once
#include "game/Player.h"
#include "game/PlayerFactory.h"
#include "engine/World.h"

namespace Gravity {
	class Game {
	public:
		Player * player;
		World world;
		Game();
		~Game();
	private:
		void createPlayer();
	};
}