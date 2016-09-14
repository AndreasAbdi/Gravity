#pragma once
#include <vector>
#include "PhysicsComponent.h"
#include "GraphicComponent.h"
#include "graphics/Screen.h"

namespace Gravity {
	class World {
	public:
		//TODO: handle edge cases
		static const int MAX_ELEM = 5000;
		PhysicsComponent * physicsComponents[MAX_ELEM];
		GraphicComponent * graphicComponents[MAX_ELEM];
	private:
		int sizeOfIndexes;
		bool entityAtIndex[MAX_ELEM] = {};
		std::vector<int> freePositions;
		std::vector<int> filledPositions;


	public:
		World();
		~World();
		void update(Screen &screen);
		void update(Screen &screen, int index);
		int addEntity(PhysicsComponent *physicsComponent, GraphicComponent *graphicComponent);
		void deleteEntity(int index);
	};
}