#include "CommandBuilder.h"
namespace Gravity {
	std::function<void()> move(Player * player, vector2D<double> moveVector) {
		return [player, moveVector]() {
			player->world->physicsComponents[player->index]->moveBy(moveVector);
		};
	};

	std::function<void()> shoot(Player * player) {
		return [player]() {
			player->shootProjectile();
		};
	};

	std::vector<Command> CommandBuilder::buildCommands(Game& game) {

		std::vector<Command> commands;
		commands.push_back(Command(move(game.player, vector2D<double>(1, 0)), SDL_SCANCODE_D));
		commands.push_back(Command(move(game.player, vector2D<double>(-1, 0)), SDL_SCANCODE_A));
		commands.push_back(Command(move(game.player, vector2D<double>(0, 1)), SDL_SCANCODE_S));
		commands.push_back(Command(move(game.player, vector2D<double>(0, -1)), SDL_SCANCODE_W));
		commands.push_back(Command(shoot(game.player),SDL_SCANCODE_SPACE));

		return commands;
	}
}

