#pragma once
#include "game/GameLoop.h"
#include "utility/Configurations.h"

//Throwaway whenever. 
/* Screwing around
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
		double speed = 0.02*(1.0*rand()) / RAND_MAX;
		speed *= speed;
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
*/


int main(int argc, char* args[]) {
	Gravity::Configurations configurations;
	configurations.addConfig("SCREEN_HEIGHT", (768));
	configurations.addConfig("SCREEN_WIDTH", (1024));
	configurations.addConfig("SCREEN_NAME", std::string("GRAVITY"));
	configurations.addConfig("SCREEN_PARTICLE", (5000));

	Gravity::GameLoop gameLoop(configurations);
	return gameLoop.runGameLoop();
}
