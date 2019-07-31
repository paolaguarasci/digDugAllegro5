#ifndef schermo_H
#define schermo_H

#include <allegro5/allegro.h>

class Screen {
private:
  ALLEGRO_DISPLAY *display;

public:
  Screen();
  ~Screen();
  void draw();
};

#endif // schermo_H