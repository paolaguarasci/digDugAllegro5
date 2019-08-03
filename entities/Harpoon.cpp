#include "Harpoon.h"
#include <iostream>
Harpoon::Harpoon() {
  gittata = 200;
  bitmap = al_load_bitmap("../assets/img/harpoon.png");
  dim_x = 30;
  dim_y = 5;
  isLive = false;
  pos_x = 0;
  pos_y = 0;
  inizial_pos_x = 0;
}
Harpoon::~Harpoon() {}
void Harpoon::start(int _pos_x, int _pos_y) {
  pos_y = _pos_y + 16;
  pos_x = _pos_x + 10;
  inizial_pos_x = _pos_x;
  update();
}
void Harpoon::update() {
  if (pos_x < inizial_pos_x + gittata) {
    pos_x += 7;
    isLive = true;
  } else {
    isLive = false;
  }
}
void Harpoon::draw() {
  if (isLive) {
    al_convert_mask_to_alpha(bitmap, al_map_rgb(0, 255, 0));
    al_draw_bitmap_region(bitmap, 19, 8, dim_x, dim_y, pos_x, pos_y, 0);
    update();
  }
}
float Harpoon::getVelX() {}
float Harpoon::getVelY() {}
int Harpoon::getDimX() {}
int Harpoon::getDimY() {}
int Harpoon::getPosX() {}
int Harpoon::getPosY() {}
int Harpoon::getAzione() {}
int Harpoon::getPosizione() {}
void Harpoon::setLive(bool live) { isLive = live; }
bool Harpoon::isColl(Entities *e) {

  int b1_x = pos_x;
  int b1_y = pos_y;
  int b1_h = dim_y;
  int b1_w = dim_x;
  int b2_x = e->getPosX();
  int b2_y = e->getPosY();
  int b2_h = e->getDimY();
  int b2_w = e->getDimX();

  if ((b1_x > b2_x + b2_w - 1) || // is b1 on the right side of b2?
      (b1_y > b2_y + b2_h - 1) || // is b1 under b2?
      (b2_x > b1_x + b1_w - 1) || // is b2 on the right side of b1?
      (b2_y > b1_y + b1_h - 1))   // is b2 under b1?
  {
    // no collision
    return false;
  }
  std::cout << "Collisione!" << std::endl;
  e->setLive(false);
  // collision
  return true;
}