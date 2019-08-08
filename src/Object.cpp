#include "Object.h"

Object::Object() {}
void Object::destroy() {}
void Object::draw() {}
void Object::update() {}

bool Object::isCol(Object *obj) {
  int b1_x = pos_x;
  int b1_y = pos_y;
  int b1_h = dim_y;
  int b1_w = dim_x;
  int b2_x = obj->getPosX();
  int b2_y = obj->getPosY();
  int b2_h = obj->getDimY();
  int b2_w = obj->getDimX();

  if ((b1_x > b2_x + b2_w - 1) || // is b1 on the right side of b2?
      (b1_y > b2_y + b2_h - 1) || // is b1 under b2?
      (b2_x > b1_x + b1_w - 1) || // is b2 on the right side of b1?
      (b2_y > b1_y + b1_h - 1))   // is b2 under b1?
  {
    // no collision
    return false;
  }
  // std::cout << "Collisione!" << std::endl;
  obj->setAlive(false);
  // collision
  return true;
}