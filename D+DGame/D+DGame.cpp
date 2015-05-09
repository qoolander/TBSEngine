// D+DGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define FPS_INTERVAL 1.0 //seconds.

void KeyboardInputHandler(SDL_Event event);
void Render(SDL_Renderer *renderer);

bool close;

int _tmain(int argc, _TCHAR* argv[])
{

	Uint32 fps_lasttime = SDL_GetTicks(); //the last recorded time.
	Uint32 fps_current; //the current FPS.
	Uint32 fps_frames = 0; //frames passed since the last recorded fps.

	SDL_Window *window;                    // Declare a pointer
	SDL_Renderer *renderer;

	SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2

	// Create an application window with the following settings:
	window = SDL_CreateWindow(
		"An SDL2 window",                             // window title
		SDL_WINDOWPOS_CENTERED,                       // initial x position
		SDL_WINDOWPOS_CENTERED,                       // initial y position
		640,                                          // width, in pixels
		480,                                          // height, in pixels
		SDL_WINDOW_OPENGL							  // flags - see below
		);

	// Check that the window was successfully made
	if (window == NULL) {
		// In the event that the window could not be made...
		printf("Could not create window: %s\n", SDL_GetError());
		return 1;
	}

	renderer = SDL_CreateRenderer(window, -1, 0);
	if (renderer == NULL){
		printf("Could not create renderer: %s\n", SDL_GetError());
		return 1;
	}

	close = false;

	while (!close) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			// handle your event here
			switch (event.type){
			case SDL_MOUSEMOTION:
				printf("We got a motion event.\n");
				printf("Current mouse position is: (%d, %d)\n", event.motion.x, event.motion.y);
				break;
			case SDL_KEYDOWN:
				printf("Key pressed\n");
				KeyboardInputHandler(event);
				break;
			case SDL_QUIT:
				close = true;
				break;
			default:
				printf("Unhandled Event!\n");
				break;
			}
		}
		Render(renderer);




		fps_frames++;
		if (fps_lasttime < SDL_GetTicks() - FPS_INTERVAL * 1000)
		{
			std::cout << fps_frames << "\n";
			fps_lasttime = SDL_GetTicks();
			fps_current = fps_frames;
			fps_frames = 0;
		}

	}
	
	//SDL_Delay(3000);  // Pause execution for 3000 milliseconds, for example

	// Close and destroy the window
	SDL_DestroyWindow(window);

	// Clean up
	SDL_Quit();
	return 0;
}

void KeyboardInputHandler(SDL_Event event){
	switch (event.key.keysym.sym){
	case SDLK_ESCAPE:
		close = true;
		break;
	}
}

void Render(SDL_Renderer *renderer){
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 256);
	SDL_RenderClear(renderer);

}