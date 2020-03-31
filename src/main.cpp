//#include <iostream>

#include "SDL.h"

int main()
{	
  	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window *window = SDL_CreateWindow(
  	  "SDL2Test",
  	  SDL_WINDOWPOS_CENTERED,
  	  SDL_WINDOWPOS_CENTERED,
  	  640,
  	  480,
  	  SDL_WINDOW_SHOWN
  	);

	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
  	SDL_SetRenderDrawColor(renderer, 1, 1, 1, SDL_ALPHA_OPAQUE);
  	SDL_RenderClear(renderer);
  	SDL_RenderPresent(renderer);

	//SDL_Delay(3000);

	bool quit = false;                                      
	SDL_Event e;                                            
	while (!quit) {                                         
	    while (SDL_PollEvent(&e)) {                         
	        if (e.type == SDL_QUIT) {                       
	            quit = true;                                
	        }                                               
	    }                                                   
	}

	SDL_DestroyWindow(window);
  	SDL_Quit();
	//std::cout << "hello from main" << std::endl;
	return 0;
}