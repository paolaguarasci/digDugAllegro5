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
  ID = 1;
  type = ENEMY;
  collidable = true;
}
void Enemy::destroy() { al_destroy_bitmap(bitmap); }

void Enemy::draw() {
  // al_convert_mask_to_alpha(bitmap, al_map_rgb(32, 156, 0));
  // al_draw_bitmap_region(bitmap, posizione * dim_x, azione * dim_y, dim_x,
  // dim_y,
  //                       pos_x, pos_y, 0);
  if (alive) {
    ALLEGRO_BITMAP *tmp = al_create_sub_bitmap(bitmap, posizione * dim_x,
                                               azione * dim_y, dim_x, dim_y);
    al_convert_mask_to_alpha(tmp, al_map_rgb(32, 156, 0));
    al_draw_scaled_rotated_bitmap(tmp, 12, 17, pos_x, pos_y, scala, scala,
                                  angolo, 0);
  }
}

void Enemy::update() {
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
    if (player->getPosX() > pos_x)
      pos_x += vel_x;
    else
      pos_x -= vel_x;
  }
  if (pos_y != player->getPosY())
    if (player->getPosY() > pos_y)
      pos_y += vel_y;
    else
      pos_y -= vel_y;
}