#include "Player.h"
#include "Entities.h"
Player::Player() {
  bitmap = al_load_bitmap("assets/img/player.png");
  pos_x = 402;
  pos_y = 106;
  vel_x = 4;
  vel_y = 4;
  acc = 0;
  dim_x = 24;
  dim_y = 32;
  azione = 3;
  posizione = 1;
  angolo = 0;
}
void Player::init() {
  std::cout << "Player init\n";
  while (pos_x > SCREEN_W / 2) {
    update(pos_x - 3, pos_y, 3, 1);
    draw();
  }
  while (pos_y < SCREEN_H / 2) {
    update(pos_x, pos_y + 3, 2, 1);
    draw();
  }
}
Player::~Player() { al_destroy_bitmap(bitmap); }
void Player::draw() {
  bool flip = false;
  ALLEGRO_BITMAP *tmp = al_create_sub_bitmap(bitmap, posizione * dim_x,
                                             azione * dim_y, dim_x, dim_y);
  al_convert_mask_to_alpha(tmp, al_map_rgb(32, 156, 0));
  // al_draw_bitmap_region(bitmap, posizione * dim_x, azione * dim_y, dim_x,
  // dim_y,
  //                       pos_x, pos_y, 0);
  al_draw_scaled_rotated_bitmap(tmp, 12, 17, pos_x, pos_y, 1, 1, angolo,
                                2 * flip);
}
void Player::setAngolo(float _angolo) { angolo = _angolo; }
float Player::getVelX() { return vel_x; }
float Player::getVelY() { return vel_y; }
void Player::update(int _pos_x, int _pos_y, int _azione, int _posizione) {
  pos_x = _pos_x;
  pos_y = _pos_y;
  posizione = _posizione;
  azione = _azione;
}
int Player::getDimX() { return dim_x; }
int Player::getDimY() { return dim_y; }
int Player::getPosX() { return pos_x; }
int Player::getPosY() { return pos_y; }
int Player::getAzione() { return azione; }
int Player::getPosizione() { return posizione; }
bool Player::isColl(Entities *e) {

  int b1_x = pos_x;
  int b1_y = pos_y;
  int b1_h = dim_y;
  int b1_w = dim_x;
  int b2_x = e->getPosX();
  int b2_y = e->getPosY();
  int b2_h = e->getDimY();
  int b2_w = e->getDimX();

  if ((b1_x > b2_x + b2_w - 1) || // is b1 on the right side of b2?
      (b1_y > b2_y + b2_h - 1) || // is b1 under b2?
      (b2_x > b1_x + b1_w - 1) || // is b2 on the right side of b1?
      (b2_y > b1_y + b1_h - 1))   // is b2 under b1?
  {
    // no collision
    return false;
  }
  std::cout << "Collisione!" << std::endl;
  e->setLive(false);
  // collision
  return true;
}