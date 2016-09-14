#include "World.h"

namespace Gravity {
	void World::createPlayer() {
		graphicComponents[currentObjectIndex] =  new SquareGraphicComponent();
		physicsComponents[currentObjectIndex] = new SquarePhysicsComponent(vector2D<double>(300, 300), vector2D<double>(0, 0), vector2D<double>(50, 50));
		player.setComponents(graphicComponents[currentObjectIndex], physicsComponents[currentObjectIndex]);
		this->currentObjectIndex++;	
	}

	World::World() {
		currentObjectIndex = 0;
		createPlayer();
	};

	void World::update(Screen &screen) {
		for (int i = 0; i < currentObjectIndex; i++) {
			physicsComponents[i]->update();
		}
		for (int i = 0; i < currentObjectIndex; i++) {
			graphicComponents[i]->update(*physicsComponents[i], screen);
		}
	}

	World::~World() {
		for (int i = 0; i < currentObjectIndex; i++) {
			delete physicsComponents[i];
			delete graphicComponents[i];
		}
	}
}