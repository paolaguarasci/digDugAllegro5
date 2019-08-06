#ifndef HARPOON_H
#define HARPOON_H
#include "Entities.h"
#include <string>
class Harpoon : public Entities {
private:
  int gittata;
  bool isLive;
  int inizial_pos_x;
  int inizial_pos_y;
  float angolo;
  std::string dir;

public:
  Harpoon();
  ~Harpoon();
  void update();
  void draw();
  float getVelX();
  float getVelY();
  int getDimX();
  int getDimY();
  int getPosX();
  int getPosY();
  int getAzione();
  int getPosizione();
  void setLive(bool);
  void start(int _pos_x, int _pos_y, std::string);
  bool isColl(Entities *e);
};
#endif // HARPOON_H