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
  virtual void update(){};
  virtual void draw(){};
  virtual float getVelX() = 0;
  virtual float getVelY() = 0;
  virtual int getDimX() = 0;
  virtual int getDimY() = 0;
  virtual int getPosX() = 0;
  virtual int getPosY() = 0;
  virtual int getAzione() = 0;
  virtual int getPosizione() = 0;
  virtual void setLive(bool){};
};

#endif // ENTITIES_H
