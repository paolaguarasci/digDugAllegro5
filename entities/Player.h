#ifndef PLAYER_H
#define PLAYER_H

// #include "../Map.h"
#include "../const.h"
#include "Entities.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_tiled.h>
#include <iostream>

class Player : public Entities {
private:
  float angolo;

public:
  Player();
  ~Player();
  void draw(ALLEGRO_DISPLAY *);
  void update(int _pos_x, int _pos_y, int _azione, int _posizione);
  float getVelX();
  float getVelY();
  int getDimX();
  int getDimY();
  int getPosX();
  int getPosY();
  void setAngolo(float);
  int getAzione();
  int getPosizione();
  bool isColl(Entities *e);
};

#endif // PLAYER_H