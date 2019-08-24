#include "Splash.h"

Splash::Splash() : Object() {
  al_init_image_addon();
  vel = 1;
  display = al_create_display(SCREEN_H, SCREEN_W);
  al_set_window_title(display, "Dig Dug - Classic NES Game");
  bitmap = al_load_bitmap("assets/img/title.png");
}
void Splash::destroy() { al_destroy_display(display); }

void Splash::draw() {
  al_flip_display();
  al_clear_to_color(al_map_rgb(0, 0, 0));
  if (vel < 0) {
    vel = 1;
  } else if (vel > 15) {
    vel = 15;
  }
  int alfa;
  for (alfa = 0; alfa <= 255; alfa += vel) {
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_tinted_bitmap(bitmap, al_map_rgba(alfa, alfa, alfa, alfa),
                          (SCREEN_W - 157) / 2, (SCREEN_H - 37) / 2, 0);
    al_flip_display();
    al_rest(0.005);
  }
  alfa = 0;
  for (alfa = 0; alfa <= 255; alfa += vel) {
    al_clear_to_color(al_map_rgba(0, 0, 0, 0));
    al_draw_tinted_bitmap(bitmap,
                          al_map_rgba(255 - alfa, 255 - alfa, 255 - alfa, alfa),
                          (SCREEN_W - 157) / 2, (SCREEN_H - 37) / 2, 0);
    al_flip_display();
    al_rest(0.005); // Não é necessário caso haja controle de FPS
  }
}

void Splash::fullscreen() {
  al_set_display_flag(
      display, ALLEGRO_FULLSCREEN_WINDOW,
      !(al_get_display_flags(display) & ALLEGRO_FULLSCREEN_WINDOW));
}