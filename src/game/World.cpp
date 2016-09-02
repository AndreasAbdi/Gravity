#include "World.h"

namespace Gravity {
	void World::createPlayer() {
		SquareGraphicComponent * graphicComponent = new SquareGraphicComponent();
		SquarePhysicsComponent * physicsComponent = new SquarePhysicsComponent(vector2D<double>(300, 300), vector2D<double>(0, 0), vector2D<double>(50, 50));
		player.setComponents(graphicComponent, physicsComponent);
		this->currentObjectIndex++;	
	}

	World::World() {
		currentObjectIndex = 0;
		createPlayer();
	};

	World::~World() {
		for (int i = 0; i < currentObjectIndex; i++) {
			delete physicsComponents[i];
			delete graphicComponents[i];
		}
		free;
	}
}