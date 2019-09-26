#include "Map.h"
#include "Object.h"

Map::Map() {
  bitmap = al_load_bitmap("assets/img/terrain.png");
  init();
}
void Map::init() {
  std::ifstream inFile;
  int x;
  inFile.open("assets/map/00.map");
  if (!inFile) {
    // std::cout  << "Unable to open file";
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
    // std::cout  << n << " ";
    tileset.push_back(new Tile());
    tileset.back()->init(n, pos_x, pos_y, k, z);
    k++;
    if (k >= 16) {
      k = 0;
      z++;
    }
  }
}
void Map::destroy() {
  for (auto it = tileset.begin(); it != tileset.end();) {
    (*it)->destroy();
    delete (*it);
    it = tileset.erase(it);
  }
}
void Map::draw() {
  ALLEGRO_BITMAP *tmp = al_create_sub_bitmap(bitmap, 0, 8, 96, 192);
  al_draw_scaled_rotated_bitmap(tmp, 0, 0, 0, 32 * 3, 6, 2.5, 0, 0);
  for (Tile *t : tileset)
    t->draw();
}

int Map::nextInDir(int pos_x, int pos_y, std::string dir) {
  Tile *tile = NULL;
  int redDot_x = -1;
  int redDot_y = -1;

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
  // std::cout  << redDot_x << " " << redDot_y << "\n";
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

void Map::scava(int pos_x, int pos_y, DIREZIONE dir, DIREZIONE dir_prec) {
  Tile *tile = NULL;
  Tile *tilePrec = NULL;
  for (Tile *t : tileset) {
    float areaX_a = t->getPosX();
    float areaX_b = t->getPosX() + 32;
    float areaY_a = t->getPosY();
    float areaY_b = t->getPosY() + 32;

    if (pos_y > areaY_a && pos_y < areaY_b && pos_x > areaX_a &&
        pos_x < areaX_b) {
      tile = t;
      if (dir_prec == dir) {
        switch (dir_prec) {
        case RIGHT:
          tilePrec = getTile(tile->getX() - 1, tile->getY());
          break;
        case LEFT:
          tilePrec = getTile(tile->getX() + 1, tile->getY());
          break;
        case UP:
          tilePrec = getTile(tile->getX(), tile->getY() + 1);
          break;
        case DOWN:
          tilePrec = getTile(tile->getX(), tile->getY() - 1);
          break;
        }
      } else {
        if (dir_prec == LEFT && dir == UP)
          tilePrec = getTile(tile->getX(), tile->getY() + 1);
        if (dir_prec == LEFT && dir == DOWN)
          tilePrec = getTile(tile->getX(), tile->getY() - 1);
        if (dir_prec == RIGHT && dir == UP)
          tilePrec = getTile(tile->getX(), tile->getY() + 1);
        if (dir_prec == RIGHT && dir == DOWN)
          tilePrec = getTile(tile->getX(), tile->getY() - 1);

        if (dir_prec == UP && dir == LEFT)
          tilePrec = getTile(tile->getX() + 1, tile->getY());
        if (dir_prec == UP && dir == RIGHT)
          tilePrec = getTile(tile->getX() - 1, tile->getY());
        if (dir_prec == DOWN && dir == LEFT)
          tilePrec = getTile(tile->getX() + 1, tile->getY());
        if (dir_prec == DOWN && dir == RIGHT)
          tilePrec = getTile(tile->getX() - 1, tile->getY());
      }
    }
  }
  if (tile != NULL && tile->getTipo() != -1 && tilePrec != NULL) {
    if (dir == dir_prec) {
      switch (dir_prec) {
      case RIGHT:
      case LEFT:
        tilePrec->setOverX(true);
        break;
      case UP:
      case DOWN:
        tilePrec->setOverY(true);
        break;
      }
    }
    if (dir != dir_prec) {
      if ((dir_prec == LEFT && dir == DOWN) || (dir_prec == UP && dir == RIGHT))
        tilePrec->setCurva(0);
      if ((dir_prec == LEFT && dir == UP) || (dir_prec == DOWN && dir == RIGHT))
        tilePrec->setCurva(1);
      if ((dir_prec == RIGHT && dir == DOWN) || (dir_prec == UP && dir == LEFT))
        tilePrec->setCurva(2);
      if ((dir_prec == RIGHT && dir == UP) || (dir_prec == DOWN && dir == LEFT))
        tilePrec->setCurva(3);
    }
    switch (dir) {
    case RIGHT:
      tile->setLastR(true);
      break;
    case LEFT:
      tile->setLastL(true);
      break;
    case UP:
      tile->setLastU(true);
      break;
    case DOWN:
      tile->setLastD(true);
      break;
    }
  }
}

void Map::update() {
  for (auto it = tileset.begin(); it != tileset.end(); ++it) {
    (*it)->update();
  }
}

Tile *Map::getTile(int x, int y) {
  auto tile = find_if(tileset.begin(), tileset.end(), [x, y](Tile *a) {
    return a->getX() == x && a->getY() == y;
  });
  return (*tile);
}