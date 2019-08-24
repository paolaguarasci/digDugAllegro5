#include "GestoreSchermi.h"

GestoreSchermi::GestoreSchermi() {
  al_init_font_addon();
  al_init_ttf_addon();
  stato = LOAD;
  currentScreen = new Splash();
}

void GestoreSchermi::destroy() {
  currentScreen->destroy();
  al_shutdown_font_addon();
  if (bitmap != NULL)
    al_destroy_bitmap(bitmap);
}

void GestoreSchermi::draw() { currentScreen->draw(); }

void GestoreSchermi::update() {
  if (oldStato != stato) {
    oldStato = stato;
    // std::cout << oldStato << " " << stato << "\n";
    currentScreen->destroy();
    switch (stato) {
    case LOAD:
      currentScreen = new Splash();
      std::cout << "LOAD\n";
      break;
    case GAME:
      currentScreen = new Screen();
      std::cout << "GAME\n";
      break;
    case DEAD:
      currentScreen = new End();
      break;

    default:
      break;
    }
  }
}