#pragma once
#include "game/Character.h"
#include "PhysicsComponent.h"
#include "GraphicComponent.h"
#include "game/SquareGraphicComponent.h"
#include "game/SquarePhysicsComponent.h"

namespace Gravity {
	class World {
	public:
		//TODO: handle edge cases
		static const int MAX_ELEM = 5000;
	private:
		int currentObjectIndex;
		PhysicsComponent * physicsComponents[MAX_ELEM];
		GraphicComponent * graphicComponents[MAX_ELEM];
	public:
		Character player;
		World();
		~World();
	private:
		void createPlayer();
	};
}