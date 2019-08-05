#include "App.h"
#include "Object.h"
#include "const.h"
#include "map/Map.h"
#include <allegro5/allegro_primitives.h>

App::App() {

  al_init();
  al_install_keyboard();
  al_init_primitives_addon();
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
        dir = "up";
        if (mappa->nextInDir(player->getPosX(), player->getPosY(), dir) != 0) {
          pos_y -= player->getVelY() - 2;
        } else {
          pos_y -= player->getVelY();
        }
        azione = 1;
        posizione = (posizione <= 0 ? 2 : posizione - 1);
        player->setAngolo(4.5);
        dir_prec = dir;
      }
      if (key[KEY_DOWN]) {
        dir = "down";
        if (mappa->nextInDir(player->getPosX(), player->getPosY(), dir) != 0) {
          pos_y += player->getVelY() - 2;
        } else {
          pos_y += player->getVelY();
        }
        azione = 3;
        posizione = (posizione >= 2 ? 0 : posizione + 1);
        player->setAngolo(4.70);
        dir_prec = dir;
      }
      if (key[KEY_LEFT]) {
        dir = "left";
        if (mappa->nextInDir(player->getPosX(), player->getPosY(), dir) != 0) {
          pos_x -= player->getVelX() - 2;
        } else {
          pos_x -= player->getVelX();
        }
        azione = 3;
        posizione = (posizione <= 0 ? 2 : posizione - 1);
        player->setAngolo(0);
        dir_prec = dir;
      }
      if (key[KEY_RIGHT]) {
        dir = "right";
        if (mappa->nextInDir(player->getPosX(), player->getPosY(), dir) != 0) {
          pos_x += player->getVelX() - 2;
        } else {
          pos_x += player->getVelX();
        }
        azione = 1;
        posizione = (posizione >= 2 ? 0 : posizione + 1);
        player->setAngolo(0);
        dir_prec = dir;
      }
      if (key[KEY_SPACE]) {
        // arma->start(player->getPosX(), player->getPosY(), dir);
        screen->fullscreen();
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
    // bool isFloor = mappa->isBlack((player->getPosX()),
    // (player->getPosY()));
    //////////////////////////////
    if (dir.compare("down") == 0 && dir_prec.compare("right") == 0) {
      while ((pos_x + 16) % 32 != 0) {
        pos_x++;
      }
    }
    if (dir.compare("up") == 0 && dir_prec.compare("right") == 0) {
      while ((pos_x + 16) % 32 != 0) {
        pos_x++;
      }
    }

    if (dir.compare("down") == 0 && dir_prec.compare("left") == 0) {
      while ((pos_x - 16) % 32 != 0) {
        pos_x--;
      }
    }
    if (dir.compare("up") == 0 && dir_prec.compare("left") == 0) {
      while ((pos_x - 16) % 32 != 0) {
        pos_x--;
      }
    }

    //////////////////////////////
    if (dir.compare("left") == 0 && dir_prec.compare("down") == 0) {
      while ((pos_y + 16) % 32 != 0) {
        pos_y++;
      }
    }
    if (dir.compare("left") == 0 && dir_prec.compare("up") == 0) {
      while ((pos_y - 16) % 32 != 0) {
        pos_y--;
      }
    }
    if (dir.compare("right") == 0 && dir_prec.compare("up") == 0) {
      while ((pos_y - 16) % 32 != 0) {
        pos_y--;
      }
    }
    if (dir.compare("right") == 0 && dir_prec.compare("down") == 0) {
      while ((pos_y + 16) % 32 != 0) {
        pos_y++;
      }
    }

    // if ((player->getPosX() - 16) % 32 == 0 &&
    //     (player->getPosY() - 16) % 32 == 0) {
    //   std::cout << "sono al centro di una mattonella!\n";
    // }
    //////////////////////////////
    // player->update(pos_x + velx, pos_y + vely, azione, posizione);

    player->update(pos_x, pos_y, azione, posizione);
    mappa->scava(player->getPosX(), player->getPosY());
    // std::cout << "Direzione: " << dir << " (prec: " << dir_prec << ")\n";
    if (draw && al_is_event_queue_empty(event_queue)) {
      draw = false;
      for (Object *o : obj)
        o->draw();
      for (Entities *e : ent)
        e->draw();
      player->draw();
      // player->init();
      // std::cout << pos_x / 32 << ", " << pos_y / 32 << "\n";
      // al_draw_filled_circle(pos_x, pos_y, 5, al_map_rgb(255, 0, 255));
      // for (int i = 0; i < 16; i++) {
      //   for (int j = 0; j < 16; j++) {
      //     al_draw_filled_circle((32 * i) + 16, (32 * j) + 16, 1.5,
      //                           al_map_rgb(255, 0, 0));
      //     al_draw_rectangle((32 * i), (32 * j), (32 * i) + 32, (32 * j) +
      //     32,
      //                       al_map_rgb(0, 255, 0), 1);
      //   }
      // }

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