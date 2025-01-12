#ifndef _MINE_H_
#define _MINE_H_
#include "UnmoveItem.h"

class Mine : public UnmoveItem {
public:
    Game* game;
    bool exist=true;
    Mine(Game* g, int x, int y): game(g),UnmoveItem(g,x,y,mine){};
    void update(int);
    bool Bomb_check();
    bool out();
};
#endif