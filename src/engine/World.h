#pragma once
#include "game/Character.h"
#include "PhysicsComponent.h"
#include "GraphicComponent.h"
#include "game/SquareGraphicComponent.h"
#include "game/SquarePhysicsComponent.h"
#include "graphics/Screen.h"

namespace Gravity {
	class World {
	public:
		//TODO: handle edge cases
		static const int MAX_ELEM = 5000;
		Character player;

	private:
		int currentObjectIndex;
		PhysicsComponent * physicsComponents[MAX_ELEM];
		GraphicComponent * graphicComponents[MAX_ELEM];

	public:
		World();
		~World();
		void update(Screen &screen);

	private:
		void createPlayer();
	};
}