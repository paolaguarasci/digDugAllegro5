#include "End.h"

End::End() {
  font46 = al_load_ttf_font("assets/font/nintendo.ttf", 46, 0);

  display = al_create_display(SCREEN_H, SCREEN_W);
  std::cout << "Costruisco end";
}
void End::destroy() {
  al_destroy_display(display);
  al_destroy_font(font46);
}

void End::draw() {
  al_flip_display();
  al_clear_to_color(al_map_rgb(0, 0, 0));
  al_draw_text(font46, al_map_rgb(255, 255, 255), SCREEN_H / 2, (SCREEN_W / 2), ALLEGRO_ALIGN_CENTRE, "GAME OVER");
}

void End::fullscreen() {
  al_set_display_flag(
      display, ALLEGRO_FULLSCREEN_WINDOW,
      !(al_get_display_flags(display) & ALLEGRO_FULLSCREEN_WINDOW));
}