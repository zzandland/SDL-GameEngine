#pragma once

#include "Game.hpp"

class TextureManager {
 public:
  TextureManager() = delete;
  ~TextureManager() = delete;
  static SDL_Texture *loadTexture(const char *fileName);
};