#ifndef GESTORESCHERMI_H
#define GESTORESCHERMI_H
#include "End.h"
#include "Object.h"
#include "Screen.h"
#include "Splash.h"
#include "Menu.h"

class GestoreSchermi : public Object {
private:
  Object *currentScreen;
  STATE stato;
  STATE oldStato;

public:
  GestoreSchermi();
  void destroy();
  void draw();
  void update();
  ALLEGRO_DISPLAY *getDisplay();
  void setState(STATE _stato) {
    oldStato = stato;
    stato = _stato;
    std::cout << "\n" << oldStato << " " << stato << "\n";
  }
  STATE getState() { return stato; }
  void setMod(int m){
    if(stato == MENU) {
      currentScreen->setMod(m);
    }
  }
};

#endif // GESTORESCHERMI_H