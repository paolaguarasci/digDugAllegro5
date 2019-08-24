#include "GestoreSchermi.h"

GestoreSchermi::GestoreSchermi() {
  stato = LOAD;
  currentScreen = new Splash();
}
void GestoreSchermi::destroy() { currentScreen->destroy(); }

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