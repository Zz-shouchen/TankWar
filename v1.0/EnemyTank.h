#ifndef _ENEMYTANK_H_
#define _ENEMYTANK_H_
#include "Tank.h"
#include "Game.h"
#include "Bullet.h"

class EnemyTank : public Tank {
public:
    int shoot_factor = 0;//a factor to control the shoot
    int move_factor = 0;
    int update_cou = 0;
    int mine_count = 0;
    Game* game;
    EnemyTank(Game* game, int x, int y,int heal,towards t,name n):Tank(game,x,y,heal,t,n),game(game){};
    virtual void update(int);//to update the tank
    bool boundary();//to check if the tank is out of boundary
    void run(int su, int randx);//to move the tank
    void pursue(int catc);//to pursue the player
};
#endif
