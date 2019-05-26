#include <allegro5/allegro.h>
#include <iostream>
using namespace std;
int main(int argc, char **argv) {
  ALLEGRO_DISPLAY *display = NULL;
  ALLEGRO_EVENT_QUEUE *event_queue = NULL;

  if (!al_init()) {
    cerr << "failed to initialize allegro!\n";
    return -1;
  }

  display = al_create_display(640, 480);
  if (!display) {
    cerr << "failed to create display!\n";
    return -1;
  }

  al_install_keyboard();

  event_queue = al_create_event_queue();
  al_register_event_source(event_queue, al_get_keyboard_event_source());

  while (true) {
    ALLEGRO_EVENT ev;
    al_wait_for_event(event_queue, &ev);
    if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
      break;
    }

    // Schermo nero
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_flip_display();
  }

  al_uninstall_keyboard();
  al_destroy_display(display);

  return 0;
}