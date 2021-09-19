#pragma once

#include "Game.hpp"

class TextureManager {
 public:
  TextureManager() = delete;
  ~TextureManager() = delete;
  static SDL_Texture *load(const char *fileName);
  static void draw(SDL_Texture *texture, SDL_Rect srcRect, SDL_Rect destRect);
};
