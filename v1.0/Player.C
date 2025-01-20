#include "Player.h"
#include "Game.h"
#include "Bullet.h"
#include "Item.h"
#include "Laser.h"

void Player::update(int key){
    // initscr();
    int shoot=0;
    switch (key){
    case KEY_UP:
        if(row>1)row--;
        if(game->coll_obs_check(row,col))row++;
        toward=UP;
        break;
    case KEY_DOWN:
        if(row<MAXROW)row++;
        if(game->coll_obs_check(row,col))row--;
        toward=DOWN;
        break;
    case KEY_LEFT:
        if(col>1)col--;
        if(game->coll_obs_check(row,col))col++;
        toward=LEFT;
        break;
    case KEY_RIGHT:
        if(col<MAXCOL)col++;
        if(game->coll_obs_check(row,col))col--;
        toward=RIGHT;
        break;
    case ' ':
        shoot=1;
        break;
//
    case 'u':
        game->bullet_count+=1000;
        break;
    case 'i':
        game->score+=1000;
        break;
    case 'p':
        health-=10;
        break;
    case 'o':
        health+=1000000;
        break;
    case 'j':
        if(game->Laser_exist==false)game->Laser_add(row,col,toward);
        break;
//
    default:
        break;
    }
    if (shoot && game->bullet_count>0){
        game->bullet_count--;
        game->reitems.push_back(new Bullet(game,row,col,toward));
    }
    init_pair(1,COLOR_BLUE,COLOR_BLACK);
    attron(COLOR_PAIR(1));
    switch (toward){
        case UP:
            game->paintat(row,col,'M');
            break;
        case DOWN:
            game->paintat(row,col,'W');
            break;
        case LEFT:
            game->paintat(row,col,'E');
            break;
        case RIGHT:
            game->paintat(row,col,'3');
            break;
        default:
            break;
    }
    attroff(COLOR_PAIR(1));//turn off color

}

bool Player::arround(int x, int y){
    for(int i=-8;i<9;i++){
        for(int j=-8;j<9;j++){
            if(row+i==x && col+j==y)return true;
        }
    }
    return false;
}
