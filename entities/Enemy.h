#ifndef ENEMY_H
#define ENEMY_H

#include "../const.h"
#include "Entities.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_tiled.h>
#include <iostream>

class Enemy : public Entities {

public:
  Enemy();
  ~Enemy();
  void draw();
  void update(int _pos_x, int _pos_y, int _azione, int _posizione);
  float getVelX();
  float getVelY();
  int getDimX();
  int getDimY();
  int getPosX();
  int getAzione();
  int getPosizione();
};

#endif // ENEMY_H