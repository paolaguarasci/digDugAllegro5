#include "App.h"
#include "Object.h"
#include "const.h"
#include "map/Map.h"
#include <allegro5/allegro_tiled.h>

App::App() {

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
  enemy = new Enemy();
  arma = new Harpoon();
  obj.push_back(mappa);
  ent.push_back(arma);
  ent.push_back(player);
  ent.push_back(enemy);
  gravity = 10;
  pos_x = player->getPosX();
  pos_y = player->getPosY();
  velx = player->getVelX();
  vely = player->getVelY();
  azione = player->getAzione();
  posizione = player->getPosizione();
  dir = "left";
  dir_prec = "";
}

int App::Run(int argc, char *argv[]) {

  while (!doexit) {
    ALLEGRO_EVENT ev;
    al_wait_for_event(event_queue, &ev);
    if (ev.type == ALLEGRO_EVENT_TIMER) {
      if (key[KEY_UP]) {
        pos_y = (pos_y <= 0 ? SCREEN_H - player->getDimY()
                            : pos_y - player->getVelY());
        azione = 1;
        posizione = (posizione <= 0 ? 2 : posizione - 1);
        vely -= 3;
        player->setAngolo(4.5);
        dir_prec = dir;
        dir = "up";
      }
      if (key[KEY_DOWN]) {
        azione = 3;
        vely += 3;
        pos_y += player->getVelY();
        posizione = (posizione >= 2 ? 0 : posizione + 1);
        player->setAngolo(4.70);
        dir_prec = dir;
        dir = "down";
      }
      if (key[KEY_LEFT]) {
        // pos_x = (pos_x <= player->getDimX() ? SCREEN_W - player->getDimX()
        //                                     : pos_x - player->getVelX());
        velx -= 3;
        azione = 3;
        posizione = (posizione <= 0 ? 2 : posizione - 1);
        player->setAngolo(0);
        dir_prec = dir;
        dir = "left";
      }
      if (key[KEY_RIGHT]) {
        azione = 1;
        velx += 3;
        posizione = (posizione >= 2 ? 0 : posizione + 1);
        player->setAngolo(0);
        dir_prec = dir;
        dir = "right";
      }
      if (key[KEY_SPACE]) {
        arma->start(player->getPosX(), player->getPosY());
        mappa->scava(player->getPosX(), player->getPosY());
      }
      draw = true;
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

      case ALLEGRO_KEY_SPACE:
        key[KEY_SPACE] = true;
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
      case ALLEGRO_KEY_SPACE:
        key[KEY_SPACE] = false;
        break;
      case ALLEGRO_KEY_ESCAPE:
        doexit = true;
        break;
      }
    }
    enemy->update();
    arma->isColl(enemy);
    if (!(enemy->getLive())) {
      // delete enemy;
      ent.remove(enemy);
    }
    bool isFloor = mappa->isBlack((player->getPosX()), (player->getPosY()));
    // gravity = isFloor ? 0 : 10;
    // vely += gravity;
    // player-> =
    //     (pos_y <= 0 ? SCREEN_H - player->getDimY() : pos_y -
    //     player->getVelY());
    // pos_x = (pos_x <= player->getDimX() ? SCREEN_W - player->getDimX()
    //                                     : pos_x - player->getVelX());
    player->update(pos_x + velx, pos_y + vely, azione, posizione);
    mappa->scava(player->getPosX(), player->getPosY());
    std::cout << "Direzione: " << dir << " (prec: " << dir_prec << ")\n";
    if (draw && al_is_event_queue_empty(event_queue)) {
      draw = false;
      for (Object *o : obj)
        o->draw();
      for (Entities *e : ent)
        e->draw();
      player->draw();
      // player->init();
      screen->draw();
    }
  }
  return 0;
}

App::~App() {
  for (Object *o : obj)
    delete o;
  for (Entities *e : ent)
    delete e;
  al_uninstall_keyboard();
  al_destroy_timer(timer);
  al_destroy_event_queue(event_queue);
}