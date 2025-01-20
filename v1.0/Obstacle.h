#ifndef _OBSTACLE_H_
#define _OBSTACLE_H_
#include "Item.h"

class Obstacle : public Item{
public:
    Game* game;
    Obstacle(Game* g, int x, int y): Item(g,x,y,obstacle),game(g){};
    void update(int);
    bool coll(int, int);
};
#endif
