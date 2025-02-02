#include "Obstacle.h"
#include "Game.h"
#include "Item.h"

void Obstacle::update(int){
    init_pair(10, COLOR_BLACK, COLOR_WHITE);
    attron(COLOR_PAIR(10));
    game->paintat(row, col, '\\');
    attroff(COLOR_PAIR(10));
}

bool Obstacle::coll(int x, int y){//check
    for(int i =- 1;i <= 1;i++){
        for(int j =- 1;j <= 1;j++){
            if(x + i == row && y + j == col){
                return true;
            }
        }
    }
    return false;
}
