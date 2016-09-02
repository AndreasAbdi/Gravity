#pragma once 
#include "game/PhysicsComponent.h"
#include "game/Character.h"
#include "utility/vector2D.h"

namespace Gravity {
	class SquarePhysicsComponent : public PhysicsComponent {
	public:
		vector2D<double> position;
		vector2D<double> velocity;
		
	public:
		SquarePhysicsComponent(vector2D<double> inputPosition, vector2D<double> inputVelocity) 
			: position(inputPosition), velocity(inputVelocity) {};
		void update(const Character& character);
	};
}