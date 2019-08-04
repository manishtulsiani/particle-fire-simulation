#pragma once
namespace pfs {
	class Particle
	{
	public:

		// declaring the x, y pixel co-ordinates as public for sake of efficiency since they will be changed a lot
		// each particle has a polar coordinate, a speed and direction ranging from 0 to 32 pi radians

		double m_x;
		double m_y;
		double m_speed;
		double m_direction;

		
	public:
		Particle();
		virtual ~Particle();		
		void update(int interval);

	private:
		void init();
	};
}

