#ifndef SCHERMO_H
#define SCHERMO_H
#include "Object.h"

class Screen : public Object {
private:
  ALLEGRO_DISPLAY *display;

public:
  Screen();
  void destroy();
  void draw();
  void update(){};
  ALLEGRO_DISPLAY *getDisplay();
  void fullscreen();
  void drawIcon();
};

#endif // schermo_H