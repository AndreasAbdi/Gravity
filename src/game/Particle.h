#pragma once
#include <math.h>
#include <stdlib.h>
#include "utility/vector2D.h"

namespace Gravity {
	struct Particle {
		double x, y;
		vector2D<double> velocity;
		Particle(const double inputX, const double inputY, const double inputSpeedX, const double inputSpeedY) :
			x(inputX), y(inputY), velocity(inputSpeedX, inputSpeedY) {};
		Particle(const double inputX, const double inputY) : Particle(inputX, inputY, 0,0) {};
		Particle() : Particle(0, 0, 0, 0) {};
		void updatePosition(double interval);
		void addToVelocity(vector2D<double> inputVelocity);
		void setVelocity(vector2D<double> inputVelocity);
	};
}