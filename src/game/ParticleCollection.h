#pragma once
#include "Particle.h"

namespace Gravity {
	class ParticleCollection {
	public:
		static const int DEFAULT_SIZE = 5000;
	private:
		Particle * particles;
		int size;
	public:
		ParticleCollection(const int size);
		ParticleCollection() : ParticleCollection(DEFAULT_SIZE) {};
		virtual ~ParticleCollection();
		void update(double timeElapsed);
		Particle * const getParticles() { return particles; };
		int getSize() { return size; };
	};
}