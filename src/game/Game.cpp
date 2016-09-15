#include "game/Game.h"

namespace Gravity {
	Game::Game() {
		createPlayer();
	}
	Game::~Game() {
		delete player;
	}
	void Game::createPlayer() {
		PlayerFactory playerFactory;
		this->player = playerFactory.createPlayer(world);
	}
}