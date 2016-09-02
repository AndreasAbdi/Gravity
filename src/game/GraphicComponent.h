#pragma once
#include "graphics/Screen.h"
#include "game/Character.h"
#include "game/PhysicsComponent.h"
namespace Gravity {
	class PhysicsComponent;

	class GraphicComponent : public Component {
	public:
		virtual void update(const Character& character, const PhysicsComponent& physicsComponent, Screen &screen) = 0;
	};
}