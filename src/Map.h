#ifndef MAP_H
#define MAP_H

#include "Object.h"
#include "Tile.h"

#include <fstream>
#include <list>
#include <vector>

class Map : public Object {
private:
  std::vector<Tile *> tileset;
  std::string file;
  std::vector<int> data;

public:
  Map();

  void destroy();
  void init();
  void draw();
  void update();
  //int nextInDir(int pos_x, int pos_y, std::string dir);
  void scava(int pos_x, int pos_y, DIREZIONE dir, DIREZIONE dir_prec);
  Tile *getTile(int x, int y);
  Tile* getTileByXY(int x, int y);
};

#endif // Map.h