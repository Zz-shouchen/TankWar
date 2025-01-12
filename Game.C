#include "Game.h"
#include "Player.h"
#include "Tank.h"
#include "EnemyTank.h"
#include "NormalTank.h"
#include "SuperTank.h"
#include "LaserTank.h"
#include "Bullet.h"
#include "RemoveItem.h"
#include "MedicalKit.h"
#include "Mine.h"
#include "Laser.h"
#include "Map.h"
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <string.h>


Game::Game() {
    gui.init();
    gui.clear();
    pl = new Player(this,29,5);
    tanks.push_back(pl);
    score = 0;
}

Game::~Game() {
    gui.end();
    if(reitems.empty() == false){
        list<RemoveItem*>::iterator ii = reitems.begin();
        while (ii != reitems.end() ) {
            delete *ii;
            ii++;
        }
    }
    reitems.clear();
    if(tanks.empty() == false){
        list<Tank*>::iterator ti = tanks.begin();
        while (ti != tanks.end() ) {
            delete *ti;
            ti++;
        }
    }
    tanks.clear();
    if(obs.empty() == false){
        list<Obstacle*>::iterator oi = obs.begin();
        while (oi != obs.end() ) {
            delete *oi;
            oi++;
        }
    }
    obs.clear();
    if(lasers.empty() == false){
        list<Laser*>::iterator li = lasers.begin();
        while (li != lasers.end() ) {
            delete *li;
            li++;
        }
    }
    lasers.clear();
}

bool Game::update() {
    update_count++;
    if(Laser_exist){
        Laser_update_count++;
    }
    if (update_count > 40 && bullet_count < 20) {
        update_count = 0;
        bullet_count++;
    }
    gui.clear(); //clear everything on the screen
    gui.printMsg(1, MAXCOL+2, "Player\'s health: ", pl->health/3);
    gui.printMsg(2, MAXCOL+2, "Bullet", bullet_count);
    gui.printMsg(3, MAXCOL+2, "score: ", score);
    gui.printMsg(4,MAXCOL+2,"current_tank_num: ", current_tank_num);
    gui.printMsg(5,MAXCOL+2,"All_current_leave_num: ", All_current_leave_num);
    int c = gui.get();
    medicalkit_pu();
    list<Tank*>::iterator ti = tanks.begin();
    while (ti != tanks.end() ) {
        (*ti)->update(c);
        boundry_re(*ti);
        if((*ti)->out()&&(*ti)->namei!=player){
            if((*ti)->namei==normaltank)score+=100;
            else if((*ti)->namei==supertank)score+=400;
            else if((*ti)->namei==lasertank)score+=700;
            current_tank_num--;
            delete *ti;
            ti = tanks.erase(ti);
        }
        ti++;
    }
    if(!obs.empty()){
        list<Obstacle*>::iterator oi = obs.begin();
        while (oi != obs.end() ) {
            (*oi)->update(c);
            oi++;
        }
    }
    list<RemoveItem*>::iterator ii = reitems.begin();
    while (ii != reitems.end() ) {
        (*ii)->update(c);
        if ((*ii)->out() == true) {
            delete *ii;
            ii = reitems.erase(ii);
        }
        else if(((*ii)->namei)==medicalkit){
            for(int i=-1;i<2;i++){
                for(int j=-1;j<2;j++){
                    if((*ii)->row+i==pl->row && (*ii)->col+j==pl->col){
                        delete *ii;
                        med_count--;
                        ii = reitems.erase(ii);
                        if(pl->health<300)pl->health=300;
                    }
                }
            }
        }
        ii++;
    }
    if(Laser_exist && Laser_update_count <3)Laser_update(c);
    else if(Laser_exist){
        lasers.clear();
        Laser_exist=false;
        Laser_update_count=0;
    }
    else laserTank_can_move=true;



    if(current_tank_num<4 && All_current_leave_num>0)add_tank();
    gui.redraw(); //draw things


    if(All_current_leave_num==0 && current_tank_num==0){
        win();
        return false;
    }

    if (gamedt()) {
        return false;//game->restart
    }

    return true;
}

void Game::medicalkit_pu(){
    if(rand()%(20+4*med_count) == 1){
        int r = rand()%(MAXROW-2)+1;
        int c = rand()%(MAXCOL-2)+1;
        if(coll_obs_check(r,c))return;
        reitems.push_back(new MedicalKit(this, r, c));
        med_count++;
    }
}

bool Game::gamedt(){
    if (pl->health <= 0) {
        gui.clear();
        gui.prMsg(MAXROW/2, MAXCOL/2-8, "Game Over");
        gui.printMsg(MAXROW/2+1, MAXCOL/2-12, "Your score is: ", score);
        gui.prMsg(MAXROW/2+2, MAXCOL/2-9, "Press q to quit");
        int time_ed = 0;
        while (time_ed < 3){
            time_ed++;
            int c = gui.get();
            if (c == 'q'){
                gui.clear();
                gui.end();
                exit(0);
                }
            usleep(1000000);
        }
        score=0;
        return true;
    }
    return false;
}

void Game::Laser_update(int c){
    list<Laser*>::iterator li = lasers.begin();
    init_pair(3,COLOR_CYAN,COLOR_YELLOW);
    attron(COLOR_PAIR(3));
    while (li != lasers.end() ) {
        (*li)->update(c);
        li++;
    }
    attroff(COLOR_PAIR(3));
}

