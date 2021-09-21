#include "game_object.h"

GameObject::GameObject(const char *texturePath, int ypos, int xpos) {
  this->ypos = ypos;
  this->xpos = xpos;
  this->texture = TextureManager::load(texturePath);

  int w, h;
  SDL_QueryTexture(texture, nullptr, nullptr, &w, &h);
  srcRect.w = w;
  srcRect.h = h;
}

GameObject::~GameObject() {}

void GameObject::render() { TextureManager::draw(texture, srcRect, destRect); }

void GameObject::update() {
  ++ypos;
  ++xpos;

  srcRect.x = srcRect.y = 0;
  destRect.x = xpos;
  destRect.y = ypos;
  destRect.w = destRect.h = 100;
}