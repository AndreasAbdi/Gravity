#pragma once
#include "SDL.h"
#include "Screen.h"
namespace Gravity {
	class Screen;

	class Filter {
	public:
		void apply(Screen& screen);
	};
}
