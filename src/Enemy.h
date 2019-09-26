#ifndef ENEMY_H
#define ENEMY_H

#include "Map.h"
#include "Object.h"
#include "Player.h"
#include <cmath>

class Enemy : public Object {
private:
  int inizial_pos_x;
  int passi;
  int direzione;
  bool flip;
  int tipo;

public:
  Enemy(int, int, int);
  void destroy();
  void draw();
  void update();
  void vola(Player *player, Map *mappa);
  void insegui(Player *player, Map *mappa);
};

#endif // ENEMY_H