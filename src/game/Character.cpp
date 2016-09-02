#include "Character.h"

namespace Gravity {
	Character::Character() {
	
	};

	void Character::setComponents(GraphicComponent * inputGraphicComponent, PhysicsComponent * inputPhysicsComponent) {
		this->graphicComponent = inputGraphicComponent;
		this->physicsComponent = inputPhysicsComponent;
	};

	void Character::update(Screen &screen) {
		physicsComponent->update();
		graphicComponent->update(*(this->physicsComponent), screen);
	};
}