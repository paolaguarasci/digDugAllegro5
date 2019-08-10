#ifndef TILE_H
#define TILE_H
#include "Object.h"
class Tile : public Object {
private:
  int tipo;

  int x;
  int y;

  bool over_x;
  bool over_y;

  bool last_r;
  bool last_d;
  bool last_u;
  bool last_l;

  int curva;

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

  void setLastR(bool last_r) { Tile::last_r = last_r; }
  void setLastD(bool last_d) { Tile::last_d = last_d; }
  void setLastU(bool last_u) { Tile::last_u = last_u; }
  void setLastL(bool last_l) { Tile::last_l = last_l; }

  void setCurva(int curva) { Tile::curva = curva; }
};

#endif // TILE_H