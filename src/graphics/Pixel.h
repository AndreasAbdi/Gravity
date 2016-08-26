#pragma once
#include "Point.h"
#include "RGB.h"
namespace Gravity {
	struct Pixel {
		RGB rgb;
		Point point;
		Pixel(const RGB inputRGB, const Point inputPoint) : rgb(inputRGB), point(inputPoint) {}
	};
}