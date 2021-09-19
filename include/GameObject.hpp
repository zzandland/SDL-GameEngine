#pragma once

#include "Game.hpp"
#include "TextureManager.hpp"

class GameObject {
 public:
  GameObject(SDL_Renderer *renderer, const char *texturePath, int ypos,
             int xpos);
  ~GameObject();
  void render();
  void update();

 private:
  SDL_Renderer *renderer;
  SDL_Texture *texture;
  int ypos, xpos;
  SDL_Rect destRect;
};