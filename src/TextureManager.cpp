#include "TextureManager.hpp"

SDL_Texture *TextureManager::loadTexture(SDL_Renderer *renderer,
                                         const char *fileName) {
  SDL_Surface *tmp = IMG_Load(fileName);
  SDL_Texture *output = SDL_CreateTextureFromSurface(renderer, tmp);
  SDL_FreeSurface(tmp);
  return output;
}
