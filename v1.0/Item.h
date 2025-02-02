#ifndef _ITEM_H_
#define _ITEM_H_
#include "Game.h"

class Item {
public:
    Game* game;
    int row = 0;
    int col = 0;
    name namei=unnamed;
    Item(Game* g,int r, int c, name n) : game(g), row(r), col(c), namei(n) {}
    virtual void update(int);
    virtual bool out();
};
#endif
