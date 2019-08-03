#ifndef MAP_H
#define MAP_H

#include "../Object.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
// #include <allegro5/allegro_tiled.h>
#include "Tile.h"
#include <iostream>
#include <list>
#include <string>
#define MAP_FOLDER "../assets/data/maps"
enum DIREZIONE { UP, DOWN, RIGHT, LEFT };
class Map : public Object {
private:
  std::list<Tile *> tileset;
  std::string file;
  std::list<int> data;

public:
  Map();
  ~Map();
  void init();
  void draw();
  void update();
  bool isBlack(int pos_x, int pos_y);
  void scava(int pos_x, int pos_y);
};

#endif // Map.h