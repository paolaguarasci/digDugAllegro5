#include "Enemy.h"
Enemy::Enemy(int x, int y, int t) {
  ID = rand() % 100000; 
  bitmap = al_load_bitmap("assets/img/original.png");
  pos_x = x;
  pos_y = y;
  tipo = t;
  // pos_x = 32 * 12;
  inizial_pos_x = pos_x;
  // pos_y = SCREEN_H - (32 * 4);
  vel_x = (tipo == 0 ? 2 : 1);
  vel_y = (tipo == 0 ? 2 : 1);
  dim_x = 15;
  dim_y = 15;
  alive = true;
  passi = 32 * 2;
  // bool flip = false;
  scala = 2;
  ID = 1;
  type = ENEMY;
  collidable = true;
  a_col = 0;
  a_row = 5;
  offsetAnimationX = 0;
  offsetAnimationY = 1;
  curr_frame = 0;
  flip = 0;
}
void Enemy::destroy() { al_destroy_bitmap(bitmap); }

void Enemy::draw() {
  // al_convert_mask_to_alpha(bitmap, al_map_rgb(32, 156, 0));
  // al_draw_bitmap_region(bitmap, posizione * dim_x, azione * dim_y, dim_x,
  // dim_y,
  //                       pos_x, pos_y, 0);
  if (alive) {
    ALLEGRO_BITMAP *tmp = al_create_sub_bitmap(
        bitmap, ((a_col) * dim_x) + (curr_frame * dim_x) + offsetAnimationX,
        ((a_row + tipo)* dim_y) + offsetAnimationY, dim_x, dim_y);
    // al_convert_mask_to_alpha(tmp, al_map_rgb(32, 156, 0));
    // al_convert_mask_to_alpha(tmp, al_map_rgb(0,0,0));
    al_draw_scaled_rotated_bitmap(tmp, 0, 0, pos_x, pos_y, scala, scala, 0,
                                  flip * 1);

    // RETTANGOLI DI DEBUG                             
    // UP                     
    // al_draw_rectangle(pos_x+32, pos_y-32,pos_x,pos_y,al_map_rgb(255,255,255), 0);
    // DOWN
    // al_draw_rectangle(pos_x, pos_y+32,pos_x+32,pos_y+64,al_map_rgb(255,255,255), 0);
    // LEFT
    // al_draw_rectangle(pos_x-32, pos_y,pos_x,pos_y+32,al_map_rgb(255,255,255), 0);
    // RIGHT
    // al_draw_rectangle(pos_x+32, pos_y,pos_x+64,pos_y+32,al_map_rgb(255,255,255), 0);
    // ===================

    // PALLINI DI DEBUG
    // UP
    // al_draw_filled_circle((pos_x + 16), (pos_y - 16), 10, al_map_rgb(255, 0, 0 ));
    // DOWN
    // al_draw_filled_circle((pos_x + 16), (pos_y + 32 + 16) , 10, al_map_rgb(0, 255, 0 ));
    // LEFT
    // al_draw_filled_circle((pos_x - 16), (pos_y + 16), 10, al_map_rgb(0, 0, 255 ));
    // RIGHT
    // al_draw_filled_circle((pos_x +32 + 16), (pos_y + 16), 10, al_map_rgb(0, 0, 0 ));
    // ===================



    // PALLINI DI DEBUG che dovrebbero segnare gli stessi punti cercati da tipoTile[]
    // UP
    // al_draw_filled_circle(((pos_x+16) / 32) * 32, (((pos_y+16) / 32) - 1) * 32, 10, al_map_rgb(255, 0, 0 ));
    // DOWN
    // al_draw_filled_circle(  ((pos_x + 16) / 32) * 32, (((pos_y + 16) / 32) + 1) *32, 10, al_map_rgb(0, 255, 0 ));
    // RIGHT
    // al_draw_filled_circle( (((pos_x + 16) / 32) + 1) * 32, ((pos_y + 16) / 32) * 32, 10, al_map_rgb(0, 0, 255 ));
    // LEFT
    // al_draw_filled_circle((((pos_x + 16) / 32) - 1) * 32, (((pos_y+16) / 32)) * 32, 10, al_map_rgb(0, 0, 0 ));
    // ===================
 
  }
}

