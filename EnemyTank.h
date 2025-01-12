#ifndef _ENEMYTANK_H_
#define _ENEMYTANK_H_
#include "Tank.h"
#include "Game.h"
#include "Bullet.h"

class EnemyTank : public Tank{
public:
    int shoot_privious=0;
    int move_privious=0;
    int update_cou=0;
    int mine_count=0;
    Game* game;
    EnemyTank(Game* game, int x, int y,int heal,towards t,name n):Tank(game,x,y,heal,t,n),game(game){};
    virtual void update(int);
    bool boundary();
    void run(int su, int randx);
    void pursue(int catc);
};
#endif