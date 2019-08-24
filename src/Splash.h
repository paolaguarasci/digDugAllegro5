#ifndef SPLASH_H
#define SPLASH_H
#include "Object.h"

class Splash : public Object {
private:
  ALLEGRO_DISPLAY *display;

public:
  Splash();
  void destroy();
  void draw();
  void update(){};
  ALLEGRO_DISPLAY *getDisplay();
  void fullscreen();
  void drawIcon();
};

#endif // sPLASH_H