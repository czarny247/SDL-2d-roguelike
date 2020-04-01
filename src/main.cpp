#include "SDL.h"
#include "game/GameLoop.hpp"
#include "utils/WindowRaiiWrapper.hpp"
#include "utils/RendererRaiiWrapper.hpp"
#include <memory>
#include <functional>

#include <iostream>

int main()
{	
	SDL_Init(SDL_INIT_VIDEO);

	utils::WindowRaiiWrapper window("SDL_GAME", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);

	utils::RendererRaiiWrapper renderer(window.get(), -1, SDL_RENDERER_SOFTWARE);
	renderer.setDrawColor(0, 0, 0, SDL_ALPHA_OPAQUE);
	renderer.clear();
	renderer.present();

	game::GameLoop mainLoop;
	mainLoop.run(window.get(), renderer.get());

	SDL_Quit();
	return 0;
}
