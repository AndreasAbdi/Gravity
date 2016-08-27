#include "Filter.h"

namespace Gravity {
	//TODO: Generalize filter class: pull the box blur to a separate child class. 
	void Filter::apply(Screen& screen) {
		//apply box blur on the thing for testing. 
		screen.doubleBuffer.swapBuffers();
		
		for (int x = 0; x < screen.width; x++) {
			for (int y = 0; y < screen.height; y++) {

				int rgbAverages[3] = { 0 };

				for (int row = -1; row <= 1; row++) {
					for (int col = -1; col <= 1; col++) {
						int currentRow = row + y;
						int currentCol = col + x;
						int index = currentCol + currentRow*screen.width;
						if (index < 0 || index >= screen.width*screen.height) {
							continue;
						}
						Uint32 * buffer = screen.doubleBuffer.getFrontBuffer();
						Uint32 color = buffer[index];
						for (int colorIndex = 0; colorIndex < 3; colorIndex++) {
							//right shift for the specific R, G, or B values. 
							rgbAverages[colorIndex] += (Uint8)(color >> (24 - (colorIndex * 8)));
						}
					}
				}

				Uint8 rgbs[3];
				for (int color = 0; color < 3; color++) {
					rgbs[color] = rgbAverages[color] / 9;
				}

				screen.setPixel(Pixel(RGB(rgbs[0], rgbs[1], rgbs[2]), Point(x, y)));
			}
		}	
	}
}