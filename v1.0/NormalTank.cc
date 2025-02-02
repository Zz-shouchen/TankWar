#include "NormalTank.h"
#include "Laser.h"
#include "Game.h"
#include "Player.h"
#include "Bullet.h"
#include <stdlib.h>

void NormalTank::update(int){
    int su = rand() % 3 + 1;
    int randx = rand() % 10;
    if(move_factor >= 5)randx = rand() % 3 + 8;
    if(shoot_factor <= 0){su = 3;shoot_factor++;};
    init_pair(2,COLOR_RED,COLOR_WHITE);
    attron(COLOR_PAIR(2));
    run(su,randx);
    attroff(COLOR_PAIR(2));
    int sh=rand() % 12;
    if(shoot_factor >= 10 && sh == 0){
        game->reitems.push_back(new Bullet(game,row,col,toward));
        shoot_factor = 0;
    }
    else if(shoot_factor >= 30){
        game->reitems.push_back(new Bullet(game,row,col,toward));
        shoot_factor =- 1;
    }
    else if(shoot_factor < 0){
        game->reitems.push_back(new Bullet(game,row,col,toward));
        shoot_factor = 0;
    }
    else shoot_factor++;
}
