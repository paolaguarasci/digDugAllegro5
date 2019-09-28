#include "Menu.h"

Menu::Menu() {
  font46 = al_load_ttf_font("assets/font/nintendo.ttf", 46, 0);

  display = al_create_display(SCREEN_H, SCREEN_W);
  al_set_window_title(display, "Dig Dug - Classic NES Game");
  // std::cout  << "Costruisco Menu";
  Object::mod = 0;
}
void Menu::destroy() {
  al_destroy_display(display);
  al_destroy_font(font46);
}

void Menu::draw() {
  al_flip_display();
  al_clear_to_color(al_map_rgb(0, 0, 0));
  // std::cout  << "Selezione : " << mod << std::endl;
  if (mod == 0) {
    al_draw_text(font46, al_map_rgb(255, 0, 0), SCREEN_W / 2, (SCREEN_H / 2) - 30, ALLEGRO_ALIGN_CENTRE, "Mod classic");
    al_draw_text(font46, al_map_rgb(255, 255, 255), SCREEN_W / 2, (SCREEN_H / 2) + 30, ALLEGRO_ALIGN_CENTRE, "Mod a tempo");
  } else if (mod == 1) {
        al_draw_text(font46, al_map_rgb(255,255, 255), SCREEN_W / 2, (SCREEN_H / 2) - 30, ALLEGRO_ALIGN_CENTRE, "Mod classic");
    al_draw_text(font46, al_map_rgb(255, 0, 0), SCREEN_W / 2, (SCREEN_H / 2) + 30, ALLEGRO_ALIGN_CENTRE, "Mod a tempo");
  } else {
        al_draw_text(font46, al_map_rgb(255, 255, 255), SCREEN_W / 2, (SCREEN_H / 2) - 30, ALLEGRO_ALIGN_CENTRE, "Mod classic");
    al_draw_text(font46, al_map_rgb(255, 255, 255), SCREEN_W / 2, (SCREEN_H / 2) + 30, ALLEGRO_ALIGN_CENTRE, "Mod a tempo");
  }
}

void Menu::fullscreen() {

}
