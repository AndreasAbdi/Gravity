#include "game/SquareGraphicComponent.h"

namespace Gravity {
	void SquareGraphicComponent::update(const Character &character, Screen &screen) {
		SDL_Renderer * renderer = screen.getRenderer();
		SDL_Rect r;
		r.x = character.getPosition().x;
		r.y = character.getPosition().y;
		r.w = character.getSize().x;
		r.h = character.getSize().y;

		// Set render color to blue ( rect will be rendered in this color )
		SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
		// Render rect
		SDL_RenderFillRect(renderer, &r);
	};
};