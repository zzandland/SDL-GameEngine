#pragma once

#include "Game.hpp"

class TextureManager {
 public:
  TextureManager() = delete;
  ~TextureManager() = delete;
  static SDL_Texture *loadTexture(SDL_Renderer *renderer, const char *fileName);
};