#include "SuperTank.h"
#include "Laser.h"
#include "Game.h"
#include "Player.h"
#include "Bullet.h"
#include "Mine.h"
#include <stdlib.h>

void SuperTank::update(int){
    update_cou++;
    if(mine_count < 10 && update_cou >= 100){
        game->reitems.push_back(new Mine(game, row, col));
        is_mineing = true;
        mine_count++;
        update_cou = 0;
    }
    int catc = 0;
    int su = rand()%3+1;
    int randx = rand()%10;
    if(move_factor >= 5)randx=rand() % 3 + 8;
    if(shoot_factor <= 0){su=3;shoot_factor++;};
    init_pair(5, COLOR_GREEN, COLOR_BLUE);
    attron(COLOR_PAIR(5));
    if(rand() % 2 == 0){catc = 1;su = 3;shoot_factor = 0;}
    run(su, randx);
    pursue(catc);
    attroff(COLOR_PAIR(5));
    int sh=rand() % 4;
    if(shoot_factor >= 6 && sh == 0){
        game->reitems.push_back(new Bullet(game, row, col, toward));
        shoot_factor = 0;
    }
    else if(shoot_factor >= 15){
        game->reitems.push_back(new Bullet(game, row, col, toward));
        shoot_factor = -1;
    }
    else if(shoot_factor < 0){
        game->reitems.push_back(new Bullet(game, row, col, toward));
        shoot_factor = 0;
    }
    else shoot_factor++;
    is_mineing = false;
}
