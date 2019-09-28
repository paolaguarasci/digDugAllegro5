#ifndef PLAYER_H
#define PLAYER_H

#include "Object.h"

class Player : public Object {
private:
  int score;
  int lives;

public:
  Player();
  void init();
  void destroy();
  void update();
  void draw();

  int getScore() { return score; }
  void setScore(int score) { Player::score = score; }
  int getLives() { return lives; }

  void moveUp();
  void moveDown();
  void moveLeft();
  void moveRight();

  void resetPos() { posizione = 1; }

};

#endif // PLAYER_H