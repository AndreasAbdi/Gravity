#pragma once
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

#include <boost/regex.hpp>

#include "SDL.h"

#include "game/ParticleCollection.h"
#include "graphics/Filter.h"
#include "graphics/Screen.h"
#include "graphics/Pixel.h"
#include "graphics/PositionConversion.h"
#include "utility/vector2D.h"

//TODO: get the boost ini parse and shove configs in an ini. 
static const int SCREEN_HEIGHT = 768;
static const int SCREEN_WIDTH = 1024;
static constexpr const char * SCREEN_NAME = "GRAVITY";
static const int PARTICLE_NUMBER = 5000;
void testBoost() {
	std::string line = "Subject: Re: GRAVITY";
	boost::regex pattern("^Subject: (Re: |Aw: )*(.*)$");
	boost::smatch matches;
	if (boost::regex_match(line, matches, pattern)) {
		std::cout << matches[2] << std::endl;
	}
}

void rainbow( Gravity::Screen &screen) {
	int timeElapsed = SDL_GetTicks();
	//shift from [-1,1] to [0,2) to [0,256);
	Uint8 r = (Uint8)((1 + sin(timeElapsed*0.001)) * 128);
	Uint8 g = (Uint8)((1 + sin(timeElapsed*0.002)) * 128);
	Uint8 b = (Uint8)((1 + sin(timeElapsed*0.003)) * 128);

	for (int x = 0; x < SCREEN_WIDTH; x++) {
		for (int y = 0; y < SCREEN_HEIGHT; y++) {
			screen.setPixel(Gravity::Pixel(Gravity::RGB(r, g, b), Gravity::Point(x, y)));
		}
	}
}

void setupExplosion(Gravity::ParticleCollection &particleCollection) {
	Gravity::Particle * const particles = particleCollection.getParticles();
	for (int i = 0; i < particleCollection.getSize(); i++) {
		double direction = (2 * M_PI*rand()) / RAND_MAX;
		double speed = 0.0002*(1.0*rand()) / RAND_MAX;
		double x = speed * cos(direction);
		double y = speed * sin(direction);
		vector2D<double> newVelocity(x, y);
		particles[i].setVelocity(newVelocity);
	}

}
void starScreen(Gravity::Screen &screen, Gravity::ParticleCollection &collection, int timeElapsed, int currentTime) {
	Gravity::Particle * const particles = collection.getParticles();
	collection.update(timeElapsed);
	for (int i = 0; i < collection.getSize(); i++) {
		Gravity::Point particleScreenCoordinates = Gravity::cartesianToScreenCoordinates(Gravity::Point(particles[i].x, particles[i].y), screen.getSize());
		//shift from [-1,1] to [0,2) to [0,256);
		Uint8 r = (Uint8)((1 + sin(currentTime*0.001)) * 128);
		Uint8 g = (Uint8)((1 + sin(currentTime*0.002)) * 128);
		Uint8 b = (Uint8)((1 + sin(currentTime*0.003)) * 128);
		screen.setPixel(Gravity::Pixel(Gravity::RGB(r, g, b), particleScreenCoordinates));

	}
}	

//TODO: Consider converting loop into a class. 
int runMainLoop() {
	srand(time(NULL));

	Gravity::Screen screen(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_NAME);
	if (screen.initialize() == false) {
		std::cout << "failed to initialize" << std::endl;
		return 1;
	}

	Gravity::ParticleCollection particleCollection(PARTICLE_NUMBER);
	setupExplosion(particleCollection);
	Gravity::Filter filter;
	int previousTime = SDL_GetTicks();
	while (screen.processEvents()) {
		//screen.clear();
		int currentTime = SDL_GetTicks();
		int timeElapsed(currentTime - previousTime);
		previousTime = currentTime;
		filter.apply(screen);
		starScreen(screen, particleCollection, timeElapsed, currentTime);
		screen.update();
	}

	screen.terminate();
	return 0;
}

int main(int argc, char* args[]) {
	return runMainLoop();
}
