#pragma once
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <boost/regex.hpp>
#include "SDL.h"
#include <string>
#include "graphics/Screen.h"
#include "graphics/Pixel.h"
//TODO: get the boost ini parse and shove configs in an ini. 
static const int SCREEN_HEIGHT = 768;
static const int SCREEN_WIDTH = 1024;
static constexpr const char * SCREEN_NAME = "GRAVITY";

void testBoost() {
	std::string line = "Subject: Re: GRAVITY";
	boost::regex pattern("^Subject: (Re: |Aw: )*(.*)$");
	boost::smatch matches;
	if (boost::regex_match(line, matches, pattern)) {
		std::cout << matches[2] << std::endl;
	}
}

//TODO: Consider converting loop into a class. 
int runMainLoop() {
	Gravity::Screen screen(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_NAME);
	if (screen.initialize() == false) {
		std::cout << "failed to initialize" << std::endl;
		return 1;
	}
	
	for (int x = 0; x < SCREEN_WIDTH; x++) {
		for (int y = 0; y < SCREEN_HEIGHT; y++) {
			screen.setPixel(Gravity::Pixel(Gravity::RGB(255, 255, 0), Gravity::Point(x, y)));
		}
	}

	screen.update();
	
	while (screen.processEvents()) {
	}

	screen.terminate();
	return 0;
}

int main(int argc, char* args[]) {
	return runMainLoop();
}
