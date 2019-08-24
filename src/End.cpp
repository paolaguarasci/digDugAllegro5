#include "End.h"

End::End() { display = al_create_display(SCREEN_H, SCREEN_W); }
void End::destroy() { al_destroy_display(display); }

void End::draw() {
  al_flip_display();
  al_clear_to_color(al_map_rgb(0, 0, 0));
}

void End::fullscreen() {
  al_set_display_flag(
      display, ALLEGRO_FULLSCREEN_WINDOW,
      !(al_get_display_flags(display) & ALLEGRO_FULLSCREEN_WINDOW));
}