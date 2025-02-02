#ifndef _MAP_H_
#define _MAP_H_
#include "Game.h"
#include "Obstacle.h"

class Map {
public:
    Game* game;
    size_t nseed = 0;
    size_t nseed_privous = 0;
    size_t num = 0;
    int width, height;
    Map(Game* g, int h, int w,size_t n): game(g), width(w), height(h), nseed(n){};
    void update();
    void update_map0();
    void update_map1();
    void update_map_rand();
};
#endif
