#ifndef CONST_H
#include <string>
const int FPS = 25.0;
const int SCREEN_W = 512; // 32 * 16
const int SCREEN_H = 512; // 32 * 16

const bool running = true;
const bool redraw = true;
const bool reload = false;

enum KEY { KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, KEY_SPACE };
enum TYPE { PLAYER, ENEMY, TILE, OTHER };
// enum DIREZIONE { UP = -1, DOWN = 1, RIGHT = 1, LEFT = -1 };
enum DIREZIONE { UP, DOWN, RIGHT, LEFT };
const std::string MAP_FOLDER = "assets/data/maps";
enum STATE { LOAD, GAME, DEAD };
#endif // CONTS_H