#include "game/SquareGraphicComponent.h"

namespace Gravity {
	void SquareGraphicComponent::update(const Character &character, const PhysicsComponent &physicsComponent, Screen &screen) {
		SDL_Renderer * renderer = screen.getRenderer();
		SDL_Rect r;
		r.x = physicsComponent.position.x;
		r.y = physicsComponent.position.y;
		r.w = physicsComponent.size.x;
		r.h = physicsComponent.size.y;

		// Set render color to blue ( rect will be rendered in this color )
		SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
		// Render rect
		SDL_RenderFillRect(renderer, &r);
	};
};