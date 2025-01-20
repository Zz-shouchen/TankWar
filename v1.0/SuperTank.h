#ifndef _SUPERTANK_H_
#define _SUPERTANK_H_
#include "EnemyTank.h"

class SuperTank : public EnemyTank {
public:
    bool is_mineing=false;
    Game* game;
    SuperTank(Game* g, int x, int y,towards t):EnemyTank(g,x,y,SUP_HEALTH,t,supertank),game(g){}
    void update(int);
};
#endif