void Game::Laser_add(int row, int col,towards tow){
    laserTank_can_move=false;
    Laser_exist=true;
    if(tow==UP){
        for(int i=row-1;i>0;i--){
            if(coll_obs_check(i,col))break;
            lasers.push_back(new Laser(this,i,col,tow));
        }
    }
    else if(tow==DOWN){
        for(int i=row+1;i<MAXROW+1;i++){
            if(coll_obs_check(i,col))break;
            lasers.push_back(new Laser(this,i,col,tow));
        }
    }
    else if(tow==LEFT){
        for(int i=col-1;i>0;i--){
            if(coll_obs_check(row,i))break;
            lasers.push_back(new Laser(this,row,i,tow));
        }
    }
    else if(tow==RIGHT){
        for(int i=col+1;i<MAXCOL+1;i++){
            if(coll_obs_check(row,i))break;
            lasers.push_back(new Laser(this,row,i,tow));
        }
    }
}

void Game::add_tank(){
    int ss=rand()%6;
    if(ss==0)return;
    int r = rand()%(MAXROW-6)+3;
    int c = rand()%(MAXCOL-6)+3;
    if(pl->arround(r,c))return;
    if(coll_obs_check(r,c))return;
    int type = rand()%All_current_leave_num;
    int to=rand()%4;
    towards tow;
    switch(to){
        case 0:tow=UP;break;
        case 1:tow=DOWN;break;
        case 2:tow=LEFT;break;
        case 3:tow=RIGHT;break;
    }
    if(type<Nor_current_leave_num){
        tanks.push_back(new NormalTank(this,r,c,tow));
        Nor_current_leave_num--;
        All_current_leave_num--;
        current_tank_num++;
    }
    else if(type<Nor_current_leave_num+Sup_current_leave_num){
        tanks.push_back(new SuperTank(this,r,c,tow));
        Sup_current_leave_num--;
        All_current_leave_num--;
        current_tank_num++;
    }
    else if(type<Nor_current_leave_num+Sup_current_leave_num+Las_current_leave_num){
        tanks.push_back(new LaserTank(this,r,c,tow));
        Las_current_leave_num--;
        All_current_leave_num--;
        current_tank_num++;
    }
}

void Game::hit(Tank *t, Item *i){
    if(i->namei==laser){
        if(t->namei==player){
            t->health-=LAS_PL_POWER;
        }
        else if(t->namei!=lasertank){
            t->health-=LAS_POWER;
        }
    }
    else if(i->namei==bullet){
        t->health-=BU_POWER;
    }
    else if(i->namei==mine && t->namei==player)pl->health-=MINE_POWER;
}

void Game::boundry_re(Tank* t){
    if(t->row<1)t->row=1;
    if(t->row>MAXROW)t->row=MAXROW;
    if(t->col<1)t->col=1;
    if(t->col>MAXCOL)t->col=MAXCOL;
}

void Game::win(){
    gui.clear();
    gui.prMsg(MAXROW/2, MAXCOL/2-8, "You Win");
    gui.printMsg(MAXROW/2+1, MAXCOL/2-12, "Your score is: ", score);
    gui.prMsg(MAXROW/2+2, MAXCOL/2-30, "Press q to quit or wait for new game(The score will be saved)");
    gui.redraw();
    int time_ed = 0;
    while (time_ed < 3){
        time_ed++;
        int c = gui.get();
        if (c == 'q'){
            gui.clear();
            gui.end();
            exit(0);
            }
        usleep(1000000);
    }
}

bool Game::get_seed(){
    char* seed = new char[11];
    memset(seed, '\0', 11 * sizeof(char));
    int c;
    int i=0;
    while(i<10){
        gui.clear();
        gui.prMsg(MAXROW/2-5, MAXCOL/2-16, "Game");
        gui.prMsg(MAXROW/2-4, MAXCOL/2-23, "Enter seed:(1-999999999),for map generation,default is 0");
        gui.prMsg(MAXROW/2-3, MAXCOL/2-23, "Press Enter to end input");
        gui.prMsg(MAXROW/2-2, MAXCOL/2-26, "seed \'0\' and seed \'1\' are precasted seeds,others are random seeds");
        gui.prMsg(MAXROW/2-1, MAXCOL/2-28, "seed:");
        gui.prMsg(MAXROW/2-1, MAXCOL/2-23, seed);
        c=getch();
        if(c<='9' && c>='0' && i<10){
            seed[i]=c;
            seed_num=seed_num*10+(c-'0');
            i++;
        }
        else if(c=='\n')break;
    }
    gui.clear();
    gui.prMsg(MAXROW/2-5, MAXCOL/2-11, "Your seed:");
    if(i==0)gui.prMsg(MAXROW/2-4, MAXCOL/2-18, "0");
    else gui.prMsg(MAXROW/2-4, MAXCOL/2-18, seed);
    gui.prMsg(MAXROW/2-3, MAXCOL/2-18, "Press Enter to start");
    c='a';
    while(c!='\n'){
        c=getch();
    }
    Map* map=new Map(this,MAXROW,MAXCOL,seed_num);
    map->update();
    delete map;
    delete[] seed;
    return false;
}

bool Game::coll_obs_check(int r, int c){
    list<Obstacle*>::iterator oi = obs.begin();
    while (oi != obs.end() ) {
        if((*oi)->row==r && (*oi)->col==c)return true;
        oi++;
    }
    return false;
}

