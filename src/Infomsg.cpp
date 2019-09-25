#include "Infomsg.h"

Infomsg::Infomsg() {
  time = -1;
  pti = 100;
  font18 = al_load_ttf_font("assets/font/nintendo.ttf", 18, 0);
}

void Infomsg::destroy() {
    al_destroy_font(font18);
}

void Infomsg::draw() { 
  std::string infomsg = "";
  if(time != -1)
    infomsg += std::to_string(pti) + " punti     " + std::to_string(time) + " secondi";
  else
    infomsg += std::to_string(pti) + " punti";
  std::cout<<infomsg<<std::endl;
  al_draw_text(font18, al_map_rgb(255, 255,255), (SCREEN_W/2) - 15, 20, ALLEGRO_ALIGN_CENTRE, infomsg.c_str());
 }

void Infomsg::update() {}