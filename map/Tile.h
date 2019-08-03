#ifndef TILE_H
#define TILE_H
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
class Tile {
private:
  int tipo;
  int dimx;
  int dimy;
  ALLEGRO_BITMAP *img;
  float pos_x;
  float pos_y;
  int x;
  int y;

public:
  Tile(int, float, float, int, int);
  ~Tile();
  void draw();
  int getTipo();
  void setTipo(int _tipo);
  float getPosX() const;
  float getPosY() const;
  int getX() const;
  int getY() const;
};

#endif // TILE_H