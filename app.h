#ifndef APP_H
#define APP_H

#include "_const.h"
#include "map.h"
#include "player.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_tiled.h>
#include <iostream>
enum KEY { KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT };

class App {
private:
  bool key[4] = {false, false, false, false};
  bool doexit = false;
  bool draw = true;
  int pos_x;
  int pos_y;
  int azione;
  int posizione;
  ALLEGRO_DISPLAY *display = NULL;
  ALLEGRO_EVENT_QUEUE *event_queue = NULL;
  ALLEGRO_TIMER *timer = NULL;
  Map *mappa = NULL;
  Player *player = NULL;

public:
  App();
  ~App();

  int Run(int argc, char *argv[]);
};

#endif // APP_H