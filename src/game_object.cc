#include "game_object.h"

GameObject::GameObject(const char *texturePath, int ypos, int xpos) {
  ypos_ = ypos;
  xpos_ = xpos;
  texture_ = TextureManager::Load(texturePath);

  int w, h;
  SDL_QueryTexture(texture_, nullptr, nullptr, &w, &h);
  src_rect_.w = w;
  src_rect_.h = h;
}

GameObject::~GameObject() {}

void GameObject::Render() {
  TextureManager::Draw(texture_, src_rect_, dest_rect_);
}

void GameObject::Update() {
  ++ypos_;
  ++xpos_;

  src_rect_.x = src_rect_.y = 0;
  dest_rect_.x = xpos_;
  dest_rect_.y = ypos_;
  dest_rect_.w = dest_rect_.h = 100;
}