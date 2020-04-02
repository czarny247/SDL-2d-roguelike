#include "GameLoop.hpp"

namespace
{
	constexpr std::chrono::duration<double> MS_PER_UPDATE {16.0};
}

namespace game
{

GameLoop::GameLoop(utils::WindowRaiiWrapper&& window, utils::RendererRaiiWrapper&& renderer)
: window_(std::move(window))
, renderer_(std::move(renderer))
{
	graphics::TextureManager::instance()->load("../res/rogue.png", "rogue", renderer_.get());
}

GameLoop::~GameLoop()
{
}

void GameLoop::run()
{
	auto previousTime = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> lag {0.0};

	bool isQuitEvent = false;
	while (!isQuitEvent) 
	{
		auto currentTime = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> elapsedTime = currentTime - previousTime;
		lag += elapsedTime;
		processInput(isQuitEvent);

		while(lag >= MS_PER_UPDATE)
		{
			//update();
			lag -= MS_PER_UPDATE;
		}

		//render(lag / MS_PER_UPDATE)
		//render(lag.count() / MS_PER_UPDATE.count());
	}
}

void GameLoop::processInput(bool& isQuitEvent)
{
	while (SDL_PollEvent(&event_))
	{
		if (event_.type == SDL_QUIT)
		{
			isQuitEvent = true;
		}
	}
}

void GameLoop::render(double movementSpeedFactor)
{
	SDL_RenderClear(renderer_.get());
	graphics::TextureManager::instance()->draw("rogue", 0,0, 128, 82, renderer_.get());
	graphics::TextureManager::instance()->drawFrame("rogue", 
		100*movementSpeedFactor, 100*movementSpeedFactor, 128, 82, 1, currentFrame_, renderer_.get());
    SDL_RenderPresent(renderer_.get());
}

void GameLoop::update()
{
	currentFrame_ = int(((SDL_GetTicks() / 100) % 6));
}

}
