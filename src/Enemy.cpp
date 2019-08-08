#include "Enemy.h"
Enemy::Enemy() {
  bitmap = al_load_bitmap("assets/img/enemy.png");
  pos_x = 32 * 13;
  inizial_pos_x = pos_x;
  pos_y = SCREEN_H - (32 * 3) + 10;
  vel_x = 2;
  vel_y = 3;
  dim_x = 24;
  dim_y = 32;
  azione = 1;
  posizione = 1;
  alive = true;
  passi = 32 * 2;
  direzione = 1;
  angolo = 0;
  scala = 1.5;
}
void Enemy::destroy() { al_destroy_bitmap(bitmap); }

void Enemy::draw() {
  // al_convert_mask_to_alpha(bitmap, al_map_rgb(32, 156, 0));
  // al_draw_bitmap_region(bitmap, posizione * dim_x, azione * dim_y, dim_x,
  // dim_y,
  //                       pos_x, pos_y, 0);
  ALLEGRO_BITMAP *tmp = al_create_sub_bitmap(bitmap, posizione * dim_x,
                                             azione * dim_y, dim_x, dim_y);
  al_convert_mask_to_alpha(tmp, al_map_rgb(32, 156, 0));
  al_draw_scaled_rotated_bitmap(tmp, 12, 17, pos_x, pos_y, scala, scala, angolo,
                                0);
}

void Enemy::update() {
  if (pos_x >= (inizial_pos_x + passi)) {
    direzione = -1;
    azione = 3;
  } else if (pos_x <= (inizial_pos_x - passi)) {
    direzione = 1;
    azione = 1;
  }
  pos_x += (direzione * vel_x);
  posizione++;
  if (posizione > 2)
    posizione = 0;
}
