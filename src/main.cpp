#include "Game.hpp"

#define FPS 60
#define FRAME_DELAY 1000 / FPS

Game *game;
int main(int argc, const char **argv) {
  game = new Game();

  game->init("SDL Game Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
             800, 600, false);

  unsigned frameStart, frameTime;

  while (game->running()) {
    frameStart = SDL_GetTicks();

    game->handleEvents();
    game->update();
    game->render();

    frameTime = SDL_GetTicks() - frameStart;

    if (FRAME_DELAY > frameTime) {
      SDL_Delay(FRAME_DELAY - frameTime);
    }
  }

  game->clean();

  return EXIT_SUCCESS;
}