#include "Particle.h"

namespace Gravity {

	void Particle::updatePosition(double timeElapsed) {
		x += velocity.x*timeElapsed;
		y += velocity.y*timeElapsed;

		if (x >= 1.0 || x <= -1.0) {
			velocity.x *= -1;
			x += velocity.x*timeElapsed;
		}

		if (y >= 1.0 || y <= -1.0) {
			velocity.y *= -1;
			y += velocity.y*timeElapsed;
		}
	}

	void Particle::addToVelocity(vector2D<double> inputVelocity) {
		this->velocity += inputVelocity;
	}

	void Particle::setVelocity(vector2D<double> inputVelocity) {
		this->velocity = inputVelocity;
	}

}

