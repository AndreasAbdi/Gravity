#include "DoubleBuffer.h"

namespace Gravity {
	DoubleBuffer::DoubleBuffer(int inputWidth, int inputHeight) :width(inputWidth), height(inputHeight), frontBuffer(NULL) {
		frontBuffer = new Uint32[width*height];
		backBuffer = new Uint32[width*height];
		memset(frontBuffer, 0, sizeof(Uint32)*width*height);
		memset(backBuffer, 0, sizeof(Uint32)*width*height);

	};

	DoubleBuffer::DoubleBuffer() {
		frontBuffer = NULL;
		width = 0;
		height = 0;
	};

	DoubleBuffer::DoubleBuffer(const DoubleBuffer& source) : width(source.width), height(source.width) {
		duplicateBuffersFrom(source);
	};

	DoubleBuffer& DoubleBuffer::operator=(const DoubleBuffer& source) {
		height = source.height;
		width = source.width;
		duplicateBuffersFrom(source);
		return *this;
	}

	DoubleBuffer::~DoubleBuffer() {
		delete[] frontBuffer;
		delete[] backBuffer;
	}
	
	void DoubleBuffer::swapBuffers() {
		Uint32 * temporaryBuffer = frontBuffer;
		frontBuffer = backBuffer;
		backBuffer = frontBuffer;
	}

	
	void DoubleBuffer::clearFrontBuffer() {
		memset(frontBuffer, 0, height*width*sizeof(Uint32));
	}

	void DoubleBuffer::setPixel(Pixel pixel) {
		if (pixelOutsideBorders(pixel)) {
			return;
		}

		int position = pixel.point.y*width + pixel.point.x;
		frontBuffer[position] = pixel.rgb.rgbaRepresentation;
	}

	void DoubleBuffer::duplicateBuffersFrom(const DoubleBuffer & source) {
		copyBuffer(frontBuffer, source.frontBuffer);
		copyBuffer(backBuffer, source.backBuffer);
	}


	void DoubleBuffer::copyBuffer(Uint32*& target, Uint32 * const source) {
		target = new Uint32[width*height];
		for (int x = 0; x < width; x++) {
			for (int y = 0; y < height; y++) {
				int index = x + y*width;
				target[index] = source[index];
			}
		}
	}

	bool DoubleBuffer::pixelOutsideBorders(Pixel pixel) {
		return (pixel.point.x < 0 || pixel.point.x >= width || pixel.point.y < 0 || pixel.point.y >= height);
	}

}
