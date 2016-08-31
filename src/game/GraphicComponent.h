#pragma once
#include "graphics/Screen.h"
#include "game/Character.h"

namespace Gravity {

	class GraphicComponent : public Component {
	public:
		virtual void update(const Character& character, Screen &screen) = 0;
	};
}