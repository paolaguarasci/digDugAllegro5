#ifndef schermo_H
#define schermo_H
#include "Object.h"
#include <allegro5/allegro.h>

class Screen : public Object {
private:
  ALLEGRO_DISPLAY *display;
  ALLEGRO_TRANSFORM t;
  float sx;
  float sy;
  float windowWidth;
  float windowHeight;
  ALLEGRO_BITMAP *icon;

public:
  Screen();
  ~Screen();
  void draw();
  void update(){};
  ALLEGRO_DISPLAY *getDisplay();
  void fullscreen();
};

#endif // schermo_H