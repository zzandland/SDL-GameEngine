#pragma once

#include "game.h"
#include "texture_manager.h"

class GameObject {
 public:
  GameObject(const char *texturePath, int ypos, int xpos);
  ~GameObject();
  void render();
  void update();

 private:
  SDL_Texture *texture;
  int ypos, xpos;
  SDL_Rect srcRect, destRect;
};