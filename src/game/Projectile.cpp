#include "game/Projectile.h"

namespace Gravity {
	Projectile::Projectile(World * world, vector2D<double> initialPosition, vector2D<double> velocity) {
		GraphicComponent *graphicComponent = new SquareGraphicComponent();
		PhysicsComponent *physicsComponent = new SquarePhysicsComponent(initialPosition, velocity, vector2D<double>(20, 100));
		int characterIndex = world->addEntity(physicsComponent, graphicComponent);
		graphicComponent->setWorldConfiguration(characterIndex, world);
		physicsComponent->setWorldConfiguration(characterIndex, world);
	};

};