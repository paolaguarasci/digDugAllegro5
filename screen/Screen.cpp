#include "Screen.h"
#include "../Object.h"
#include "../const.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

Screen::Screen() : Object() {
  al_init_image_addon();
  display = al_create_display(SCREEN_W, SCREEN_H);
}
Screen::~Screen() { al_destroy_display(display); }

void Screen::draw() { al_flip_display(); }
ALLEGRO_DISPLAY *Screen::getDisplay() { return display; }