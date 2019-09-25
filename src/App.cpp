#include "App.h"

App::App() {
  al_init();
  al_install_keyboard();
  al_init_primitives_addon();

  screen = new GestoreSchermi();
  screen->setState(LOAD);
  timer = new Timer();
  event_queue = al_create_event_queue();
  al_register_event_source(event_queue, al_get_keyboard_event_source());
  timer->addToEventQueue(event_queue);

  mappa = new Map();
  player = new Player();
  enemy1 = new Enemy(300, 400);
    enemy2 = new Enemy(200, 345);
      enemy3 = new Enemy(100, 200);

  arma = new Harpoon();
  obj.push_back(mappa);
  obj.push_back(arma);
  obj.push_back(enemy1);
    obj.push_back(enemy2);
      obj.push_back(enemy3);
  obj.push_back(player);
  obj.push_back(screen);
}

int App::Run(int argc, char *argv[]) {

  timer->start();
  screen->draw();
  screen->setState(GAME);

  while (!doexit) {
    ALLEGRO_EVENT ev;
    al_wait_for_event(event_queue, &ev);

    if (ev.type == ALLEGRO_EVENT_TIMER) {

      if (key[KEY_UP]) {
        player->moveUp();
      }
      if (key[KEY_DOWN]) {
        player->moveDown();
      }
      if (key[KEY_LEFT]) {
        player->moveLeft();
      }
      if (key[KEY_RIGHT]) {
        player->moveRight();
      }
      if (key[KEY_SPACE]) {
        arma->start(player->getPosX(), player->getPosY(), player->getDir());
      }
      draw = true;
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
      player->resetPos();
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

    for (std::list<Object *>::iterator it = obj.begin(); it != obj.end();
         ++it) {
      (*it)->update();
    }

    for (std::list<Object *>::iterator it = obj.begin(); it != obj.end();
         ++it) {
      player->isCol(*it);
    }
    
    // TODO: Modificare assolutamente questo schifezza!
    arma->isCol(enemy1);
    arma->isCol(enemy2);
    arma->isCol(enemy3);
    if (!(enemy1->getAlive())) {
      // delete enemy;
      obj.remove(enemy1);
    }
    enemy2->insegui(player, mappa);
        if (!(enemy2->getAlive())) {
      // delete enemy;
      obj.remove(enemy2);
    }
    enemy2->insegui(player, mappa);
        if (!(enemy3->getAlive())) {
      // delete enemy;
      obj.remove(enemy3);
    }
    enemy3->insegui(player, mappa);
    // Fine schifezza

    mappa->scava(player->getPosX(), player->getPosY(), player->getDir(),
                 player->getDirPrec());
    if (draw && al_is_event_queue_empty(event_queue)) {
      draw = false;
      for (Object *o : obj)
        o->draw();
    }
  }
  doexit = false;
  std::cout << "Esco dal loop";
  screen->setState(DEAD);
  while(!doexit) {
    ALLEGRO_EVENT ev;
    al_wait_for_event(event_queue, &ev);
    if (ev.type == ALLEGRO_EVENT_KEY_UP && ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
      std::cout << "Ho premuto ESC!\n";
      doexit = true;
    }
    screen->update();
    screen->draw();
  }

  return 0;
}

App::~App() {
  for (std::list<Object *>::iterator it = obj.begin(); it != obj.end();) {
    (*it)->destroy();
    delete (*it);
    it = obj.erase(it);
  }
  al_destroy_event_queue(event_queue);
  al_uninstall_keyboard();
}