#pragma once 
#include <iostream>
#include <time.h>
#include <string>

#include "SDL.h"

#include "graphics/Screen.h"
#include "sdl/SDLWrapper.h"
#include "utility/Configurations.h"
#include "graphics/Screen.h"
#include "game/Character.h"
#include "game/SquareGraphicComponent.h"
#include "game/InputManager.h"
#include "game/Command.h"
namespace Gravity {

	class GameLoop {
	private:
		Screen screen;
		Configurations configurations;
		double lastUpdatedTime;
		double timeElapsedSinceLastUpdate;
	public:
		GameLoop(Configurations inputConfigurations);
		int runGameLoop();
	private:
		void updateRunTime();
		bool setupUsingConfigurations();
		bool setupVariablesUsingConfigs(int &screenWidth, int &screenHeight, std::string &screenName);
		bool teardown();
	};

}