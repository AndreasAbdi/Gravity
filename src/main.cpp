#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <boost/regex.hpp>
#include "SDL.h"
#include <string>
 
int main(int argc, char* args[]) {
	std::string line = "Subject: Re: GRAVITY";
	boost::regex pattern("^Subject: (Re: |Aw: )*(.*)$");
	boost::smatch matches;
	if (boost::regex_match(line, matches, pattern)) {
		std::cout << matches[2] << std::endl;
	}

	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Quit();
    return 0;
}
