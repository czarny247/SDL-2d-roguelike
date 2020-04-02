#include "RendererRaiiWrapper.hpp"

namespace utils
{

RendererRaiiWrapper::RendererRaiiWrapper(SDL_Window* window, int rendererIndex, uint32_t rendererFlags)
: renderer_(nullptr, 
	[](SDL_Renderer* renderer)
	{
		SDL_RenderClear(renderer); 
		SDL_DestroyRenderer(renderer); 
		renderer = nullptr;
	})
{
	SDL_Renderer *renderer = SDL_CreateRenderer(window, rendererIndex, rendererFlags);

	renderer_.reset(renderer);

	renderer = nullptr;
}

SDL_Renderer* RendererRaiiWrapper::get()
{
	return renderer_.get();
}

void RendererRaiiWrapper::setDrawColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	SDL_SetRenderDrawColor(renderer_.get(), r, g, b, a);
}

void RendererRaiiWrapper::clear()
{
	SDL_RenderClear(renderer_.get());
}

void RendererRaiiWrapper::present()
{
	SDL_RenderPresent(renderer_.get());
}

int RendererRaiiWrapper::copyTexture(SDL_Texture* texture,
	const SDL_Rect* source, const SDL_Rect* destination)
{
	return SDL_RenderCopy(renderer_.get(), texture, source, destination);
}

}