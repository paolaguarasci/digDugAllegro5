#pragma once

class entities {
 private:
  float pos_x;
  float pos_y;
  float dim;
  std::string path_img = "";

 public:
  entities();
  ~entities();
};

entities::entities() {}

entities::~entities() {}
