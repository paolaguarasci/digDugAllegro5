#include "Tile.h"
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
Tile::Tile(int _tipo, float _pos_x, float _pos_y, int _x, int _y)
    : tipo(_tipo), dimx(32), dimy(32), pos_x(_pos_x), pos_y(_pos_y), x(_x),
      y(_y) {
  img = al_load_bitmap("../assets/img/tileset.png");
}
Tile::~Tile() {}
void Tile::draw() {
  al_draw_bitmap_region(img, 0 + (dimx * tipo), 0, dimx, dimy, pos_x, pos_y, 0);
}
int Tile::getTipo() { return tipo; }
void Tile::setTipo(int _tipo) { tipo = _tipo; }
float Tile::getPosX() const { return pos_x; }
float Tile::getPosY() const { return pos_y; }
int Tile::getX() const { return x; }
int Tile::getY() const { return y; }