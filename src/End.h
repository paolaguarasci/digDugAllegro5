#ifndef END_H
#define END_H
#include "Object.h"

class End : public Object {
private:
  ALLEGRO_DISPLAY *display;
  ALLEGRO_FONT *font46 = NULL;
  ALLEGRO_FONT *font24 = NULL;
  int punti;

public:
  End(int);
  void destroy();
  void draw();
  void update(){};
  ALLEGRO_DISPLAY *getDisplay();
  void fullscreen();
  void drawIcon();

};

#endif // END_H