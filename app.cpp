#include "app.h"
#include "Object.h"
#include "_const.h"
#include "map.h"

App::App() {
  pos_x = 32 * 2;
  pos_y = SCREEN_H - (32 * 3);
  azione = 1;
  posizione = 1;
  al_init();
  al_install_keyboard();
  screen = new Screen();
  event_queue = al_create_event_queue();
  timer = al_create_timer(1 / FPS);
  al_register_event_source(event_queue, al_get_keyboard_event_source());
  al_register_event_source(event_queue, al_get_timer_event_source(timer));
  al_start_timer(timer);
  mappa = new Map();
  player = new Player();
  obj.push_back(mappa);
  obj.push_back(player);
}

int App::Run(int argc, char *argv[]) {

  while (!doexit) {
    ALLEGRO_EVENT ev;
    al_wait_for_event(event_queue, &ev);
    if (ev.type == ALLEGRO_EVENT_TIMER) {
      if (key[KEY_UP]) {
        pos_y = (pos_y <= 0 ? SCREEN_H - player->getDimY()
                            : pos_y - player->getVelY());
        azione = 0;
        posizione = (posizione <= 0 ? 2 : posizione - 1);
      }
      if (key[KEY_DOWN]) {
        azione = 2;
        pos_y += player->getVelY();
        posizione = (posizione >= 2 ? 0 : posizione + 1);
      }
      if (key[KEY_LEFT]) {
        pos_x = (pos_x <= player->getDimX() ? SCREEN_W - player->getDimX()
                                            : pos_x - player->getVelX());
        azione = 3;
        posizione = (posizione <= 0 ? 2 : posizione - 1);
      }
      if (key[KEY_RIGHT]) {
        azione = 1;
        pos_x = (pos_x >= (SCREEN_W - player->getDimX())
                     ? 0
                     : pos_x + player->getVelX());
        posizione = (posizione >= 2 ? 0 : posizione + 1);
      }
      draw = true;
      player->update(pos_x, pos_y, azione, posizione);
    } else if (ev.type == ALLEGRO_EVENT_KEY_DOWN &&
               ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
      break;
    } else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
      switch (ev.keyboard.keycode) {
      case ALLEGRO_KEY_UP:
        key[KEY_UP] = true;
        break;

      case ALLEGRO_KEY_DOWN:
        key[KEY_DOWN] = true;
        break;

      case ALLEGRO_KEY_LEFT:
        key[KEY_LEFT] = true;
        break;

      case ALLEGRO_KEY_RIGHT:
        key[KEY_RIGHT] = true;
        break;
      }
    } else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
      posizione = 1;
      switch (ev.keyboard.keycode) {
      case ALLEGRO_KEY_UP:
        key[KEY_UP] = false;
        break;

      case ALLEGRO_KEY_DOWN:
        key[KEY_DOWN] = false;
        break;

      case ALLEGRO_KEY_LEFT:
        key[KEY_LEFT] = false;
        break;

      case ALLEGRO_KEY_RIGHT:
        key[KEY_RIGHT] = false;
        break;

      case ALLEGRO_KEY_ESCAPE:
        doexit = true;
        break;
      }
    }
    if (draw && al_is_event_queue_empty(event_queue)) {
      draw = false;
      for (Object *o : obj)
        o->draw();
      screen->draw();
    }
  }
  return 0;
}

App::~App() {
  for (Object *o : obj)
    delete o;
  al_uninstall_keyboard();
  al_destroy_timer(timer);
  al_destroy_event_queue(event_queue);
}