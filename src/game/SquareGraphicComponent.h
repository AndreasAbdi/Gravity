#pragma once 

#include "game/Character.h"
#include "engine/GraphicComponent.h"
#include "engine/PhysicsComponent.h"

namespace Gravity {
	class SquareGraphicComponent : public GraphicComponent {
	public:	
		void update(const PhysicsComponent &physicsComponent, Screen &screen);
	};
}