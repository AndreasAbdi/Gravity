#pragma once
#include "graphics/Screen.h"
#include "game/Character.h"
#include "engine/PhysicsComponent.h"
namespace Gravity {
	class PhysicsComponent;

	class GraphicComponent : public Component {
	public:
		virtual void update(const PhysicsComponent& physicsComponent, Screen &screen) = 0;
	};
}