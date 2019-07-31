#include "Enemy.h"
Enemy::Enemy() {
  bitmap = al_load_bitmap("../assets/img/enemy.png");
  pos_x = 300;
  inizial_pos_x = 300;
  pos_y = SCREEN_H - 75;
  vel_x = 2;
  vel_y = 3;
  acc = 0;
  dim_x = 24;
  dim_y = 33;
  azione = 1;
  posizione = 1;
  isLive = true;
  passi = 75;
  direzione = 1;
}
Enemy::~Enemy() { al_destroy_bitmap(bitmap); }
void Enemy::draw() {
  al_convert_mask_to_alpha(bitmap, al_map_rgb(32, 156, 0));
  al_draw_bitmap_region(bitmap, posizione * dim_x, azione * dim_y, dim_x, dim_y,
                        pos_x, pos_y, 0);
}

float Enemy::getVelX() { return vel_x; }
float Enemy::getVelY() { return vel_y; }
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
int Enemy::getDimX() { return dim_x; }
int Enemy::getDimY() { return dim_y; }
int Enemy::getPosX() { return pos_x; }
int Enemy::getPosY() { return pos_y; }
int Enemy::getAzione() { return azione; }
int Enemy::getPosizione() { return posizione; }