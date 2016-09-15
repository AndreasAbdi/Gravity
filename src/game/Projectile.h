#pragma once
#include "game/Character.h"
#include "game/SquareGraphicComponent.h"
#include "game/SquarePhysicsComponent.h"

namespace Gravity {
	class Projectile : public Character {
	public:
		Projectile(World * world, vector2D<double> initialPosition, vector2D<double> velocity);
	};
};