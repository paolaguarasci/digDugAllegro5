#ifndef schermo_H
#define schermo_H
#include "../Object.h"
#include <allegro5/allegro.h>

class Screen : public Object {
private:
  ALLEGRO_DISPLAY *display;

public:
  Screen();
  ~Screen();
  void draw();
  void update(){};
  ALLEGRO_DISPLAY *getDisplay();
};

#endif // schermo_H