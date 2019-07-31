#include "map.h"
#include "Object.h"
#include "_const.h"

#include <allegro5/allegro_image.h>
#include <allegro5/allegro_tiled.h>
Map::Map() {
  std::cout << MAP_FOLDER << "level1.tmx";
  map = al_open_map(MAP_FOLDER, "level1.tmx");
  map_total_width = al_get_map_width(map) * al_get_tile_width(map);
  map_total_height = al_get_map_height(map) * al_get_tile_height(map);
}
Map::~Map() { al_free_map(map); }
void Map::draw() {
  al_draw_map_region(map, map_x, map_y, screen_width, screen_height, 0, 0, 0);
}