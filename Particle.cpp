#include "Particle.h"
#include <stdlib.h>

namespace pfs {
	Particle::Particle()
	{
		// define a space in cartesian co-ordinates from -1,-1 to +1,+1
		m_x = ((2.0 * rand()) / RAND_MAX) - 1;
		m_y = ((2.0 * rand()) / RAND_MAX) - 1;

		xspeed = 0.001 * ((2.0 * rand()) / RAND_MAX - 1); // get a random number from -1 to +1
		yspeed = 0.001 * ((2.0 * rand()) / RAND_MAX - 1); // get a random number from -1 to +1
	}

	Particle::~Particle()
	{
	}
	void Particle::update()
	{
		m_x += xspeed;
		m_y += yspeed;

		// don't move outside the screen edge

		if (m_x <= -1.0 || m_x >= 1.0) {
			xspeed = -xspeed;
		}

		if (m_y <= -1.0 || m_y >= 1.0) {
			yspeed = -yspeed;
		}
	}
}
