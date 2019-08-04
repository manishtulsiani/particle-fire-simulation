#include "Particle.h"
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>


namespace pfs {
	Particle::Particle(): m_x(0), m_y(0)
	{
		init();
	}

	Particle::~Particle()
	{
	}

	void Particle::init() {

		m_direction = (2 * M_PI * rand()) / RAND_MAX; // direction is the angle
		m_speed = (0.04 * rand()) / RAND_MAX;

		m_speed *= m_speed;
	}

	void Particle::update(int interval)
	{
		// curl the direction of the particles

		m_direction += interval * 0.0003;

		double xspeed = m_speed * cos(m_direction);
		double yspeed = m_speed * sin(m_direction);

		// multiplying by the time interval between consecutive for loops ensures the speed of movement is consistent
		m_x += xspeed * interval;
		m_y += yspeed * interval;

		// particle going out of screen
		if (m_x < -1 || m_x > 1 || m_y < -1 || m_y > 1) {
			init();
		}

		// randomly initialize the particles once in 100 times
		if (rand() / RAND_MAX < 100) {
			init();
		}
	}
}
