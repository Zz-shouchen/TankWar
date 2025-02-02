#include "LaserTank.h"
#include "Laser.h"
#include "Game.h"
#include "Player.h"
#include "Bullet.h"
#include "Mine.h"
#include <stdlib.h>

void LaserTank::update(int){//update the tank
    update_cou++;
    if(mine_count < 10 && update_cou >= 100){
        game->reitems.push_back(new Mine(game, row, col));//add a mine
        is_mineing = true;
        mine_count++;
        update_cou = 0;
    }
    int catc = 0;
    int su = rand() % 3 + 1;//a factor
    int randx = rand() % 10;
    if(move_factor >= 5)randx = rand() % 3 + 8;
    if(shoot_factor <= 0){su = 3;shoot_factor++;};
    if(rand() % 5 == 0 && !is_mineing && laser_factor >= 4 && !(game->Laser_exist)){
        game->Laser_add(row, col, toward);
        shoot_factor = 0;
        game->laserTank_can_move = false;
        laser_factor = 0;
    }
    else laser_factor++;
    if(game->laserTank_can_move == false){
        su = 3;
    }
    init_pair(11, COLOR_CYAN, COLOR_MAGENTA);
    attron(COLOR_PAIR(11));
    if(rand() % 2 == 0){catc = 1;su = 3;shoot_factor = 0;}
    run(su, randx);//run the tank
    pursue(catc);//pursue the player
    attroff(COLOR_PAIR(11));
    int sh = rand() % 4;
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
