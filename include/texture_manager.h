#pragma once

#include "game.h"

class TextureManager {
 public:
  TextureManager() = delete;
  ~TextureManager() = delete;
  static SDL_Texture *Load(const char *fileName);
  static void Draw(SDL_Texture *texture, SDL_Rect srcRect, SDL_Rect destRect);
};
