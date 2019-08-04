#include "Swarm.h"

namespace pfs {
	Swarm::Swarm()
	{
		m_particles = new Particle[NPARTICLES];
		lastTime = 0;
	}

	Swarm::~Swarm()
	{
		delete[] m_particles;
	}
	void Swarm::update(int elapsed)
	{
		int interval = elapsed - lastTime;
		for (int i = 0; i < NPARTICLES; i++) {
			m_particles[i].update(interval);
		}

		lastTime = elapsed;
	}
}

