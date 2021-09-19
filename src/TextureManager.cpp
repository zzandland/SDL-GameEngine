#include "TextureManager.hpp"

SDL_Texture *TextureManager::load(const char *fileName) {
  SDL_Surface *tmp = IMG_Load(fileName);
  SDL_Texture *output = SDL_CreateTextureFromSurface(Game::getRenderer(), tmp);
  SDL_FreeSurface(tmp);
  return output;
}

void TextureManager::draw(SDL_Texture *texture, SDL_Rect srcRect,
                          SDL_Rect destRect) {
  SDL_RenderCopy(Game::getRenderer(), texture, &srcRect, &destRect);
}
