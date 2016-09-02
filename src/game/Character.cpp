#include "Character.h"

namespace Gravity {
	void Character::update(Screen &screen) {
		physicsComponent->update(*this);
		graphicComponent->update(*this, *(this->physicsComponent), screen);
	}
}