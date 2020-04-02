#pragma once

#include "SDL_image.h"
#include <string>
#include <map>
#include <memory>

namespace graphics
{

class TextureManager
{
public:
    TextureManager(const TextureManager&) = delete;
	TextureManager& operator=(const TextureManager&) = delete;

    static TextureManager* instance();

	bool load(const std::string& fileName, const std::string& id, SDL_Renderer* renderer);

	void draw(const std::string& id, int x, int y, int width, int height, 
		SDL_Renderer* renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

	void drawFrame(const std::string& id, int x, int y, int width, int height, int currentRow, 
		int currentFrame, SDL_Renderer* renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

private:
	std::map<std::string, SDL_Texture*> textureMap_;
	static TextureManager* instance_;
	TextureManager() = default;
	~TextureManager() = default;
};

}