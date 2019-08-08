#ifndef MAP_H
#define MAP_H

#include "Object.h"
#include "Tile.h"

#include <fstream>
#include <list>

class Map : public Object {
private:
  std::list<Tile *> tileset;
  std::string file;
  std::list<int> data;

public:
  Map();

  void destroy();
  void init();
  void draw();
  void update();
  int nextInDir(int pos_x, int pos_y, std::string dir);
  void scava(int pos_x, int pos_y);
};

#endif // Map.h