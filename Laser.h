#ifndef _LASER_H_
#define _LASER_H_
#include "Game.h"
#include "RemoveItem.h"

class Laser : public RemoveItem {
    Game* game;
    towards towe;
public:
    Laser(Game* game, int x, int y,towards di): RemoveItem(game,x, y,laser), game(game), towe(di) {};
    void update(int);
};
#endif