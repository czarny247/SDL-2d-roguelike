#pragma once

#include "SDL.h"
#include "graphics/TextureManager.hpp"
#include <chrono>

namespace game
{

class GameLoop
{

public:
	GameLoop(SDL_Window* window, SDL_Renderer* renderer);
	~GameLoop();
	GameLoop(GameLoop& gl) = delete;
	//GameLoop(GameLoop&& gl)

	void run();

private:
	SDL_Event event_ {};
	graphics::TextureManager textureManager_ {};
	int currentFrame_ {0};

	SDL_Window* window_;
	SDL_Renderer* renderer_;

	void processInput(bool& isQuitEvent);
	void render(double movementSpeedFactor);
	void update();
};

}