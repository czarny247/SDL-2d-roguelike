#pragma once

#include "SDL.h"
#include "graphics/TextureManager.hpp"
#include "utils/RendererRaiiWrapper.hpp"
#include "utils/WindowRaiiWrapper.hpp"
#include <chrono>

namespace game
{

class GameLoop
{

public:
	GameLoop(utils::WindowRaiiWrapper&& window, utils::RendererRaiiWrapper&& renderer);
	~GameLoop();
	GameLoop(GameLoop& gl) = delete;
	//GameLoop(GameLoop&& gl)

	void run();

private:
	SDL_Event event_ {};
	//graphics::TextureManager textureManager_ {};
	int currentFrame_ {0};

	//SDL_Window* window_;
	//SDL_Renderer* renderer_;

	utils::RendererRaiiWrapper renderer_;
	utils::WindowRaiiWrapper window_;

	void processInput(bool& isQuitEvent);
	void render(double movementSpeedFactor);
	void update();
};

}