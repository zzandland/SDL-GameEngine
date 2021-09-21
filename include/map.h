#pragma once

#include <fstream>
#include <iostream>
#include <vector>

#include "SDL.h"
#include "texture_manager.h"

enum Tile { kDirt, kGrass, kWater };

class Map {
 public:
  Map();
  ~Map() = default;

  void Load(const char *path);
  void Draw();

 private:
  int w_, h_;
  SDL_Rect src_rect_, dest_rect_;
  SDL_Texture *dirt_, *grass_, *water_;
  std::vector<std::vector<Tile>> map_;
};