#pragma once 
#include "game/GraphicComponent.h"
#include "game/Character.h"


namespace Gravity {
	class SquareGraphicComponent : public GraphicComponent {
	public:	
		void update(const Character& character, Screen &screen);
	};
}