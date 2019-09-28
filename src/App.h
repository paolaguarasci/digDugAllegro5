#ifndef APP_H
#define APP_H

#include "Enemy.h"
#include "GestoreSchermi.h"
#include "Harpoon.h"
#include "Map.h"
#include "Object.h"
#include "Player.h"
#include "Timer.h"
#include "Infomsg.h"
#include <iostream>
#include <list>
#include <string>

class App {
private:
  bool key[5] = {false, false, false, false, false};
  bool doexit = false;
  bool draw = true;
  bool modTimer = false;
  
  int modtimer_time;
  int numEnemy;
  int modality;
  ALLEGRO_EVENT_QUEUE *event_queue = NULL;

  Map *mappa = NULL;
  Player *player = NULL;
  Enemy *enemy1 = NULL;
  Enemy *enemy2 = NULL;
  Enemy *enemy3 = NULL;

  GestoreSchermi *screen = NULL;
  Harpoon *arma;
  Timer *timer;

  Infomsg* infoMsg = NULL;

  std::list<Object *> obj;
  std::list<Enemy *> enemy;
public:
  App();
  ~App();

  int Run(int argc, char *argv[]);
};

#endif // APP_H