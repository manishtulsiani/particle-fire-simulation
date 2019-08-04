#pragma once
namespace pfs {
	class Particle
	{
	public:

		// declaring the x, y pixel co-ordinates as public for sake of efficiency since they will be changed a lot
		double m_x;
		double m_y;
		double xspeed;
		double yspeed;
		
	public:
		Particle();
		virtual ~Particle();
		void update();
	};
}

