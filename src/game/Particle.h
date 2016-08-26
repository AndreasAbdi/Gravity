#pragma once
#include <math.h>
#include <stdlib.h>
namespace Gravity {
	struct Particle {
		double x, y;
		Particle(double inputX, double inputY) : x(inputX), y(inputY) {};
		Particle();
	};
}