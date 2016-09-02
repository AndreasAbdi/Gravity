#include "CommandBuilder.h"
namespace Gravity {
	std::function<void()> move(Character &character, vector2D<double> moveVector) {
		return [&character, moveVector]() {
			character.physicsComponent->addToVelocity(moveVector);
		};
	};

	std::vector<Command> CommandBuilder::buildCommands( World& world) {

		std::vector<Command> commands;
		commands.push_back(Command(move(world.player, vector2D<double>(0.01, 0)), SDL_SCANCODE_D));
		commands.push_back(Command(move(world.player, vector2D<double>(-0.01, 0)), SDL_SCANCODE_A));
		commands.push_back(Command(move(world.player, vector2D<double>(0, 0.01)), SDL_SCANCODE_S));
		commands.push_back(Command(move(world.player, vector2D<double>(0, -0.01)), SDL_SCANCODE_W));

		return commands;
	}
}

