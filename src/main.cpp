#include "App.h"
using namespace std;
int main(int argc, char *argv[]) {
  App *app = new App();
  int result = app->Run(argc, argv);
  delete app;
  return result;
}