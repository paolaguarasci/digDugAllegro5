#ifndef TILE_H
#define TILE_H
#include "Object.h"
class Tile : public Object {
private:
  int tipo;

  ALLEGRO_BITMAP *img;

  int x;
  int y;

  bool over_x;
  bool over_y;

public:
  Tile();
  void init(int, float, float, int, int);
  void destroy();
  void draw();
  void update();
  int getX() const { return x; }
  int getY() const { return y; }
  int getTipo() { return tipo; }
  void setTipo(int _tipo) { tipo = _tipo; }

  bool getOverX() { return over_x; }
  bool getOverY() { return over_y; }

  void setOverX(bool over_x) { Tile::over_x = over_x; }
  void setOverY(bool over_y) { Tile::over_y = over_y; }
};

#endif // TILE_H