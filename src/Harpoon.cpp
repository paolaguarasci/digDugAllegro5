#include "Harpoon.h"

Harpoon::Harpoon() {
  gittata = 200;
  bitmap = al_load_bitmap("assets/img/harpoon.png");
  dim_x = 30;
  dim_y = 5;
  alive = false;
  pos_x = 0;
  pos_y = 0;
  inizial_pos_x = 0;
  inizial_pos_y = 0;
  type = WEAPON;
  dir = LEFT;
  collidable = true;
}
void Harpoon::destroy() { al_destroy_bitmap(bitmap); }
void Harpoon::start(int _pos_x, int _pos_y, DIREZIONE _dir) {
  pos_y = _pos_y + 16;
  pos_x = _pos_x + 10;
  inizial_pos_x = _pos_x;
  inizial_pos_y = _pos_y;
  dir = _dir;
  if (dir == UP)
    angolo = 4.5;
  if (dir == DOWN)
    angolo = 1.5;
  if (dir == LEFT)
    angolo = 3;
  if (dir == RIGHT)
    angolo = 0;
  update();
}
void Harpoon::update() {
  if (dir == UP) {
    if (pos_y < inizial_pos_y + gittata) {
      pos_y -= 7;
      alive = true;
    } else {
      alive = false;
    }
  }

  if (dir == DOWN) {
    if (pos_y < inizial_pos_y + gittata) {
      pos_y += 7;
      alive = true;
    } else {
      alive = false;
    }
  }

  if (dir == LEFT) {
    if (pos_x > inizial_pos_x - gittata) {
      pos_x -= 7;
      alive = true;
    } else {
      alive = false;
    }
  }

  if (dir == RIGHT) {
    if (pos_x < inizial_pos_x + gittata) {
      pos_x += 7;
      alive = true;
    } else {
      alive = false;
    }
  }
}
void Harpoon::draw() {
  if (alive) {
    // Soluzione precedente (senza rotazione)
    // al_convert_mask_to_alpha(bitmap, al_map_rgb(0, 255, 0));
    // al_draw_bitmap_region(bitmap, 19, 8, dim_x, dim_y, pos_x, pos_y, 0);
    // Soluzione attuale (con rotazione)
    ALLEGRO_BITMAP *tmp = al_create_sub_bitmap(bitmap, 19, 8, dim_x, dim_y);
    al_convert_mask_to_alpha(bitmap, al_map_rgb(0, 255, 0));
    al_draw_scaled_rotated_bitmap(tmp, 0, 0, pos_x, pos_y, 1.25, 1.25, angolo,
                                  0);
    update();
    al_destroy_bitmap(tmp);
  }
}