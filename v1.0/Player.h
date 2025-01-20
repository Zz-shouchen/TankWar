#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "Game.h"
#include "Tank.h"

class Player :public Tank{
public:
    Game* game;
    Player(Game* game, int x, int y): Tank(game,x,y,PL_HEALTH,DOWN,player), game(game){};
    void update(int);
    bool arround(int x, int y);
};
#endif
