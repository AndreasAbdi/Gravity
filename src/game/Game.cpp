#include "game/Game.h"

namespace Gravity {
	Game::Game() {
		createPlayer();
	}

	void Game::createPlayer() {
		GraphicComponent *graphicComponent = new SquareGraphicComponent();
		PhysicsComponent *physicsComponent = new SquarePhysicsComponent(vector2D<double>(300, 300), vector2D<double>(0, 0), vector2D<double>(50, 50));
		int characterIndex = world.addEntity(physicsComponent, graphicComponent);
		player.setWorldConfiguration(characterIndex, &world);
		graphicComponent->setWorldConfiguration(characterIndex, &world);
		physicsComponent->setWorldConfiguration(characterIndex, &world);
	}
}