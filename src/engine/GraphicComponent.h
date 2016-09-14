#pragma once
#include "engine/Component.h"
#include "graphics/Screen.h"
#include "engine/PhysicsComponent.h"
namespace Gravity {
	class PhysicsComponent;

	class GraphicComponent : public Component {
	public:
		virtual void update(Screen &screen) = 0;
	};
}