#include "Tile.h"
Tile::Tile() {}
void Tile::init(int _tipo, float _pos_x, float _pos_y, int _x, int _y) {
  bitmap = NULL;
  tipo = _tipo;
  dim_x = 32;
  dim_y = 32;
  pos_x = _pos_x;
  pos_y = _pos_y;
  x = _x;
  y = _y;
  bitmap = al_load_bitmap("assets/img/terrain.png");
  collidable = tipo > 0;
  type = TILE;
  ID = 99;
  over_x = false;
  over_y = false;
  last_r = false;
  last_d = false;
  last_u = false;
  last_l = false;

  curva = -1;
}

void Tile::destroy() {
  if (bitmap != NULL)
    al_destroy_bitmap(bitmap);
}
void Tile::draw() {
  // TODO: RALLENTA DRAMMATICAMENTE LE PRESTAZIONI, RISULTA INGIOCABILE
  // al_convert_mask_to_alpha(bitmap, al_map_rgb(128, 255, 0));

  al_draw_bitmap_region(bitmap, 0 + (dim_x * tipo), 200, dim_x, dim_y, pos_x,
                        pos_y, 0);
}
void Tile::update() {
  if (last_r)
    tipo = 2;
  else if (last_d)
    tipo = 3;
  else if (last_u)
    tipo = 1;
  else if (last_l)
    tipo = 4;
  if (!over_x && !over_y && curva != -1) {
    over_x = false;
    over_y = false;
    tipo = curva + 7;
  }
  if (over_x && !over_y) {
    tipo = 6;
  } else if (!over_x && over_y) {
    tipo = 5;
  } else if (over_x && over_x) {
    tipo = 0;
  }
}