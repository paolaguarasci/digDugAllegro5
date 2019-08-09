#ifndef ENEMY_H
#define ENEMY_H

#include "Object.h"
#include "Player.h"

class Enemy : public Object {
private:
  int inizial_pos_x;
  int passi;
  int direzione;
  bool flip;

public:
  Enemy();
  void destroy();
  void draw();
  void update();
  void insegui(Player *player);
};

#endif // ENEMY_H