#include "Screen.h"
#include "_const.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

Screen::Screen() {
  al_init_image_addon();
  display = al_create_display(SCREEN_W, SCREEN_H);
}
Screen::~Screen() { al_destroy_display(display); }

void Screen::draw() { al_flip_display(); }