#ifndef PLAYER_H
#define PLAYER_H

#include "_const.h"
#include "map.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_tiled.h>
#include <iostream>

class Player {
private:
  ALLEGRO_BITMAP *bitmap;
  float pos_x;
  float pos_y;
  float vel_x;
  float vel_y;
  float acc;
  int dim_x;
  int dim_y;
  int azione;
  int posizione;

public:
  Player();
  ~Player();
  void draw();
  void update(int _pos_x, int _pos_y, int _azione, int _posizione);
  float getVelX();
  float getVelY();
  int getDimX();
  int getDimY();
};

#endif // PLAYER_H