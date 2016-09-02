#pragma once
#include <vector>
#include "utility/vector2D.h"
#include "game/Component.h"
#include "game/GraphicComponent.h"
#include "game/PhysicsComponent.h"

namespace Gravity {

	class GraphicComponent;
	class PhysicsComponent;

	class Character {
	public:
		GraphicComponent * graphicComponent;
		PhysicsComponent * physicsComponent;
	public:
		Character(GraphicComponent * inputGraphicComponent, PhysicsComponent * inputPhysicsComponent) :
			graphicComponent(inputGraphicComponent), physicsComponent(inputPhysicsComponent) {};
		void update(Screen &screen);
	};
}