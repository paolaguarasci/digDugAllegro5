#ifndef MENU_H
#define MENU_H
#include "Object.h"

class Menu : public Object {
private:
  ALLEGRO_DISPLAY *display;
  ALLEGRO_FONT *font46 = NULL;

public:
  Menu();
  void destroy();
  void draw();
  void update(){};
  ALLEGRO_DISPLAY *getDisplay();
  void fullscreen();
  void drawIcon();
};

#endif // MENU_H