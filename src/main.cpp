#pragma once
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <boost/regex.hpp>
#include "SDL.h"
#include <string>
#include "Screen.h"

static const int SCREEN_HEIGHT = 600;
static const int SCREEN_WIDTH = 800;

void testBoost() {
	std::string line = "Subject: Re: GRAVITY";
	boost::regex pattern("^Subject: (Re: |Aw: )*(.*)$");
	boost::smatch matches;
	if (boost::regex_match(line, matches, pattern)) {
		std::cout << matches[2] << std::endl;
	}
}


int main(int argc, char* args[]) {
	
	Gravity::Screen screen;
	if (screen.initialize() == false) {
		std::cout << "failed to initialize" << std::endl;
		return 1;
	}
	
	while (screen.processEvents()) {
	}
	
	screen.terminate();

	return 0;
}
