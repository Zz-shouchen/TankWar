#include "Map.h"
#include "Obstacle.h"
#include "Game.h"

void Map::update(){
    if(nseed==0)update_map0();
    else if(nseed==1)update_map1();
    else {
        while(game->obs.size()<150){update_map_rand();}
    }
}

void Map::update_map0(){
    for(int j=1;j<MAXCOL/5;j++){
        game->obs.push_back(new Obstacle(game,MAXROW/3,j));
        game->obs.push_back(new Obstacle(game,MAXROW/3*2,j));
        game->obs.push_back(new Obstacle(game,MAXROW/3,MAXCOL-j+1));
        game->obs.push_back(new Obstacle(game,MAXROW/3*2,MAXCOL-j+1));
    }
    for(int j=1;j<MAXROW/5;j++){
        game->obs.push_back(new Obstacle(game,j,MAXCOL/3));
        game->obs.push_back(new Obstacle(game,j,MAXCOL/3*2));
        game->obs.push_back(new Obstacle(game,MAXROW-j+1,MAXCOL/3));
        game->obs.push_back(new Obstacle(game,MAXROW-j+1,MAXCOL/3*2));
    }
    for(int j=0;j<MAXCOL/3;j++){
        game->obs.push_back(new Obstacle(game,MAXROW/3,j+MAXCOL/3));
        game->obs.push_back(new Obstacle(game,MAXROW/3*2,j+MAXCOL/3));
    }
}

void Map::update_map1(){
    for(int j=0;j<MAXROW/5*3;j++){
        game->obs.push_back(new Obstacle(game,j+1,MAXCOL/5));
        game->obs.push_back(new Obstacle(game,j+1,MAXCOL/5*3));
        game->obs.push_back(new Obstacle(game,MAXROW-j,MAXCOL/5*2));
        game->obs.push_back(new Obstacle(game,MAXROW-j,MAXCOL/5*4));
    }
}

void Map::update_map_rand(){
    int d=nseed%(MAXROW-2)+1;
    int x=nseed%(MAXCOL-4)+2;
    game->obs.push_back(new Obstacle(game,d,x-1));
    game->obs.push_back(new Obstacle(game,d,x+1));
    game->obs.push_back(new Obstacle(game,d,x));
    size_t nseed_push=nseed<<3-1;
    nseed=nseed_push xor nseed_privous;
    nseed_privous=nseed;
}
