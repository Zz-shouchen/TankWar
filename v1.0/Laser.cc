#include "Laser.h"
#include "Player.h"
#include "Tank.h"

void Laser::update(int) {//update the laser
    if(towe == LEFT || towe == RIGHT)game->paintat(row, col, '~');
    if(towe == UP || towe == DOWN)game->paintat(row, col, '$');
    if(game->tanks.empty())return;
    list<Tank*>::iterator it = game->tanks.begin();
    while(it != game->tanks.end()){
        if((*it)->namei == player && (*it)->row == row && (*it)->col == col)game->hit(*it, this);
        else if((*it)->collide(row, col))game->hit(*it, this);
        it++;
    }
}
