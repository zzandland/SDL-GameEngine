#pragma once

#include <iostream>

#include "SDL.h"
#include "SDL_image.h"

class Game {
 public:
  Game();
  ~Game();

  void init(const char *title, int xpos, int ypos, int width, int height,
            bool fullscreen);
  static SDL_Renderer *getRenderer();
  void handleEvents();
  void update();
  void render();
  void clean();

  bool running() { return isRunning; };

 private:
  bool isRunning = false;
  SDL_Window *window;
  static SDL_Renderer *renderer;
};