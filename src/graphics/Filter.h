#pragma once
#include "SDL.h"
#include "Screen.h"
namespace Gravity {
	class Screen;

	class Filter {
	private:
		int divisionLookupTable[256*9];
	public:
		Filter();
		void apply(Screen& screen);
	};
}
