#pragma once

#include "game.h"
#include "texture_manager.h"

class GameObject {
 public:
  GameObject(const char *texturePath, int ypos, int xpos);
  ~GameObject();
  void Render();
  void Update();

 private:
  SDL_Texture *texture_;
  int ypos_, xpos_;
  SDL_Rect src_rect_, dest_rect_;
};