#include "Map.h"
#include "Object.h"
#include "const.h"
#include <algorithm>
#include <allegro5/allegro_image.h>
#include <fstream>
#include <iostream>

Map::Map() { init(); }
void Map::init() {
  std::ifstream inFile;
  int x;
  inFile.open("assets/map/00.map");
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
      tileset.push_back(new Tile(0, pos_x, pos_y, k, z));
    if (n == 1)
      tileset.push_back(new Tile(1, pos_x, pos_y, k, z));
    if (n == 2)
      tileset.push_back(new Tile(2, pos_x, pos_y, k, z));
    if (n == 3)
      tileset.push_back(new Tile(3, pos_x, pos_y, k, z));
    k++;
    if (k >= 16) {
      k = 0;
      z++;
    }
  }
}
Map::~Map() {
  for (Tile *t : tileset)
    delete t;
}
void Map::draw() {
  for (Tile *t : tileset)
    t->draw();
}

int Map::nextInDir(int pos_x, int pos_y, std::string dir) {
  Tile *tile = NULL;
  int redDot_x;
  int redDot_y;

  if (dir.compare("left") == 0) {
    redDot_x = (pos_x / 32) - 1;
    redDot_y = (pos_y / 32);

  } else if (dir.compare("up") == 0) {
    redDot_x = (pos_x / 32);
    redDot_y = (pos_y / 32) - 1;

  } else if (dir.compare("right") == 0) {
    redDot_x = (pos_x / 32) + 1;
    redDot_y = (pos_y / 32);

  } else if (dir.compare("down") == 0) {
    redDot_x = (pos_x / 32);
    redDot_y = (pos_y / 32) + 1;
  }
  std::cout << redDot_x << " " << redDot_y << "\n";
  for (Tile *t : tileset) {
    if (t->getX() == redDot_x && t->getY() == redDot_y) {
      tile = t;
    }
  }
  if (tile != NULL)
    return tile->getTipo();
  else
    return -1;
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