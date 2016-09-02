#include "game/PhysicsComponent.h"

namespace Gravity {
	void PhysicsComponent::moveBy(vector2D<double> moveVector) {
		this->position += moveVector;
	}

	void PhysicsComponent::addToVelocity(vector2D<double> velocityVector) {
		this->velocity += velocityVector;
	}

}
