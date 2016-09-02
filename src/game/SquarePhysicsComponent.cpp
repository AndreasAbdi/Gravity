#include "game/SquarePhysicsComponent.h"

namespace Gravity {
	void SquarePhysicsComponent::update() {
		this->position += this->velocity;
	};
};