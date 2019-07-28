#ifndef MAP_H
#define MAP_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_tiled.h>
#include <iostream>
#define MAP_FOLDER "../assets/data/maps"
#define DEBUG 0

class Map {
private:
  ALLEGRO_MAP *map;
  int map_total_width;
  int map_total_height;

public:
  Map();
  ~Map();
  void draw();
};

#endif // Map.h