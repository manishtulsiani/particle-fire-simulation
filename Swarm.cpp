#include "Swarm.h"

namespace pfs {
	Swarm::Swarm()
	{
		m_particles = new Particle[NPARTICLES];
	}

	Swarm::~Swarm()
	{
		delete[] m_particles;
	}
}

