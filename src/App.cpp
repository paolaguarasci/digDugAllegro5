#include "App.h"

App::App() {
  srand(time(0));
  al_init();
  al_install_keyboard();
  al_init_primitives_addon();

  screen = new GestoreSchermi();
  screen->setState(LOAD);
  timer = new Timer();
  event_queue = al_create_event_queue();
  al_register_event_source(event_queue, al_get_keyboard_event_source());
  timer->addToEventQueue(event_queue);
  modtimer_time = FPS * 60;
  mappa = new Map();
  player = new Player();

  modality = 0;

  enemy1 = new Enemy(300, 400, -1);
  enemy2 = new Enemy(200, 345, 1);
  enemy3 = new Enemy(100, 200, -1);

  infoMsg = new Infomsg();

  arma = new Harpoon();
  obj.push_back(mappa);
  obj.push_back(arma);
  obj.push_back(enemy1);
  obj.push_back(enemy2);
  obj.push_back(enemy3);
  obj.push_back(player);
  obj.push_back(infoMsg);
  obj.push_back(screen);
  numEnemy = 3;
}

int App::Run(int argc, char *argv[]) {

  doexit=false;
  timer->start();
  screen->draw();

  // std::cout  << "Esco dal loading ";
  screen->setState(MENU);
  screen->setMod(modality);
  while(!doexit) {
    ALLEGRO_EVENT ev;
    al_wait_for_event(event_queue, &ev);
    if (ev.type == ALLEGRO_EVENT_KEY_UP && ev.keyboard.keycode == ALLEGRO_KEY_UP) {
      // std::cout  << "Ho premuto freccia su!\n";
      modality = 0;
    } else if (ev.type == ALLEGRO_EVENT_KEY_UP && ev.keyboard.keycode == ALLEGRO_KEY_DOWN) {
      // std::cout  << "Ho premuto freccia giu!\n";
      modality = 1;
    } else if (ev.type == ALLEGRO_EVENT_KEY_UP && ev.keyboard.keycode == ALLEGRO_KEY_ENTER) {
      // std::cout  << "Ho premuto invio!\n";
      doexit = true;
    }
    screen->setMod(modality);
    screen->update();
    screen->draw();
  }

  doexit=false;
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
      // case ALLEGRO_KEY_T:
      //   modTimer = true;
      //   break;
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
      if(player->isCol(*it)) doexit = true;     
    }
    
    // TODO: Modificare assolutamente questo schifezza!
    // if(arma->isCol(enemy1)) player->setScore(30);
    // if(arma->isCol(enemy2)) player->setScore(30);
    // if(arma->isCol(enemy3)) player->setScore(30);
    arma->isCol(enemy1);
    arma->isCol(enemy2);
    arma->isCol(enemy3);
    enemy1->insegui(player, mappa);
    enemy2->insegui(player, mappa);
    enemy3->insegui(player, mappa);
    
    if (!(enemy1->getAlive())) {
      // delete enemy;
      obj.remove(enemy1);
      // numEnemy -= 1;
    } 
    if (!(enemy2->getAlive())) {
      // delete enemy;
      obj.remove(enemy2);
      // numEnemy -= 1;
    } 
    if (!(enemy3->getAlive())) {
      // delete enemy;
      obj.remove(enemy3);
      // numEnemy -= 1;
    }
    numEnemy = 0;
    for (std::list<Object *>::iterator it = obj.begin(); it != obj.end();
         ++it) {
      if ((*it)->getType() == ENEMY) numEnemy++;
    }
    std::cout   << "Numero di nemici " << numEnemy << "\n"
                << "Mod a tempo " << (modality == 0 ? "NO" : "SI") << "\n" 
                << std::endl;
            
    // Fine schifezza
    player->setScore((3 - numEnemy) * 90);
    infoMsg->setPti(player->getScore());
    mappa->scava(player->getPosX(), player->getPosY(), player->getDir(),
                 player->getDirPrec());
    if (draw && al_is_event_queue_empty(event_queue)) {
      draw = false;
      for (Object *o : obj)
        o->draw();
    }
    if (modality == 1) { modTimer = true; }
    if(modTimer && modtimer_time > 0) {
      // std::cout << "Restano: " << modtimer_time / 60 << " secondi"<< std::endl;
      modtimer_time--;
      infoMsg->setTime(modtimer_time/FPS);
    }
    if(modtimer_time == 0 && modTimer) doexit = true;

    if (numEnemy == 0) doexit = true;
  }
  doexit = false;
  // std::cout  << "Esco dal loop";
  // std::cout  << "Punti alla fine.. " << player->getScore() << std::endl;
  screen->setState(DEAD);
  while(!doexit) {
  screen->setPunti(player->getScore(), numEnemy == 0);
    ALLEGRO_EVENT ev;
    al_wait_for_event(event_queue, &ev);
    if (ev.type == ALLEGRO_EVENT_KEY_UP && ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
      // std::cout  << "Ho premuto ESC!\n";
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
    // delete (*it);
    it = obj.erase(it);
  }
  al_destroy_event_queue(event_queue);
  al_uninstall_keyboard();
}