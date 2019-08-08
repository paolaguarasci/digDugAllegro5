#ifndef TILE_H
#define TILE_H
#include "Object.h"
class Tile : public Object {
private:
  int tipo;

  ALLEGRO_BITMAP *img;

  int x;
  int y;

public:
  Tile();
  void init(int, float, float, int, int);
  void destroy();
  void draw();
  int getX() const { return x; }
  int getY() const { return y; }
  int getTipo() { return tipo; }
  void setTipo(int _tipo) { tipo = _tipo; }
};

#endif // TILE_H