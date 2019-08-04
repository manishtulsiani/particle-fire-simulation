#include "Particle.h"
#include <stdlib.h>

namespace pfs {
	Particle::Particle()
	{
		// define a space in cartesian co-ordinates from -1,-1 to +1,+1
		m_x = ((2.0 * rand()) / RAND_MAX) - 1;
		m_y = ((2.0 * rand()) / RAND_MAX) - 1;
	}

	Particle::~Particle()
	{
	}
}
