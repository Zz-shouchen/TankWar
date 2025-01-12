#ifndef _LASERTANK_H_
#define _LASERTANK_H_
#include "EnemyTank.h"

class LaserTank : public EnemyTank {
public:
    int mine_privious=0;
    int laser_privious=0;
    bool is_mineing=false;
    Game* game;
    LaserTank(Game* g, int x, int y,towards t):EnemyTank(g,x,y,LAS_HEALTH,t,lasertank),game(g){};
    void update(int);
};

#endif