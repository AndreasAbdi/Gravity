#include "ParticleCollection.h"
namespace Gravity {
	ParticleCollection::ParticleCollection(const int size) {
		particles = new Particle[size];
		this->size = size;
	}


	ParticleCollection::~ParticleCollection() {
		delete[] particles;
	}
}

