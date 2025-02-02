#ifndef _BULLET_H_
#define _BULLET_H_
#include "RemoveItem.h"
#include "Game.h"

class Bullet : public RemoveItem {
public:
    towards toward = UP;//the direction of the bullet
    Game* game;//in this game
    Bullet(Game* g,int x,int y,towards t): RemoveItem(g,x,y,bullet),game(g),toward(t) {};
    void update(int);//update the bullet's position, it doesn't need input parameter, but player's update needs.
    bool out();//check if the bullet is out of the map
};
#endif
