#include "Filter.h"

namespace Gravity {
	Filter::Filter() {
		for (int i = 0; i < 256 * 9; i++) {
			divisionLookupTable[i] = (i / 9);
		}
	}
	//TODO: Generalize filter class: pull the box blur to a separate child class. 
	//TODO: needs to be faster. split into horizontal and vertical blurs. 
	void Filter::apply(Screen& screen) {

		screen.doubleBuffer.swapBuffers();
		Uint32 * backBuffer = screen.doubleBuffer.getBackBuffer();
		Uint32 * frontBuffer = screen.doubleBuffer.getFrontBuffer();

		Uint32 color;
		int index;
		int rTotal, gTotal, bTotal;
		Uint8 r, g, b;
		for (int x = 0; x < screen.width; x++) {
			for (int y = 0; y < screen.height; y++) {
				rTotal = gTotal = bTotal = 0;

				for (int row = -1; row <= 1; row++) {
					for (int col = -1; col <= 1; col++) {
						index = (col + x) + (row + y)*screen.width;
						if (index < 0 || index >= screen.width*screen.height) {
							continue;
						}
						color = backBuffer[index];
						rTotal += (Uint8)(color >> 24);
						gTotal += (Uint8)(color >> 16);
						bTotal += (Uint8)(color >> 8);
					}
				}
				r = divisionLookupTable[rTotal];
				g = divisionLookupTable[gTotal];
				b = divisionLookupTable[bTotal];
				frontBuffer[x + y*screen.width] = RGB(r,g,b).rgbaRepresentation;
			}
		}	
	}
}