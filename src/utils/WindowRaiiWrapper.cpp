#include "WindowRaiiWrapper.hpp"

namespace utils
{

WindowRaiiWrapper::WindowRaiiWrapper(const char* windowTitle, int xPos, int yPos, 
	int width, int height, uint32_t flags)
: window_(nullptr, 
	[](SDL_Window* window){SDL_DestroyWindow(window); window = nullptr;})
{
	SDL_Window *window = SDL_CreateWindow(windowTitle, xPos, yPos,
		width, height, flags);

	window_.reset(window);

	window = nullptr;
}

SDL_Window* WindowRaiiWrapper::get()
{
	return window_.get();
}

}