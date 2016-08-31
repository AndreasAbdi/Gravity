#include "game/SquareGraphicComponent.h"

namespace Gravity {
	void SquareGraphicComponent::update(const Character &character, Screen &screen) {
		SDL_Renderer * renderer = screen.getRenderer();
		// Creat a rect at pos ( 50, 50 ) that's 50 pixels wide and 50 pixels high.
		SDL_Rect r;
		r.x = 50;
		r.y = 50;
		r.w = 50;
		r.h = 50;

		// Set render color to blue ( rect will be rendered in this color )
		SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
		// Render rect
		SDL_RenderFillRect(renderer, &r);
	};
};