#include "player.h"

Player::Player() {
  bitmap = al_load_bitmap("../assets/img/player.png");
  pos_x = 100;
  pos_y = 100;
  vel_x = 0;
  vel_y = 0;
  acc = 0;
  dim_x = 24;
  dim_y = 33;
  azione = 1;
  posizione = 1;
}
Player::~Player() { al_destroy_bitmap(bitmap); }
void Player::draw() {
  al_convert_mask_to_alpha(bitmap, al_map_rgb(32, 156, 0));
  al_draw_bitmap_region(bitmap, posizione * dim_x, azione * dim_y, dim_x, dim_y,
                        pos_x, pos_y, 0);
}
void Player::update(int _pos_x, int _pos_y, int _azione, int _posizione) {
  pos_x = _pos_x;
  pos_y = _pos_y;
  posizione = _posizione;
  azione = _azione;
}