#pragma once

namespace Gravity {
	class World;

	class Component {
	public:
		int index;
		World * world;
		virtual ~Component() {};
		void setWorldConfiguration(int index, World * world);
	};
}