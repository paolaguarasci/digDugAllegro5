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
}
void Tile::destroy() { al_destroy_bitmap(img); }
void Tile::draw() {
  al_draw_bitmap_region(img, 0 + (dim_x * tipo), 0, dim_x, dim_y, pos_x, pos_y,
                        0);
  al_draw_filled_circle(pos_x, pos_y, 2, al_map_rgb(255, 0, 0));
}
