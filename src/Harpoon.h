#ifndef HARPOON_H
#define HARPOON_H
#include "Object.h"

class Harpoon : public Object {
private:
  int gittata;
  int inizial_pos_x;
  int inizial_pos_y;

public:
  Harpoon();
  void destroy();
  void update();
  void draw();
  void start(int _pos_x, int _pos_y, DIREZIONE _dir);
};
#endif // HARPOON_H