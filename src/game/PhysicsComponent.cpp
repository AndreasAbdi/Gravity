#include "game/PhysicsComponent.h"

namespace Gravity {
	void PhysicsComponent::moveBy(vector2D<double> moveVector) {
		this->position += moveVector;
	}

}
