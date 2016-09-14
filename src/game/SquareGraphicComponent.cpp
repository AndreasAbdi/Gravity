#include "game/SquareGraphicComponent.h"

namespace Gravity {
	void SquareGraphicComponent::update(Screen &screen) {
		SDL_Renderer * renderer = screen.getRenderer();
		SDL_Rect r;
		SquarePhysicsComponent * physicsComponent = dynamic_cast<SquarePhysicsComponent*>(world->physicsComponents[index]);
		r.x = (int)physicsComponent->position.x;
		r.y = (int)physicsComponent->position.y;
		r.w = (int)physicsComponent->size.x;
		r.h = (int)physicsComponent->size.y;

		// Set render color to blue ( rect will be rendered in this color )
		SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
		// Render rect
		SDL_RenderFillRect(renderer, &r);
	};
};