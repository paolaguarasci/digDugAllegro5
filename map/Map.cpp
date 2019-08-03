#include "Map.h"
#include "../Object.h"
#include "../const.h"
#include <algorithm>
#include <allegro5/allegro_image.h>
#include <fstream>
#include <iostream>

Map::Map() { init(); }
void Map::init() {
  std::ifstream inFile;
  int x;
  inFile.open("../assets/map/00.map");
  if (!inFile) {
    std::cout << "Unable to open file";
    // exit(1); // terminate with error
  }
  while (inFile >> x) {
    data.push_back(x);
  }
  inFile.close();
  float pos_x = 0;
  float pos_y = 0;
  int k = 0;
  int z = 0;
  for (int n : data) {
    pos_x = 32 * k;
    pos_y = 32 * z;
    if (n == 0)
      tileset.push_back(new Tile(0, pos_x, pos_y));
    if (n == 1)
      tileset.push_back(new Tile(1, pos_x, pos_y));
    if (n == 2)
      tileset.push_back(new Tile(2, pos_x, pos_y));
    if (n == 3)
      tileset.push_back(new Tile(3, pos_x, pos_y));
    k++;
    if (k >= 16) {
      k = 0;
      z++;
    }
  }
}
Map::~Map() {}
void Map::draw() {
  for (Tile *t : tileset)
    t->draw();
}

bool Map::isBlack(int pos_x, int pos_y) {
  Tile *tile = NULL;
  for (Tile *t : tileset) {
    float areaX_a = t->getPosX();
    float areaX_b = t->getPosX() + 32;
    float areaY_a = t->getPosY();
    float areaY_b = t->getPosY() + 32;

    if (pos_y > areaY_a && pos_y < areaY_b && pos_x > areaX_a &&
        pos_x < areaX_b) {
      tile = t;
    }
  }
  if (tile != NULL)
    return tile->getTipo() == 0;
  else
    return NULL;
}

void Map::scava(int pos_x, int pos_y) {
  Tile *tile = NULL;
  for (Tile *t : tileset) {
    float areaX_a = t->getPosX();
    float areaX_b = t->getPosX() + 32;
    float areaY_a = t->getPosY();
    float areaY_b = t->getPosY() + 32;

    if (pos_y > areaY_a && pos_y < areaY_b && pos_x > areaX_a &&
        pos_x < areaX_b) {
      tile = t;
    }
  }
  if (tile != NULL)
    // return tile->getTipo() == 0;
    tile->setTipo(0);
}

void Map::update() {}