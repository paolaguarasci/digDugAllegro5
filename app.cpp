#pragma once
#include "_const.cpp"
#include "input.cpp"
#include <allegro5/allegro.h>
#include <allegro5/allegro_tiled.h>
#include <iostream>

class App {
private:
  bool key[4] = {false, false, false, false};
  bool doexit = false;
  bool redraw = true;
  int red, green, blue = 0;
  ALLEGRO_DISPLAY *display = NULL;
  ALLEGRO_EVENT_QUEUE *event_queue = NULL;
  ALLEGRO_TIMER *timer = NULL;

public:
  App();
  ~App();

  int Run(int argc, char *argv[]);
};

App::App() {
  al_init();
  display = al_create_display(SCREEN_W, SCREEN_H);
  al_install_keyboard();
  event_queue = al_create_event_queue();
  timer = al_create_timer(1 / FPS);
  al_register_event_source(event_queue, al_get_keyboard_event_source());
  al_register_event_source(event_queue, al_get_timer_event_source(timer));
  al_start_timer(timer);
}

int App::Run(int argc, char *argv[]) {
  while (!doexit) {
    ALLEGRO_EVENT ev;
    al_wait_for_event(event_queue, &ev);
    if (ev.type == ALLEGRO_EVENT_TIMER) {
      if (key[KEY_UP]) {
        red += 10;
      }
      if (key[KEY_DOWN]) {
        green += 10;
      }
      if (key[KEY_LEFT]) {
        blue += 10;
      }
      if (key[KEY_RIGHT]) {
        red = 0;
        green = 0;
        blue = 0;
      }
      redraw = true;
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
    if (redraw && al_is_event_queue_empty(event_queue)) {
      redraw = false;
      al_clear_to_color(al_map_rgb(red, green, blue));
      al_flip_display();
    }
  }
  return 0;
}

App::~App() {
  al_uninstall_keyboard();
  al_destroy_timer(timer);
  al_destroy_event_queue(event_queue);
  al_destroy_display(display);
}
