#include "GameObject.hpp"

GameObject::GameObject(SDL_Renderer *renderer, const char *texturePath,
                       int ypos, int xpos) {
  this->ypos = ypos;
  this->xpos = xpos;
  this->renderer = renderer;
  this->texture = TextureManager::loadTexture(renderer, texturePath);
}

GameObject::~GameObject() {}

void GameObject::render() {
  SDL_RenderCopy(renderer, texture, nullptr, &destRect);
}

void GameObject::update() {
  ++ypos;
  ++xpos;

  srcRect.x = srcRect.y = 0;
  srcRect.w = srcRect.h = 32;

  destRect.x = xpos;
  destRect.y = ypos;
  destRect.w = srcRect.w * 2;
  destRect.h = srcRect.h * 2;
}