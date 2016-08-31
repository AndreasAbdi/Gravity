#include "GameLoop.h"

namespace Gravity {
	GameLoop::GameLoop(Configurations configurations) {
		this->configurations = configurations;
	};

	int Gravity::GameLoop::runGameLoop() {
		if (!setupUsingConfigurations()) {
			return 1;
		}
		updateRunTime();

		SquareGraphicComponent * graphicComponent = new SquareGraphicComponent();
		Character character(graphicComponent);

		while (screen.processEvents()) {
			updateRunTime();
			
			auto action = [](int d) -> int {
				return 1;
			};
			character.update(screen);
			screen.update();
		}
		teardown();
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
