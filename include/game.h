#pragma once

#include <iostream>

#include "SDL.h"
#include "SDL_image.h"

class Game {
 public:
  Game() = delete;
  Game(const char *title, int xpos, int ypos, int width, int height,
       bool fullscreen);
  ~Game();
  static SDL_Renderer *renderer();
  void HandleEvents();
  void Update();
  void Render();
  void Clean();

  bool running() { return running_; };

 private:
  bool running_ = false;
  SDL_Window *window_;
  static SDL_Renderer *renderer_;
};