#include "Game.hpp"

#include "GameObject.hpp"
#include "TextureManager.hpp"

GameObject *player;

Game::Game() {}

Game::~Game() {}

void Game::init(const char *title, int xpos, int ypos, int width, int height,
                bool fullscreen) {
  int flags = 0;
  if (fullscreen) {
    flags = SDL_WINDOW_FULLSCREEN;
  }
  if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
    std::cout << "Subsystems initialized" << std::endl;

    window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
    if (window) {
      std::cout << "Window created" << std::endl;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer) {
      SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
      std::cout << "Renderer created" << std::endl;
    }
    isRunning = true;
  }

  player = new GameObject(renderer, "assets/player.png", 0, 0);
}

void Game::handleEvents() {
  SDL_Event event;
  SDL_PollEvent(&event);

  switch (event.type) {
    case SDL_QUIT:
      isRunning = false;
      break;

    default:
      break;
  }
}

void Game::update() { player->update(); }

void Game::render() {
  SDL_RenderClear(renderer);

  player->render();

  SDL_RenderPresent(renderer);
}

void Game::clean() {
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
  std::cout << "Game cleaned" << std::endl;
}
