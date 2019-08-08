#ifndef TIMER_H
#define TIMER_H
#include "Object.h"
class Timer : public Object {

private:
  ALLEGRO_TIMER *timer = NULL;

public:
  Timer();
  void destroy();
  void start();
  void addToEventQueue(ALLEGRO_EVENT_QUEUE *ev);
};

#endif