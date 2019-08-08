#include "Screen.h"

Screen::Screen() : Object() {
  al_init_image_addon();
  display = al_create_display(SCREEN_H, SCREEN_W);
  al_set_window_title(display, "Dig Dug - Classic NES Game");
}
void Screen::destroy() { al_destroy_display(display); }

void Screen::draw() { al_flip_display(); }

void Screen::fullscreen() {
  al_set_display_flag(
      display, ALLEGRO_FULLSCREEN_WINDOW,
      !(al_get_display_flags(display) & ALLEGRO_FULLSCREEN_WINDOW));
}