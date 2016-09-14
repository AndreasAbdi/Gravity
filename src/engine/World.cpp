#include "World.h"

namespace Gravity {
	World::World() {
		for (int index = 0; index < this->MAX_ELEM; index++) {
			this->freePositions.push_back(index);
		}
	}

	World::~World() {
		for (auto iter = this->filledPositions.begin(); iter != this->filledPositions.end(); ++iter) {
			delete physicsComponents[(*iter)];
			delete graphicComponents[(*iter)];
		}
	}

	void World::update(Screen &screen) {
		for (auto iter = this->filledPositions.begin(); iter != this->filledPositions.end(); ++iter) {
			physicsComponents[(*iter)]->update();
		}
		for (auto iter = this->filledPositions.begin(); iter != this->filledPositions.end(); ++iter) {
			graphicComponents[(*iter)]->update(screen);
		}
	}

	void World::update(Screen & screen, int index) {
		if (entityAtIndex[index]) {
			physicsComponents[index]->update();
			graphicComponents[index]->update(screen);

		}
	}

	int World::addEntity(PhysicsComponent * physicsComponent, GraphicComponent * graphicComponent) {
		if (!this->freePositions.empty()) {
			int entityPosition = freePositions.front();
			graphicComponents[entityPosition] = graphicComponent;
			physicsComponents[entityPosition] = physicsComponent;
			entityAtIndex[entityPosition] = true;
			freePositions.erase(freePositions.begin());
			filledPositions.push_back(entityPosition);
			return entityPosition;
		} else {
			throw std::overflow_error("no more space");
		}
	}

	void World::deleteEntity(int index) {
		if (entityAtIndex[index]) {
			delete physicsComponents[index];
			delete graphicComponents[index];
			entityAtIndex[index] = false;
			filledPositions.erase(std::find(filledPositions.begin(), filledPositions.end(), index));
			freePositions.push_back(index);
		}
	}
}