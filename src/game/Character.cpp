#include "Character.h"

namespace Gravity {



	void Character::update(Screen &screen) {
		graphicComponent->update(*this, *(this->physicsComponent), screen);
	}
}