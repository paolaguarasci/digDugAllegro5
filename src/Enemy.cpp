#include "Enemy.h"
Enemy::Enemy() {
  bitmap = al_load_bitmap("assets/img/original.png");
  pos_x = 32 * 13;
  inizial_pos_x = pos_x;
  pos_y = SCREEN_H - (32 * 3) + 10;
  vel_x = 7;
  vel_y = 7;
  dim_x = 15;
  dim_y = 15;
  alive = true;
  passi = 32 * 2;
  bool flip = false;
  scala = 2;
  ID = 1;
  type = ENEMY;
  collidable = true;
  a_col = 0;
  a_row = 6;
  offsetAnimationX = 0;
  offsetAnimationY = 1;
}
void Enemy::destroy() { al_destroy_bitmap(bitmap); }

void Enemy::draw() {
  // al_convert_mask_to_alpha(bitmap, al_map_rgb(32, 156, 0));
  // al_draw_bitmap_region(bitmap, posizione * dim_x, azione * dim_y, dim_x,
  // dim_y,
  //                       pos_x, pos_y, 0);
  if (alive) {
    ALLEGRO_BITMAP *tmp = al_create_sub_bitmap(
        bitmap, (a_col * dim_x) + (curr_frame * dim_x) + offsetAnimationX,
        (a_row * dim_y) + offsetAnimationY, dim_x, dim_y);
    al_convert_mask_to_alpha(tmp, al_map_rgb(32, 156, 0));
    al_draw_scaled_rotated_bitmap(tmp, 0, 0, pos_x, pos_y, scala, scala, 0,
                                  flip * 1);
  }
}

void Enemy::update() {
  curr_frame = (curr_frame == 1 ? 0 : 1);
  // if (pos_x >= (inizial_pos_x + passi)) {
  //   direzione = -1;
  //   azione = 3;
  // } else if (pos_x <= (inizial_pos_x - passi)) {
  //   direzione = 1;
  //   azione = 1;
  // }
  // pos_x += (direzione * vel_x);
  // posizione++;
  // if (posizione > 2)
  //   posizione = 0;
}

void Enemy::insegui(Player *player) {

  /*
    Movimento automatico del nemico, all'inseguimento del player.
    - versione inziale: non tiene conto delle mattonelle nere
    - prox fix: tenere conto della "strada migliore"
    ...probabilmente in un prox refactoring lo sposto in update()...
  */
  if (pos_x != player->getPosX()) {
    if (player->getPosX() > pos_x) {
      flip = false;
      pos_x += vel_x;
    } else {
      flip = true;
      pos_x -= vel_x;
    }
  }
  if (pos_y != player->getPosY())
    if (player->getPosY() > pos_y)
      pos_y += vel_y;
    else
      pos_y -= vel_y;
}