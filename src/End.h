#ifndef END_H
#define END_H
#include "Object.h"

class End : public Object {
private:
  ALLEGRO_DISPLAY *display;

public:
  End();
  void destroy();
  void draw();
  void update(){};
  ALLEGRO_DISPLAY *getDisplay();
  void fullscreen();
  void drawIcon();
};

#endif // END_H