#include "game/SquarePhysicsComponent.h"

namespace Gravity {
	void SquarePhysicsComponent::update(const Character &character) {
		this->position += this->velocity;
	};
};