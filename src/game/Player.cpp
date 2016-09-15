#include "game/Player.h"

namespace Gravity {
	void Player::shootProjectile() {
		vector2D<double> position = this->world->physicsComponents[this->index]->position;
		vector2D<double> projectilePosition = position + vector2D<double>(0, 10);
		Projectile projectile(world, projectilePosition, vector2D<double>(0, 10));
	}
}