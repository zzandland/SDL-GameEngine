#include "game.h"

#include "game_object.h"
#include "map.h"
#include "texture_manager.h"

SDL_Renderer *Game::renderer_ = nullptr;
GameObject *player = nullptr;
Map *map = nullptr;

Game::Game(const char *title, int xpos, int ypos, int width, int height,
           bool fullscreen) {
  int flags = 0;
  if (fullscreen) {
    flags = SDL_WINDOW_FULLSCREEN;
  }
  if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
    std::cout << "Subsystems initialized" << std::endl;

    window_ = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
    if (window_) {
      std::cout << "Window created" << std::endl;
    }

    Game::renderer_ = SDL_CreateRenderer(window_, -1, 0);
    if (renderer_) {
      SDL_SetRenderDrawColor(renderer_, 255, 255, 255, SDL_ALPHA_OPAQUE);
      std::cout << "Renderer created" << std::endl;
    }
    running_ = true;
  }

  player = new GameObject("assets/player.png", 0, 0);
  map = new Map();
  map->Load("assets/level1.txt");
}

Game::~Game() {}

SDL_Renderer *Game::renderer() { return Game::renderer_; }

void Game::HandleEvents() {
  SDL_Event event;
  SDL_PollEvent(&event);

  switch (event.type) {
    case SDL_QUIT:
      running_ = false;
      break;

    default:
      break;
  }
}

void Game::Update() { player->Update(); }

void Game::Render() {
  SDL_RenderClear(renderer_);

  player->Render();
  map->Draw();

  SDL_RenderPresent(renderer_);
}

void Game::Clean() {
  SDL_DestroyWindow(window_);
  SDL_DestroyRenderer(renderer_);
  SDL_Quit();
  std::cout << "Game cleaned" << std::endl;
}
