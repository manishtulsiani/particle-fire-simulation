#pragma once
#include "Particle.h"
namespace pfs {
	class Swarm
	{
	public :
		static const int NPARTICLES = 5000;

	private:
		Particle* m_particles;

	public:
		Swarm();
		~Swarm();
		const Particle* const getParticles() { return m_particles; }
	};
}

