#pragma once
#include "Point.h"

namespace Gravity {
	Point cartesianToScreenCoordinates(const Point &cartesianPosition, const Point &ScreenSize);
}