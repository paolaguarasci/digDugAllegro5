#include "Tile.h"
Tile::Tile() {}
void Tile::init(int _tipo, float _pos_x, float _pos_y, int _x, int _y) {
  tipo = _tipo;
  dim_x = 32;
  dim_y = 32;
  pos_x = _pos_x;
  pos_y = _pos_y;
  x = _x;
  y = _y;
  img = al_load_bitmap("assets/img/tileset.png");
  collidable = tipo > 0;
  type = TILE;
  ID = 99;
  over_x = false;
  over_y = false;
}

void Tile::destroy() { al_destroy_bitmap(img); }
void Tile::draw() {
  al_draw_bitmap_region(img, 0 + (dim_x * tipo), 0, dim_x, dim_y, pos_x, pos_y,
                        0);
}
void Tile::update() {
  if (over_x && !over_y) {
    tipo = 5;
  } else if (!over_x && over_y) {
    tipo = 4;
  } else if (over_x && over_x) {
    tipo = 0;
  }
}