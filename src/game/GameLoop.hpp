#pragma once

#include "SDL.h"
#include <chrono>

namespace game
{

class GameLoop
{

public:
	GameLoop() = default;
	~GameLoop() = default;	
	GameLoop(GameLoop& gl) = delete;
	//GameLoop(GameLoop&& gl)

	void run(SDL_Window* window, SDL_Renderer* renderer);

private:
	SDL_Event event_;

	void processInput(bool& isQuitEvent);
};

}