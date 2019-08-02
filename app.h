#ifndef APP_H
#define APP_H

#include "Map.h"
#include "const.h"
#include "entities/Enemy.h"
#include "entities/Player.h"
#include "screen/Screen.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_tiled.h>
#include <iostream>
#include <list>
enum KEY { KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT };

class App {
private:
  bool key[4] = {false, false, false, false};
  bool doexit = false;
  bool draw = true;
  int pos_x = 0;
  int pos_y = 0;
  int velx;
  int vely;
  int azione = 0;
  int posizione = 0;
  ALLEGRO_EVENT_QUEUE *event_queue = NULL;
  ALLEGRO_TIMER *timer = NULL;
  Map *mappa = NULL;
  Player *player = NULL;
  Enemy *enemy = NULL;
  Screen *screen = NULL;
  std::list<Object *> obj;
  std::list<Entities *> ent;
  float gravity;

public:
  App();
  ~App();

  int Run(int argc, char *argv[]);
};

#endif // APP_H