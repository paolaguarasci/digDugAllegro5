#include "Splash.h"

Splash::Splash() : Object() {
  al_init_image_addon();
  display = al_create_display(SCREEN_H, SCREEN_W);
  al_set_window_title(display, "Dig Dug - Classic NES Game");
}
void Splash::destroy() { al_destroy_display(display); }

void Splash::draw() {
  al_flip_display();
  al_clear_to_color(al_map_rgb(0, 0, 0));
}

void Splash::fullscreen() {
  al_set_display_flag(
      display, ALLEGRO_FULLSCREEN_WINDOW,
      !(al_get_display_flags(display) & ALLEGRO_FULLSCREEN_WINDOW));
}