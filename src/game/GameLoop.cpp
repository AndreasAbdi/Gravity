#include "GameLoop.h"

namespace Gravity {
	GameLoop::GameLoop(Configurations configurations) {
		this->configurations = configurations;
	};
	std::function<void()> move(Character &character, vector2D<double> moveVector) {
		return [&character, moveVector]() {
			character.physicsComponent->moveBy(moveVector);
		};
	};

	int Gravity::GameLoop::runGameLoop() {
		if (!setupUsingConfigurations()) {
			return 1;
		}
		updateRunTime();

		//TESTING
		InputManager inputManager;
		std::vector<Command> commands;
		SquareGraphicComponent * graphicComponent = new SquareGraphicComponent();
		SquarePhysicsComponent * physicsComponent = new SquarePhysicsComponent(vector2D<double>(300, 300), vector2D<double>(0,0), vector2D<double>(50, 50));
		Character character(graphicComponent, physicsComponent);
		Command toTheRight(move(character, vector2D<double>(0, 1)), SDLK_d);
		commands.push_back(Command(move(character, vector2D<double>(1, 0)),SDL_SCANCODE_D));
		commands.push_back(Command(move(character, vector2D<double>(-1, 0)), SDL_SCANCODE_A));
		commands.push_back(Command(move(character, vector2D<double>(0, 1)), SDL_SCANCODE_S));
		commands.push_back(Command(move(character, vector2D<double>(0, -1)), SDL_SCANCODE_W));
		inputManager.setCommands(commands);
		//TESTING

		while (screen.processEvents()) {
			updateRunTime();
			screen.clear();
			inputManager.handleInput();
			character.update(screen);
			screen.update();
		}
		teardown();
		delete graphicComponent;
		return 0;
	}

	void GameLoop::updateRunTime() {
		double currentTime = SDL_GetTicks();
		timeElapsedSinceLastUpdate = currentTime - lastUpdatedTime;
		lastUpdatedTime = currentTime;
	}

	bool GameLoop::teardown() {
		screen.terminate();
		SDL::terminate();
		return true;
	}

	bool GameLoop::setupUsingConfigurations() {
		srand(time(NULL));

		int screenWidth, screenHeight;
		std::string screenName;
		if (!setupVariablesUsingConfigs(screenWidth, screenHeight, screenName)) {
			return false;
		}

		SDL::initialize();

		if (screen.initialize(screenWidth, screenHeight, screenName.c_str()) == false) {
			SDL::terminate();
			return false;
		}

		screen.clear();
		return true;
	}

	bool GameLoop::setupVariablesUsingConfigs(int &screenWidth, int &screenHeight, std::string &screenName) {
		bool ableToGetConfigs = true;
		ableToGetConfigs = ableToGetConfigs && configurations.getValue<int>("SCREEN_WIDTH", screenWidth);
		ableToGetConfigs = ableToGetConfigs && configurations.getValue<int>("SCREEN_HEIGHT", screenHeight);
		ableToGetConfigs = ableToGetConfigs && configurations.getValue<std::string>("SCREEN_NAME", screenName);

		return ableToGetConfigs;
	}

}
