#pragma once 
#include "engine/GraphicComponent.h"
#include "game/SquarePhysicsComponent.h"
#include "engine/World.h"

namespace Gravity {
	class SquareGraphicComponent : public GraphicComponent {
	public:	
		void update(Screen &screen);
	};
}