#ifndef _BULLET_H_
#define _BULLET_H_
#include "RemoveItem.h"
#include "Game.h"

class Bullet : public RemoveItem {
public:
    towards toward;
    Game* game;
    Bullet(Game* g,int x,int y,towards t): RemoveItem(g,x,y,bullet),game(g),toward(t) {};
    void update(int);
    bool out();
};
#endif