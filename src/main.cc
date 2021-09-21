#include "game.h"

#define FPS 60
#define FRAME_DELAY 1000 / FPS

Game *game;
int main(int argc, const char **argv) {
  game = new Game("SDL Game Engine", SDL_WINDOWPOS_CENTERED,
                  SDL_WINDOWPOS_CENTERED, 800, 640, false);

  unsigned frameStart, frameTime;

  while (game->running()) {
    frameStart = SDL_GetTicks();

    game->HandleEvents();
    game->Update();
    game->Render();

    frameTime = SDL_GetTicks() - frameStart;

    if (FRAME_DELAY > frameTime) {
      SDL_Delay(FRAME_DELAY - frameTime);
    }
  }

  game->Clean();

  return EXIT_SUCCESS;
}