#pragma once 
#include <functional>
#include "game/Character.h"
#include "SDL.h"

namespace Gravity {
	struct Command {
	public:
		std::function<void()> action;
		Uint8 keyToInvoke;
		Command(std::function<void()> inputAction, Uint8 inputKeyAction) : action(inputAction), keyToInvoke(inputKeyAction) {};
		
	};
}