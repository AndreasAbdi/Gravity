#pragma once
#include <vector>
#include "utility/vector2D.h"
#include "game/Component.h"
#include "game/GraphicComponent.h"

namespace Gravity {

	class GraphicComponent;

	class Character {
	private:
		vector2D<double> position;
		vector2D<double> size;
		GraphicComponent * graphicComponent;
	public:
		Character(GraphicComponent * graphicComponent);
		void moveBy(vector2D<double> moveVector);
		vector2D<double> getPosition() const;
		vector2D<double> getSize() const;
		void update(Screen &screen);
	};
}