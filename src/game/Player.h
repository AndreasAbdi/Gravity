#pragma once
#include "game/Character.h"
#include "game/Projectile.h"

namespace Gravity {
	class Player : public Character {
	public:
		void shootProjectile();
	};
};