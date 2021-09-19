#include "GameObject.hpp"

GameObject::GameObject(const char *texturePath, int ypos, int xpos) {
  this->ypos = ypos;
  this->xpos = xpos;
  this->texture = TextureManager::load(texturePath);
}

GameObject::~GameObject() {}

void GameObject::render() {
  SDL_RenderCopy(Game::getRenderer(), texture, nullptr, &destRect);
}

void GameObject::update() {
  ++ypos;
  ++xpos;

  destRect.x = xpos;
  destRect.y = ypos;
  destRect.w = destRect.h = 100;
}