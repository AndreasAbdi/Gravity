#include "ParticleCollection.h"
namespace Gravity {
	ParticleCollection::ParticleCollection(const int size) {
		particles = new Particle[size];
		this->size = size;
	}

	void ParticleCollection::update(double timeElapsed) {
		for (int particleIndex = 0; particleIndex < size; particleIndex++) {
			particles[particleIndex].updatePosition(timeElapsed);
		}
	}

	ParticleCollection::~ParticleCollection() {
		delete[] particles;
	}
}

