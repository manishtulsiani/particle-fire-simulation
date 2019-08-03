#include <iostream>
#include "SDL.h"

using namespace std;

int main(int argc, char* argv[])
{
	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;
	
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		cout << "SDL init failed." << endl;
		return 1;
	}

	SDL_Window* window = SDL_CreateWindow
	("Particle Fire Explosion", // window's title
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, // coordinates on the screen, in pixels, of the window's upper left corner
		SCREEN_WIDTH, SCREEN_HEIGHT, // window's length and height in pixels  
		SDL_WINDOW_SHOWN);

	if (window == NULL) {
		cout << "Error when creating window: " << SDL_GetError() << endl;
		SDL_Quit();
		return 2;
	}

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
	// SDL_RENDERER_PRESENTVSYNC syncs the rendering with screen refreshing

	if (renderer == NULL) {
		cout << "Renderer not created." << endl;
		return 3;
	}

	// Texture
	SDL_Texture* texturer = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, 
									SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

	// Each pixel is 4 bytes: RGBA - RGB is red, green, blue, a is alpha for transparency
	// so each pixel is 32 bits
	// total memory for all the pixels for the screen

	Uint32* buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];

	// set the buffer to black colour
	memset(buffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

	for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; ++i) {
		buffer[i] = 0xFFFFFFFF; 
	}

	SDL_UpdateTexture(texturer, NULL, buffer, SCREEN_WIDTH * sizeof(Uint32));

	if (texturer == NULL) {
		cout << "Texturer not created" << endl;
	}
	
	// Clear the renderer
	SDL_RenderClear(renderer);

	// copy the texturer to the renderer
	SDL_RenderCopy(renderer, texturer, NULL, NULL);

	// Up until now everything was drawn behind the scenes.
	// This will render it to the screen
	SDL_RenderPresent(renderer);

	bool quit = false;
	SDL_Event event;

	// main while event loop
	while (!quit) {

		// update particles, draw particles, check for user events

		// poll for events
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				quit = true;
			}
		}
	}

	delete [] buffer;
	//SDL_Delay(3000); // window lasts 3 seconds
	SDL_DestroyTexture(texturer);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}