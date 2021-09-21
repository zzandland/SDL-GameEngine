#include "map.h"

Map::Map() {
  dirt_ = TextureManager::Load("assets/dirt_.png");
  grass_ = TextureManager::Load("assets/grass_.png");
  water_ = TextureManager::Load("assets/water_.png");
}

void Map::Load(const char *path) {
  std::ifstream ifs(path);
  char c;
  if (!ifs.is_open()) {
    std::cerr << "Could not open the file - '" << path << "'" << std::endl;
  }

  ifs >> h_ >> w_;
  map_.resize(h_, std::vector<Tile>(w_, Tile::kDirt));

  int y, x;
  y = x = 0;
  while (ifs >> c && y < h_) {
    if (x == w_) {
      ++y;
      x = 0;
    }
    Tile t = static_cast<Tile>(c - '0');
    map_[y][x++] = t;
  }

  std::cout << "Map loaded: '" << path << "' (" << h_ << " x " << w_ << ")"
            << std::endl;

  ifs.close();
}

void Map::Draw() {
  for (int y = 0; y < h_; ++y) {
    for (int x = 0; x < w_; ++x) {
      Tile t = map_[y][x];
      switch (t) {
        case Tile::kDirt:
          TextureManager::Draw(dirt_, src_rect_, dest_rect_);
          break;
        case Tile::kGrass:
          TextureManager::Draw(grass_, src_rect_, dest_rect_);
          break;
        case Tile::kWater:
          TextureManager::Draw(water_, src_rect_, dest_rect_);
          break;
      }
    }
  }
}
