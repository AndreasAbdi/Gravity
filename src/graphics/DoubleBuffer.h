#pragma once
#include <iostream>
#include "SDL.h"
#include "graphics/Pixel.h"

namespace Gravity {
	class DoubleBuffer {
	private:
		Uint32 * frontBuffer;
		Uint32 * backBuffer;
		int width, height;
	public:
		DoubleBuffer(int inputWidth, int inputHeight);
		DoubleBuffer();
		DoubleBuffer(const DoubleBuffer &source);
		DoubleBuffer& operator=(const DoubleBuffer &source);
		virtual ~DoubleBuffer();

		void swapBuffers();
		void clearFrontBuffer();
		
		void setPixel(Pixel pixel);
		Uint32 * getFrontBuffer() { return frontBuffer; };
	private:
		void duplicateBuffersFrom(const DoubleBuffer &source);
		void copyBuffer(Uint32*& target, Uint32 * const source);
		bool pixelOutsideBorders(Pixel pixel);
	};
}