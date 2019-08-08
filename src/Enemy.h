#ifndef ENEMY_H
#define ENEMY_H

#include "Object.h"

class Enemy : public Object {
private:
  int inizial_pos_x;
  int passi;
  int direzione;

public:
  Enemy();
  void destroy();
  void draw();
  void update();
};

#endif // ENEMY_H