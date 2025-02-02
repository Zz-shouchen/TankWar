#ifndef _NORMALTANK_H_
#define _NORMALTANK_H_
#include "EnemyTank.h"

class NormalTank : public EnemyTank {
public:
    Game* game;
    NormalTank(Game* game, int x, int y, towards t): EnemyTank(game, x, y, NOR_HEALTH, t, normaltank), game(game){}
    void update(int);
};
#endif
