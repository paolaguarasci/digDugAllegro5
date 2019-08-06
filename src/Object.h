#ifndef OBJECT_H
#define OBJECT_H
#include <iostream>
class Object {
public:
  Object();
  virtual ~Object();
  virtual void draw() = 0;
  void update();
};

#endif // OBJECT_H