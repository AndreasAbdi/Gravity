#pragma once 
#include "game/PhysicsComponent.h"
#include "game/Character.h"
#include "utility/vector2D.h"

namespace Gravity {
	class SquarePhysicsComponent : public PhysicsComponent {
	public:
		SquarePhysicsComponent(vector2D<double> inputPosition, vector2D<double> inputVelocity, vector2D<double> inputSize) 
			: PhysicsComponent(inputPosition, inputVelocity, inputSize) {};
		void update();
	};
}