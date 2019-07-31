#ifndef ENTITIES_H
#define ENTITIES_H
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <string>

class Entities {
protected:
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
  Entities();
  virtual ~Entities();
  virtual void update(int _pos_x, int _pos_y, int _azione, int _posizione) = 0;
  virtual void draw() = 0;
};

#endif // ENTITIES_H
