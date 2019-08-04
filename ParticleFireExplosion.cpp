#include <iostream>
#include <math.h>
#include "Screen.h"
#include <time.h>
#include "Swarm.h"

using namespace pfs;
using namespace std;

int main(int argc, char* argv[])
{
	srand(time(NULL));

	Screen screen;
	Swarm swarm;

	if (!screen.init()) {
		cout << "Error initialising SDL." << endl;
		terminate();
	}

	while (true) {
		
		// Draw particles

		int elapsed = SDL_GetTicks();
		unsigned char green = (unsigned char)((1 + sin(elapsed * 0.0001)) * 128);
		unsigned char red = (unsigned char)((1 + sin(elapsed * 0.0002)) * 128);
		unsigned char blue = (unsigned char)((1 + sin(elapsed * 0.0003)) * 128);		

		const Particle* const particles = swarm.getParticles();

		for (int i = 0; i < Swarm::NPARTICLES; i++) {
			Particle particle = particles[i];
			
			// each particle is intialized in -1,-1 to +1,+1. add +1 to make it positive and multiply by half of width or height to map
			// the particle co-ordinate to screen co-ordinate

			int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH / 2;
			int y = (particle.m_y + 1) * Screen::SCREEN_HEIGHT / 2;
			screen.setPixel(x, y, red, green, blue);

		}

		// update the screen
		screen.updateScreen();

		// Check for messages/events
		if (!screen.processEvents()) {
			break;
		}
	}

	screen.close();
	return 0;
}