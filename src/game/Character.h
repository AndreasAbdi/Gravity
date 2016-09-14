#pragma once
#include <vector>
#include "utility/vector2D.h"
#include "engine/Component.h"
#include "engine/GraphicComponent.h"
#include "engine/PhysicsComponent.h"

namespace Gravity {

	class GraphicComponent;
	class PhysicsComponent;

	class Character {
	public:
		GraphicComponent * graphicComponent;
		PhysicsComponent * physicsComponent;
	public:
		Character();
		Character(GraphicComponent * inputGraphicComponent, PhysicsComponent * inputPhysicsComponent) :
			graphicComponent(inputGraphicComponent), physicsComponent(inputPhysicsComponent) {};
		void setComponents(GraphicComponent * inputGraphicComponent, PhysicsComponent * inputPhysicsComponent);
		void update(Screen &screen);
	};
}