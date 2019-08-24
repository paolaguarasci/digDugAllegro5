#ifndef OBJECT_H
#define OBJECT_H
#include "const.h"
#include <algorithm>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include <iostream>
#include <string>

class Object {
protected:
  int ID;
  TYPE type;
  float pos_x;
  float pos_y;
  float vel_x;
  float vel_y;

  int dim_x;
  int dim_y;
  int azione;
  int posizione;

  bool alive;
  bool collidable;

  float angolo;
  float scala;
  DIREZIONE dir;
  DIREZIONE dir_prec;

  int a_row;
  int a_col;
  int curr_frame;
  int offsetAnimationX;
  int offsetAnimationY;

  ALLEGRO_BITMAP *bitmap = NULL;

public:
  Object();
  virtual void destroy();
  virtual void draw();
  virtual void update();

  float getVelX() { return vel_x; }
  float getVelY() { return vel_y; }
  void setVelX(float vel_x) { Object::vel_x = vel_x; }
  void setVelY(float vel_y) { Object::vel_y = vel_y; }

  int getDimX() { return dim_x; }
  int getDimY() { return dim_y; }
  void setDimX(float dim_x) { Object::dim_x = dim_x; }
  void setDimY(float dim_y) { Object::dim_y = dim_y; }

  int getPosX() { return pos_x; }
  int getPosY() { return pos_y; }
  void setPosX(float pos_x) { Object::pos_x = pos_x; }
  void setPosY(float pos_y) { Object::pos_y = pos_y; }

  int getAzione() { return azione; }
  int getPosizione() { return posizione; }
  void setAzione(float azione) { Object::azione = azione; }
  void setPosizione(float posizione) { Object::posizione = posizione; }

  DIREZIONE getDir() { return dir; }
  void setDir(DIREZIONE dir) { Object::dir = dir; }
  DIREZIONE getDirPrec() { return dir_prec; }
  void setDirPrec(DIREZIONE dir_prec) { Object::dir_prec = dir_prec; }

  bool getAlive() { return alive; }
  void setAlive(bool alive) { Object::alive = alive; };

  float getAngolo() { return angolo; }
  void setAngolo(float angolo) { Object::angolo = angolo; }
  bool getCollidable() { return collidable; }
  bool isCol(Object *obj);
};

#endif // OBJECT_H