#ifndef CONST_H
#define CONST_H

const float FPS = 60.0;
const int SCREEN_W = 640;
const int SCREEN_H = 480;
enum KEY { KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT };

bool running = true;
bool redraw = true;
bool reload = false;

int map_x = 0, map_y = 0;
int screen_width = 640;
int screen_height = 480;

#endif // const