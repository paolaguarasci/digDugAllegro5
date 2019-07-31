#ifndef ENTITIES_H
#define ENTITIES_H
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <string>

class Entities {
private:
  float pos_x = 0;
  float pos_y = 0;
  int dim_x = 0;
  int dim_y = 0;
  std::string path_img = "";
  // ALLEGRO_BITMAP *bitmap = NULL;

public:
  Entities();
  ~Entities();
  void update();
  void draw();
};

#endif // ENTITIES_H
