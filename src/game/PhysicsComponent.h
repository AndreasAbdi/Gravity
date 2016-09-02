#pragma once
#include "game/Character.h"
#include "utility/vector2D.h"
namespace Gravity {

	class PhysicsComponent : public Component {
	public:
		vector2D<double> position;
		vector2D<double> velocity;
		vector2D<double> size;
	public:
		PhysicsComponent(vector2D<double> inputPosition, vector2D<double> inputVelocity, vector2D<double> inputSize) 
			: position(inputPosition), velocity(inputVelocity), size(inputSize) {};

		void moveBy(vector2D<double> moveVector);

		virtual void update(const Character& character) = 0;
	};
}
