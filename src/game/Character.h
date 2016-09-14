#pragma once
#include <vector>
#include "utility/vector2D.h"
#include "engine/Component.h"
#include "engine/GraphicComponent.h"
#include "engine/PhysicsComponent.h"
#include "engine/World.h"

namespace Gravity {
	class Character {
	public:
		World * world;
		int index;
	public:
		Character();
		Character(World * inputWorld, int inputIndex) : world(inputWorld), index(inputIndex) {};

		void update(Screen &screen);

		void setWorldConfiguration(int index, World * world) {
			this->index = index;
			this->world = world;
		}
	};
}