void Enemy::update() {
  curr_frame = (curr_frame == 1 ? 0 : 1);
  switch (direzione) {
  case RIGHT:
    pos_x -= vel_x;
    break;
  case LEFT:
    pos_x += vel_x;
    break;
  case UP:
    pos_y -= vel_y;
    break;
  case DOWN:
    pos_y += vel_y;
    break;
  }
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
/* TODO:
  Movimento automatico del nemico, all'inseguimento del player.
  - versione inziale: non tiene conto delle mattonelle nere
  - prox fix: tenere conto della "strada migliore"
  ...probabilmente in un prox refactoring lo sposto in update()...
*/
void Enemy::insegui(Player *player, Map *mappa) {
  // distanza tra due punti:
  // sqrt((x2-x1)^2 + (y2-y1)^2)
  // float distPlayer =
  //     sqrt((pos_x - player->getPosX()) * (pos_x - player->getPosX()) +
  //          (pos_y - player->getPosY()) * (pos_y - player->getPosY()));
  // Tile *nextTile = mappa->getTile(pos_x / 32, pos_y / 32);
  int tipoTile[4];
  tipoTile[0] =
      mappa->getTile(((pos_x + 16) / 32) - 1, ((pos_y + 16) / 32))->getTipo(); // LEFT
  tipoTile[1] = mappa->getTile(((pos_x+16) / 32), (((pos_y+16) / 32) - 1))->getTipo(); // UP
  tipoTile[2] =
      mappa->getTile((((pos_x + 16) / 32) + 1), ((pos_y + 16) / 32))->getTipo(); // RIGHT
  tipoTile[3] =
      mappa->getTile(((pos_x + 16) / 32), (((pos_y + 16) / 32) + 1))->getTipo(); // DOWN
  float distTile[4];

  // LEFT
  distTile[0] =
      sqrt((pos_x - 16 - player->getPosX()) * (pos_x - 16 - player->getPosX()) +
           (pos_y + 16 - player->getPosY()) * (pos_y + 16 - player->getPosY()));
  // UP
  distTile[1] =
      sqrt((pos_x + 16 - player->getPosX()) * (pos_x + 16  - player->getPosX()) +
           (pos_y - 16 - player->getPosY()) * (pos_y - 16 - player->getPosY()));
  // RIGHT
  distTile[2] =
      sqrt((pos_x + 32 + 16 - player->getPosX()) * (pos_x + 32 + 16 - player->getPosX()) +
           (pos_y + 16 - player->getPosY()) * (pos_y + 16 - player->getPosY()));
  // DOWN
  distTile[3] =
      sqrt((pos_x + 16 - player->getPosX()) * (pos_x + 16 - player->getPosX()) +
           (pos_y + 32  - player->getPosY()) * (pos_y + 32  - player->getPosY()));
  float min = SCREEN_W;
  int minIndex = -1;
  for (int i = 0; i < 4; i++) {
    // std::cout << distTile[i] << " ";
    if (distTile[i] < min && tipoTile[i] != 0) {
      min = distTile[i];
      minIndex = i;
      
    }
  }
  std::cout << "Tile 'libera' " << minIndex << std::endl;
  switch (minIndex) {
  case 0:
    direzione = RIGHT;
    break;
  case 1:
    direzione = UP;
    break;
  case 2:
    direzione = LEFT;
    break;
  case 3:
    direzione = DOWN;
    break;
  default:
    direzione = -1;
    break;
  }
  // std::cout << "direzione " << direzione << "\n";
}

void Enemy::vola(Player *player, Map *mappa) {
  if (pos_x != player->getPosX()) {
    if (player->getPosX() > pos_x) {
      flip = false;
      pos_x += vel_x;
    } else {
      flip = true;
      pos_x -= vel_x;
    }
  }
  if (pos_y != player->getPosY()){
    if (player->getPosY() > pos_y) {

      pos_y += vel_y;
    }
    else{

      pos_y -= vel_y;
    }
  }
}