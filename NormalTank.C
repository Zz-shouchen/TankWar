#include "NormalTank.h"
#include "Laser.h"
#include "Game.h"
#include "Player.h"
#include "Bullet.h"
#include <stdlib.h>

void NormalTank::update(int){
    int su=rand()%3+1;
    int randx=rand()%10;
    if(move_privious>=5)randx=rand()%3+8;
    if(shoot_privious<=0){su=3;shoot_privious++;};
    init_pair(2,COLOR_RED,COLOR_WHITE);
    attron(COLOR_PAIR(2));
    run(su,randx);
    attroff(COLOR_PAIR(2));
    int sh=rand()%12;
    if(shoot_privious>=10 && sh==0){
        game->reitems.push_back(new Bullet(game,row,col,toward));
        shoot_privious=0;
    }
    else if(shoot_privious>=30){
        game->reitems.push_back(new Bullet(game,row,col,toward));
        shoot_privious=-1;
    }
    else if(shoot_privious<0){
        game->reitems.push_back(new Bullet(game,row,col,toward));
        shoot_privious=0;
    }
    else shoot_privious++;
    // if(collide(game->pl->row,game->pl->col))game->pl->health-=10;
}




//CMD//UP

//CWD//DOWN

// n  // n 
// E  // 3
// U  // U
//LEFT//RIGHT