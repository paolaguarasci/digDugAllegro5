#include "Player.h"

Player::Player() {
  bitmap = al_load_bitmap("assets/img/player.png");
  pos_x = 402;
  pos_y = 106;
  vel_x = 4;
  vel_y = 4;
  dim_x = 24;
  dim_y = 32;
  azione = 3;
  posizione = 1;
  angolo = 0;
  score = 0;
  lives = 3;
  ID = 0;
  type = PLAYER;
  scala = 1;
}

void Player::destroy() { al_destroy_bitmap(bitmap); }
void Player::draw() {
  bool flip = false;
  ALLEGRO_BITMAP *tmp = al_create_sub_bitmap(bitmap, posizione * dim_x,
                                             azione * dim_y, dim_x, dim_y);
  al_convert_mask_to_alpha(tmp, al_map_rgb(32, 156, 0));
  // al_draw_bitmap_region(bitmap, posizione * dim_x, azione * dim_y, dim_x,
  // dim_y,
  //                       pos_x, pos_y, 0);
  al_draw_scaled_rotated_bitmap(tmp, 12, 17, pos_x - dim_x / 2,
                                pos_y - dim_y / 2, scala, scala, angolo,
                                2 * flip);
}

void Player::update() {
  if (pos_x > SCREEN_W)
    pos_x = SCREEN_W;
  if (pos_x < 0)
    pos_x = 0;
  if (pos_y > SCREEN_H)
    pos_y = SCREEN_H;
  if (pos_y < 0)
    pos_y = 0;
  if (dir == DOWN && dir_prec == RIGHT) {
    while (((int)pos_x + 16) % 32 != 0) {
      pos_x++;
    }
  }
  if (dir == UP && dir_prec == RIGHT) {
    while (((int)pos_x + 16) % 32 != 0) {
      pos_x++;
    }
  }

  if (dir == DOWN && dir_prec == LEFT) {
    while (((int)pos_x - 16) % 32 != 0) {
      pos_x--;
    }
  }
  if (dir == UP && dir_prec == LEFT) {
    while (((int)pos_x - 16) % 32 != 0) {
      pos_x--;
    }
  }

  //////////////////////////////
  if (dir == LEFT && dir_prec == DOWN) {
    while (((int)pos_y + 16) % 32 != 0) {
      pos_y++;
    }
  }
  if (dir == LEFT && dir_prec == UP) {
    while (((int)pos_y - 16) % 32 != 0) {
      pos_y--;
    }
  }
  if (dir == RIGHT == 0 && dir_prec == UP) {
    while (((int)pos_y - 16) % 32 != 0) {
      pos_y--;
    }
  }
  if (dir == RIGHT == 0 && dir_prec == DOWN) {
    while (((int)pos_y + 16) % 32 != 0) {
      pos_y++;
    }
  }
}

void Player::moveUp() {
  dir = UP;
  // if (mappa->nextInDir(player->getPosX(), player->getPosY(), dir) !=
  // 0)
  // {
  // pos_y -= vel_y - 2;
  // } else {
  pos_y -= vel_y;
  // }
  azione = 1;
  posizione = (posizione <= 0 ? 2 : posizione - 1);
  angolo = 4.5;
  dir_prec = dir;
}
void Player::moveDown() {
  dir = DOWN;
  // if (mappa->nextInDir(player->getPosX(), player->getPosY(), dir) !=
  // 0)
  // {
  // pos_y += vel_y - 2;
  // } else {
  pos_y += vel_y;
  // }
  azione = 3;
  posizione = (posizione >= 2 ? 0 : posizione + 1);
  angolo = 4.70;
  dir_prec = dir;
}
void Player::moveLeft() {
  dir = LEFT;
  // if (mappa->nextInDir(player->getPosX(), player->getPosY(), dir) != 0) {
  //   pos_x -= vel_x - 2;
  // } else {
  pos_x -= vel_x;
  // }
  azione = 3;
  posizione = (posizione <= 0 ? 2 : posizione - 1);
  angolo = 0;
  dir_prec = dir;
}
void Player::moveRight() {
  dir = RIGHT;
  // if (mappa->nextInDir(player->getPosX(), player->getPosY(), dir) !=
  // 0)
  // {
  //   pos_x += vel_x - 2;
  // } else {
  pos_x += vel_x;
  // }
  azione = 1;
  posizione = (posizione >= 2 ? 0 : posizione + 1);
  angolo = 0;
  dir_prec = dir;
}
