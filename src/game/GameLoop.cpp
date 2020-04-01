#include "GameLoop.hpp"

namespace
{
	constexpr std::chrono::duration<double> MS_PER_UPDATE {16.0};
}

namespace game
{

void GameLoop::run(SDL_Window* window, SDL_Renderer* renderer)
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
			//update
			lag -= MS_PER_UPDATE;
		}

		//render(lag / MS_PER_UPDATE)
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

}