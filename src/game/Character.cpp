#include "Character.h"

namespace Gravity {
	Character::Character() {
	}

	Character::~Character() {};

	void Character::update(Screen &screen) {
		world->physicsComponents[index]->update();
		world->graphicComponents[index]->update(screen);
	};
}