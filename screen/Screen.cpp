#include "Screen.h"
#include "../Object.h"
#include "../const.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

Screen::Screen() : Object() {
  display = al_create_display(SCREEN_H, SCREEN_W);
  al_init_image_addon();

  icon = al_load_bitmap("../assets/img/ico.png");
  al_convert_mask_to_alpha(icon, al_map_rgb(0, 255, 0));
  // TODO: l'icona appare ma lo schermo resta nero. 
  // Il gioco funziona però!
  // Aggiornamento: su ubuntu funziona, sul mac no.
  al_set_display_icon(display, icon);

  windowWidth = al_get_display_width(display);
  windowHeight = al_get_display_height(display);
  al_set_window_title(display, "Dig Dug - Classic NES Game");

  sx = windowWidth / (float)SCREEN_W;
  sy = windowHeight / (float)SCREEN_H;
  al_identity_transform(&t);
  al_scale_transform(&t, sx, sy);
  // display = al_create_display(SCREEN_W, SCREEN_H);
}
Screen::~Screen() {
  al_destroy_display(display);
  al_shutdown_image_addon();
  al_destroy_bitmap(icon);
}

void Screen::draw() { al_flip_display(); }
ALLEGRO_DISPLAY *Screen::getDisplay() { return display; }

void Screen::fullscreen() {
  al_use_transform(&t);
  al_set_display_flag(
      display, ALLEGRO_FULLSCREEN_WINDOW,
      !(al_get_display_flags(display) & ALLEGRO_FULLSCREEN_WINDOW));
}