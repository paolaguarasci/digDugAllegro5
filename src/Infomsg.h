#ifndef INFOMSG_H
#define INFOMSG_H
#include "Object.h"

class Infomsg : public Object {
private:
    int pti;
    int time;
    ALLEGRO_FONT *font18 = NULL;

public:
  Infomsg();
  void destroy();
  void draw();
  void update();
  void setTime(int t ){ time = t;}
  void setPti(int p) { pti = p;}
};

#endif // INFOMSG_H