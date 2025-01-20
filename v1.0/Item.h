#ifndef _ITEM_H_
#define _ITEM_H_
#include "Game.h"
class Game;

class Item {
public:
    Game* game;
    int row;
    int col;
    name namei=unnamed;
    Item(Game* g,int r, int c, name n) : game(g), row(r), col(c), namei(n) {}
    virtual void update(int);
    virtual bool out();
};
#endif
