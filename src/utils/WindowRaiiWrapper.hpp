#pragma once

#include "SDL.h"

#include <cstdint>
#include <memory>
#include <functional>

namespace utils
{

class WindowRaiiWrapper
{

public:
	using WindowPtr = 
		std::unique_ptr<SDL_Window, std::function<void(SDL_Window*)>>;

	WindowRaiiWrapper(const char* windowTitle, int xPos, int yPos,
		int width, int height, uint32_t flags);

	~WindowRaiiWrapper() = default;

	//todo apply rule of 5

	SDL_Window* get();

private:
	WindowPtr window_;

};

}