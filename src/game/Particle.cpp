#include "Particle.h"

namespace Gravity {
	Particle::Particle() {
		//cartesian coordinate generation. 
		x = ((2.0*rand()) / RAND_MAX) - 1;
		y = ((2.0*rand()) / RAND_MAX) - 1;
	}

}

