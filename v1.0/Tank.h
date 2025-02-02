#ifndef _TANK_H_
#define _TANK_H_
#include "Game.h"
#include "Item.h"

class Tank : public Item {
public:
    Game* game;
    int health;
    towards toward;
    Tank(Game* g, int x, int y, int he, towards tow, name n): Item(g, x, y, n), game(g), health(he), toward(tow) {};
    virtual void update(int);
    bool out();
    bool collide(int, int);
};
#endif
