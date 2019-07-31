#ifndef MAP_H
#define MAP_H

#include "Object.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_tiled.h>
#include <iostream>
#define MAP_FOLDER "../assets/data/maps"

class Map : public Object {
private:
  ALLEGRO_MAP *map;
  int map_total_width;
  int map_total_height;

public:
  Map();
  ~Map();
  void draw();
  void update() {}
};

#endif // Map.h