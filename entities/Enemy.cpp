#include "Enemy.h"
Enemy::Enemy() {
  bitmap = al_load_bitmap("../assets/img/enemy.png");
  pos_x = 100;
  pos_y = SCREEN_H - 100;
  vel_x = 10;
  vel_y = 3;
  acc = 0;
  dim_x = 24;
  dim_y = 33;
  azione = 1;
  posizione = 1;
}
Enemy::~Enemy() { al_destroy_bitmap(bitmap); }
void Enemy::draw() {
  al_convert_mask_to_alpha(bitmap, al_map_rgb(32, 156, 0));
  al_draw_bitmap_region(bitmap, posizione * dim_x, azione * dim_y, dim_x, dim_y,
                        pos_x, pos_y, 0);
}

float Enemy::getVelX() { return vel_x; }
float Enemy::getVelY() { return vel_y; }
void Enemy::update(int _pos_x, int _pos_y, int _azione, int _posizione) {
  pos_x = _pos_x;
  pos_y = _pos_y;
  posizione = _posizione;
  azione = _azione;
}
int Enemy::getDimX() { return dim_x; }
int Enemy::getDimY() { return dim_y; }
int Enemy::getPosX() { return pos_x; }
int Enemy::getAzione() { return azione; }
int Enemy::getPosizione() { return posizione; }