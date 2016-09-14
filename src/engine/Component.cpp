#include "engine/Component.h"

namespace Gravity {
	void Component::setWorldConfiguration(int index, World * world) {
		this->index = index;
		this->world = world;
	};

};