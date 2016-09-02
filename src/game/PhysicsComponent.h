#pragma once
#include "game/Character.h"

namespace Gravity {

	class PhysicsComponent : public Component {
	public:
		virtual void update(const Character& character) = 0;
	};
}
