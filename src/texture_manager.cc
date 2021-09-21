#include "texture_manager.h"

SDL_Texture *TextureManager::Load(const char *fileName) {
  SDL_Surface *tmp = IMG_Load(fileName);
  SDL_Texture *output = SDL_CreateTextureFromSurface(Game::renderer(), tmp);
  SDL_FreeSurface(tmp);
  return output;
}

void TextureManager::Draw(SDL_Texture *texture, SDL_Rect srcRect,
                          SDL_Rect destRect) {
  SDL_RenderCopy(Game::renderer(), texture, &srcRect, &destRect);
}
