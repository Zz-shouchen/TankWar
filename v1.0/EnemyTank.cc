#include "EnemyTank.h"
#include "Player.h"
#include "Obstacle.h"
#include <stdlib.h>

void EnemyTank::update(int){
    return;//do nothing
}

bool EnemyTank::boundary(){
    //check if the tank is out of boundary
    switch(toward){
        case UP:
            return row <= 2;
        case DOWN:
            return row >= MAXROW - 2;
        case LEFT:
            return col <= 2;
        case RIGHT:
            return col >= MAXCOL - 2;
    }
    return false;
}

void EnemyTank::run(int su, int randx){
    //move the tank
    switch(toward){
        case UP:
            game->paintat(row, col - 1, 'C');//paint the tank
            game->paintat(row, col, 'M');
            game->paintat(row, col + 1, 'D');
            if(su == 3)break;//su == 3 means the tank doesn's need to move
            if(boundary()){//check if the tank is out of boundary
                row++;
                toward = DOWN;
                break;
            }
            if(randx < 7){//move up
                row--;
                move_factor = 0;
                if(game->coll_obs_check(row, col))row++;
            }
            else if(randx < 8){toward = LEFT;move_factor++;}//turn left
            else if(randx < 9){toward = RIGHT;move_factor++;}//turn right
            else {//move down
                row++;
                move_factor = 0;
                if(game->coll_obs_check(row, col))row--;
            }
            break;
        case DOWN:
            game->paintat(row, col - 1, 'C');
            game->paintat(row, col, 'W');
            game->paintat(row, col + 1, 'D');
            if(su == 3)break;
            if(boundary()){
                row--;
                toward = UP;
                break;
            }
            if(randx < 7){
                row++;
                move_factor = 0;
                if(game->coll_obs_check(row, col))row--;
            }
            else if(randx < 8){toward = LEFT;move_factor++;}
            else if(randx < 9){toward = RIGHT;move_factor++;}
            else {
                row--;
                move_factor = 0;
                if(game->coll_obs_check(row, col))row++;
            }
            break;
        case LEFT:
            game->paintat(row - 1, col, 'n');
            game->paintat(row, col, 'E');
            game->paintat(row + 1, col, 'U');
            if(su == 3)break;
            if(boundary()){
                col++;
                toward = RIGHT;
                break;
            }
            if(randx < 7){
                col--;
                move_factor = 0;
                if(game->coll_obs_check(row, col))col++;
                }
            else if(randx < 8){toward = UP;move_factor++;}
            else if(randx < 9){toward = DOWN;move_factor++;}
            else {
                col++;
                move_factor = 0;
                if(game->coll_obs_check(row, col))col--;
            }
            break;
        case RIGHT:
            game->paintat(row - 1, col, 'n');
            game->paintat(row, col, '3');
            game->paintat(row + 1, col, 'U');
            if(su == 3)break;
            if(boundary()){
                col--;
                toward = LEFT;
                break;
            }
            if(randx < 7){
                col++;
                move_factor = 0;
                if(game->coll_obs_check(row, col))col--;
            }
            else if(randx < 8){toward = UP;move_factor++;}
            else if(randx < 9){toward = DOWN;move_factor++;}
            else {
                col--;
                move_factor = 0;
                if(game->coll_obs_check(row, col))col++;
            }
            break;
        default:
            //should never happen
            toward = UP;
            break;
    }
}

void EnemyTank::pursue(int catc){//catc == 1 means the tank catches the player
    if(catc == 1){
        if(rand()%2 == 0){//change the direction randomly, 50% for up and down, 50% for left and right
            if(row > game->pl->row){
                row--;
                if(game->coll_obs_check(row, col))row++;
                toward = UP;
                }
            else if(row < game->pl->row){
                row++;
                if(game->coll_obs_check(row, col))row--;
                toward = DOWN;
                }
        }
        else {
            if(col > game->pl->col){
                col--;
                if(game->coll_obs_check(row, col))col++;
                toward = LEFT;
            }
            else if(col < game->pl->col){
                col++;
                if(game->coll_obs_check(row, col))col--;
                toward = RIGHT;
            }
        }
        if((rand() + 1) % 4 == 0){//a chance to shoot(25%), the tank doesn't shoot if it moves
            game->reitems.push_back(new Bullet(game, row, col, toward));
            shoot_factor = 0;//reset the shoot_factor
        }
    }
}
