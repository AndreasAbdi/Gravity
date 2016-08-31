#include "Character.h"

namespace Gravity {

	void Character::moveBy(vector2D<double> moveVector) {
		this->position += moveVector;
	}

	vector2D<double> Character::getPosition() const {
		return this->position;
	}

	vector2D<double> Character::getSize() const {
		return this->size;
	}
	void Character::update(Screen &screen) {
		graphicComponent->update(*this, screen);
	}
}