#pragma once

#include <fstream>
#include <iostream>
#include <vector>

#include "SDL.h"
#include "TextureManager.hpp"

enum Tile { kDirt, kGrass, kWater };

class Map {
 public:
  Map(int w, int h);
  ~Map() = default;

  void load(const char *path);
  void draw();

 private:
  int w, h;
  SDL_Rect srcRect, destRect;
  SDL_Texture *dirt, *grass, *water;
  std::vector<std::vector<Tile>> map;
};