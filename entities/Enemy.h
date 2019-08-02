#ifndef ENEMY_H
#define ENEMY_H

#include "../const.h"
#include "Entities.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_tiled.h>
#include <iostream>

class Enemy : public Entities {
private:
  bool isLive = true;
  int inizial_pos_x;
  int passi;
  int direzione;

public:
  Enemy();
  ~Enemy();
  void draw();
  void update();
  float getVelX();
  float getVelY();
  int getDimX();
  int getDimY();
  int getPosX();
  int getPosY();
  int getAzione();
  int getPosizione();
  void setLive(bool);
  bool getLive();
};

#endif // ENEMY_H