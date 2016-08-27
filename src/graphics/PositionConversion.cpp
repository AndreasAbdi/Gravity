#include "PositionConversion.h"

namespace Gravity {
	Point cartesianToScreenCoordinates(const Point &cartesianPosition, const Point &screenSize){
		int x = (cartesianPosition.x + 1) * screenSize.x / 2;
		int y = cartesianPosition.y * screenSize.x / 2 + screenSize.y/2;
		return Point(x,y);
	}

}
