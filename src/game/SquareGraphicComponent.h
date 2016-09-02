#pragma once 

#include "game/Character.h"
#include "game/GraphicComponent.h"
#include "game/PhysicsComponent.h"

namespace Gravity {
	class SquareGraphicComponent : public GraphicComponent {
	public:	
		void update(const Character& character, const PhysicsComponent &physicsComponent, Screen &screen);
	};
}