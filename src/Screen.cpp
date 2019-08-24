#include "Screen.h"

Screen::Screen() { display = al_create_display(SCREEN_H, SCREEN_W); }
void Screen::destroy() { al_destroy_display(display); }

void Screen::draw() {
  al_flip_display();
  al_clear_to_color(al_map_rgb(0, 0, 0));
}

void Screen::fullscreen() {
  al_set_display_flag(
      display, ALLEGRO_FULLSCREEN_WINDOW,
      !(al_get_display_flags(display) & ALLEGRO_FULLSCREEN_WINDOW));
}