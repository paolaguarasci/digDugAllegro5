#include "Player.h"

Player::Player() {
  bitmap = al_load_bitmap("assets/img/original.png");
  pos_x = 467;
  pos_y = 71;
  vel_x = 32;
  vel_y = 32;
  dim_x = 15;
  dim_y = 15;

  curr_frame = 0;
  score = 0;
  lives = 3;
  ID = 0;
  type = PLAYER;
  scala = 1.5;
  dir = LEFT;
  offsetAnimationX = 22;
  offsetAnimationY = 0;
  a_col = 12;
  a_row = 0;
}

void Player::destroy() { al_destroy_bitmap(bitmap); }
void Player::draw() {
  bool flip = false;
  ALLEGRO_BITMAP *tmp = al_create_sub_bitmap(
      bitmap, (a_col * dim_x) + (curr_frame * dim_x) + offsetAnimationX,
      (a_row * dim_y) + offsetAnimationY, dim_x, dim_y);
  al_convert_mask_to_alpha(tmp, al_map_rgb(32, 156, 0));
  al_draw_scaled_rotated_bitmap(tmp, 0, 0, pos_x, pos_y, scala, scala, 0, 0);
}

void Player::update() {
  std::cout << pos_x << " " << pos_y << "\n";
  if (pos_x >= SCREEN_W)
    pos_x = SCREEN_W - dim_x;
  if (pos_x <= 0)
    pos_x = 0;
  if (pos_y >= SCREEN_H)
    pos_y = SCREEN_H - dim_y;
  if (pos_y <= 0)
    pos_y = 0;

  // TODO:
  // Devo fare in modo che si muova a blocchi perchè l'algoritmo di prima,
  // per quanto impreciso, cmq funzionava ma usava l'operazione di modulo, che
  // ha bisogno di dati interi per lavorare. Ora con le posizioni float non
  // funziona.
}

void Player::moveUp() {
  dir_prec = dir;
  dir = UP;
  // if (mappa->nextInDir(player->getPosX(), player->getPosY(), dir) !=
  // 0)
  // {
  // pos_y -= vel_y - 2;
  // } else {
  pos_y -= vel_y;
  // }

  dir_prec = (dir != DOWN && dir != UP ? dir : dir_prec);

  if (dir_prec == RIGHT) {
    std::cout << "RIGHT\n";
    offsetAnimationX = 0;
    offsetAnimationY = 7;
    a_col = 0;
    a_row = 2;
  }
  if (dir_prec == LEFT) {
    std::cout << "LEFT\n";
    offsetAnimationX = 22;
    offsetAnimationY = 7;
    a_col = 12;
    a_row = 2;
  }
  curr_frame = (curr_frame == 1 ? 0 : 1);
  dir = UP;
}
void Player::moveDown() {
  // if (mappa->nextInDir(player->getPosX(), player->getPosY(), dir) !=
  // 0)
  // {
  // pos_y += vel_y - 2;
  // } else {
  pos_y += vel_y;
  // }

  // dir_prec = (dir != DOWN && dir != UP ? dir : dir_prec);
  dir_prec = dir;

  std::cout << "RIGHT\n";
  offsetAnimationX = 0;
  offsetAnimationY = 0;
  a_col = 0;
  a_row = 1;

  // if (dir_prec == LEFT) {
  //   std::cout << "LEFT\n";
  //   offsetAnimationX = 22;
  //   offsetAnimationY = 0;
  //   a_col = 12;
  //   a_row = 1;
  // }
  curr_frame = (curr_frame == 1 ? 0 : 1);
  dir = DOWN;
}
void Player::moveLeft() {
  dir_prec = dir;
  dir = LEFT;
  // if (mappa->nextInDir(player->getPosX(), player->getPosY(), dir) != 0) {
  //   pos_x -= vel_x - 2;
  // } else {
  pos_x -= vel_x;
  // }
  offsetAnimationX = 22;
  offsetAnimationY = 0;
  a_col = 12;
  a_row = 0;
  curr_frame = (curr_frame == 1 ? 0 : 1);
}
void Player::moveRight() {
  dir_prec = dir;
  dir = RIGHT;
  // if (mappa->nextInDir(player->getPosX(), player->getPosY(), dir) !=
  // 0)
  // {
  //   pos_x += vel_x - 2;
  // } else {
  pos_x += vel_x;
  // }
  offsetAnimationX = 0;
  offsetAnimationY = 0;
  a_col = 0;
  a_row = 0;
  curr_frame = (curr_frame == 1 ? 0 : 1);
}
