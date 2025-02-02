#include "Bullet.h"
#include "RemoveItem.h"
#include "EnemyTank.h"

void Bullet::update(int){
    if(out())return;//out of the map
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);//set color
    attron(COLOR_PAIR(4));//set color
    //move bullet
    switch(toward){
        case UP:
            game->paintat(row, col, '^');
            row--;
            break;
        case DOWN:
            game->paintat(row, col, 'V');
            row++;
            break;
        case LEFT:
            game->paintat(row, col, '<');
            col--;
            break;
        case RIGHT:
            game->paintat(row, col, '>');
            col++;
            break;
        default:
            break;
    }
    attroff(COLOR_PAIR(4));//reset color
    list<Tank*>::iterator it = game->tanks.begin();//iterator for tanks
    //check hits
    while(it != game->tanks.end()){
        if((*it)->namei == player && (*it)->row == row && (*it)->col == col){game->hit(*it, this);row = MAXROW + 1;col = MAXCOL + 100;}
        else if((*it)->namei != player && (*it)->collide(row, col)){game->hit(*it, this);row = MAXROW + 100;}
        it++;
    }
}

bool Bullet::out(){
    if(game->coll_obs_check(row, col) || row > MAXROW || col > MAXCOL || row < 0 || col < 0)return true;
    return false;
}
