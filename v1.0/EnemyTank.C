#include "EnemyTank.h"
#include "Game.h"
#include "Player.h"
#include "Obstacle.h"
#include <stdlib.h>

void EnemyTank::update(int){

}


bool EnemyTank::boundary(){
    switch(toward){
        case UP:
            return row<=2;
        case DOWN:
            return row>=MAXROW-2;
        case LEFT:
            return col<=2;
        case RIGHT:
            return col>=MAXCOL-2;
    }
    return false;
}

void EnemyTank::run(int su, int randx){
    switch(toward){
        case UP:
            game->paintat(row,col-1, 'C');
            game->paintat(row,col, 'M');
            game->paintat(row,col+1, 'D');
            if(su==3)break;
            if(boundary()){
                row++;
                toward=DOWN;
                break;
            }
            if(randx<7){
                row--;
                move_privious=0;
                if(game->coll_obs_check(row,col))row++;
            }
            else if(randx<8){toward=LEFT;move_privious++;}
            else if(randx<9){toward=RIGHT;move_privious++;}
            else {
                row++;
                move_privious=0;
                if(game->coll_obs_check(row,col))row--;
            }
            break;
        case DOWN:
            game->paintat(row,col-1, 'C');
            game->paintat(row,col, 'W');
            game->paintat(row,col+1, 'D');
            if(su==3)break;
            if(boundary()){
                row--;
                toward=UP;
                break;
            }
            if(randx<7){
                row++;
                move_privious=0;
                if(game->coll_obs_check(row,col))row--;
            }
            else if(randx<8){toward=LEFT;move_privious++;}
            else if(randx<9){toward=RIGHT;move_privious++;}
            else {
                row--;
                move_privious=0;
                if(game->coll_obs_check(row,col))row++;
            }
            break;
        case LEFT:
            game->paintat(row-1,col, 'n');
            game->paintat(row,col, 'E');
            game->paintat(row+1,col, 'U');
            if(su==3)break;
            if(boundary()){
                col++;
                toward=RIGHT;
                break;
            }
            if(randx<7){
                col--;
                move_privious=0;
                if(game->coll_obs_check(row,col))col++;
                }
            else if(randx<8){toward=UP;move_privious++;}
            else if(randx<9){toward=DOWN;move_privious++;}
            else {
                col++;
                move_privious=0;
                if(game->coll_obs_check(row,col))col--;
            }
            break;
        case RIGHT:
            game->paintat(row-1,col, 'n');
            game->paintat(row,col, '3');
            game->paintat(row+1,col, 'U');
            if(su==3)break;
            if(boundary()){
                col--;
                toward=LEFT;
                break;
            }
            if(randx<7){
                col++;
                move_privious=0;
                if(game->coll_obs_check(row,col))col--;
            }
            else if(randx<8){toward=UP;move_privious++;}
            else if(randx<9){toward=DOWN;move_privious++;}
            else {
                col--;
                move_privious=0;
                if(game->coll_obs_check(row,col))col++;
            }
            break;
        default:
            break;
    }
}

void EnemyTank::pursue(int catc){
    if(catc==1){
        if(rand()%2==0){
            if(row>game->pl->row){
                row--;
                if(game->coll_obs_check(row,col))row++;
                toward=UP;
                }
            else if(row<game->pl->row){
                row++;
                if(game->coll_obs_check(row,col))row--;
                toward=DOWN;
                }
        }
        else {
            if(col>game->pl->col){
                col--;
                if(game->coll_obs_check(row,col))col++;
                toward=LEFT;
            }
            else if(col<game->pl->col){
                col++;
                if(game->coll_obs_check(row,col))col--;
                toward=RIGHT;
            }
        }
        if(rand()%4==0){
            game->reitems.push_back(new Bullet(game,row,col,toward));
            shoot_privious=0;
        }
    }
}
