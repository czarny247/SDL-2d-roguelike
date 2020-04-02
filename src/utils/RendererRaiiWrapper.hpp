#pragma once

#include "SDL.h"

#include <memory>
#include <cstdint>
#include <functional>

namespace utils
{

class RendererRaiiWrapper
{

public:
	using RendererPtr = 
		std::unique_ptr<SDL_Renderer, std::function<void(SDL_Renderer*)>>;

	RendererRaiiWrapper(SDL_Window* window, int rendererIndex, uint32_t rendererFlags);

	RendererRaiiWrapper(RendererRaiiWrapper&& other);

	RendererRaiiWrapper& operator=(RendererRaiiWrapper&& other);

	~RendererRaiiWrapper() = default;

	SDL_Renderer* get();

	void setDrawColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
	void clear();
	void present();

	int copyTexture(SDL_Texture* texture, const SDL_Rect* source, const SDL_Rect* destination);

private:
	RendererPtr renderer_;
};

}