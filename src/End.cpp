#include "End.h"

End::End(int p) {
  font46 = al_load_ttf_font("assets/font/nintendo.ttf", 46, 0);
  font24 = al_load_ttf_font("assets/font/nintendo.ttf", 24, 0);
  display = al_create_display(SCREEN_H, SCREEN_W);
  std::cout << "Costruisco end";
  // p = 999;
  punti = p;
  std::cout << "    Punti alla costruzione " << punti <<std::endl;
}
void End::destroy() {
  al_destroy_display(display);
  al_destroy_font(font46);
  al_destroy_font(font24);
}

void End::draw() {
  al_flip_display();
  al_clear_to_color(al_map_rgb(0, 0, 0));
  std::string pti = std::to_string(punti) + " punti";
  std::cout << "punti " << punti <<std::endl;
  al_draw_text(font46, al_map_rgb(255, 255, 255), SCREEN_W / 2, (SCREEN_H / 2) - 50, ALLEGRO_ALIGN_CENTRE, "GAME OVER");
  al_draw_text(font24, al_map_rgb(255, 255, 255), SCREEN_W / 2, (SCREEN_H / 2) + 50, ALLEGRO_ALIGN_CENTRE, pti.c_str());
}

void End::fullscreen() {
  al_set_display_flag(
      display, ALLEGRO_FULLSCREEN_WINDOW,
      !(al_get_display_flags(display) & ALLEGRO_FULLSCREEN_WINDOW));
}