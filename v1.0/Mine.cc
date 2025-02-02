#include "Mine.h"
#include "Game.h"
#include "Player.h"

void Mine::update(int){
    init_pair(7, COLOR_GREEN, COLOR_WHITE);
    attron(COLOR_PAIR(7));
    game->paintat(row, col, '#');
    attroff(COLOR_PAIR(7));
    if(Bomb_check())game->hit(game->pl, this);
}

bool Mine::Bomb_check(){//check if the mine is bombed by the player
    for(int i =- 1;i <= 1;i++){
        for(int j =- 1;j <= 1;j++){
            if(row + i == game->pl->row && col + j == game->pl->col){
                game->paintat(row, col, '*');
                exist = false;
                return true;
            }
        }
    }
    return false;
}

bool Mine::out(){
    return !exist;
}
