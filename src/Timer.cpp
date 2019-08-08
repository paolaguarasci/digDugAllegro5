#include "Timer.h"
Timer::Timer() { timer = al_create_timer(1.0 / FPS); }
void Timer::destroy() {
  Object::destroy();
  al_destroy_timer(timer);
}
void Timer::start() { al_start_timer(timer); }
void Timer::addToEventQueue(ALLEGRO_EVENT_QUEUE *ev) {
  al_register_event_source(ev, al_get_timer_event_source(timer));
}