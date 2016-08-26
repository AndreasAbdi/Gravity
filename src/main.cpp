#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <boost/regex.hpp>
#include "SDL.h"
#include <string>
 
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

void testSDL() {

}

int main(int argc, char* args[]) {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "SDL INIT FAILED" << std::endl;
		return 1;
	}

	SDL_Window *mainWindow = SDL_CreateWindow("GRAVITY",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if (mainWindow == NULL) {
		SDL_Quit();
		return 2;
	}

	SDL_Renderer *renderer = SDL_CreateRenderer(mainWindow, -1, SDL_RENDERER_PRESENTVSYNC);
	SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888,
		SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

	if (renderer == NULL) {
		std::cout << "Could not create renderer" << std::endl;
		SDL_DestroyWindow(mainWindow);
		SDL_Quit();
		return 3;
	}

	if(texture == NULL) {
		std::cout << "Could not create renderer" << std::endl;
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(mainWindow);
		SDL_Quit();
		return 4;
	}

	Uint32 *buffer = new Uint32[SCREEN_WIDTH*SCREEN_HEIGHT];
	memset(buffer, 0xAA, SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32));

	SDL_UpdateTexture(texture, NULL, buffer, SCREEN_WIDTH*sizeof(Uint32));
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);


	SDL_Event event;	
	bool quit = false;
	while (!quit) {
		//update particles
		//draw particles
		//check for messages and events. 
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				quit = true;
			}
		}
	}

	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(mainWindow);
	//std::cout << "SDL INIT SUCCEEDED" << std::endl;
	SDL_Quit();

    return 0;
}
