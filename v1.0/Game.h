#ifndef _GAME_H__
#define _GAME_H__
#include <list>
#include "Gui.h"
using namespace std;

int const PL_HEALTH=300;
int const NOR_HEALTH=30;
int const SUP_HEALTH=120;
int const LAS_HEALTH=150;
int const BU_POWER=30;
int const MINE_POWER=150;
int const LAS_POWER=20;// 60/3=20
int const LAS_PL_POWER=30;// 90/3=30
int const ENEMYTANK_NUM=20;
int const NORMALTANK_NUM=15;
int const SUPERTANK_NUM=4;
int const LASERTANK_NUM=1;

class Item;
class Player;
class Tank;
class RemoveItem;
class Laser;
class Obstacle;
class Map;

enum towards {UP, DOWN, LEFT, RIGHT};
enum name{unnamed,player,normaltank,supertank,lasertank,bullet,medicalkit,mine,laser,obstacle};

class Game {
    Gui gui;
public:
    Player* pl;
    size_t seed_num=0;
    list <Tank*> tanks={};
    list <Obstacle*> obs={};
    list <Laser*> lasers={};
    size_t med_count=0;
    size_t enemyTank_count=0;
    list <RemoveItem*> reitems={};
    size_t score=0;
    int bullet_count=20;
    int update_count=0;
    int current_tank_num=0;
    int Nor_current_leave_num=NORMALTANK_NUM;
    int Sup_current_leave_num=SUPERTANK_NUM;
    int Las_current_leave_num=LASERTANK_NUM;
    int All_current_leave_num=ENEMYTANK_NUM;
    int Laser_update_count=0;
    bool Laser_exist=false;
    bool laserTank_can_move=true;
    int a=tanks.size();

    Game() ;
    ~Game();
    bool update();
    void paintat(size_t ro, size_t cl, char c) {gui.paintat(ro, cl, c);}
    void medicalkit_pu();
    bool gamedt();
    void Laser_update(int);
    void Laser_add(int, int,towards);
    void add_tank();
    void hit(Tank *t,Item *i);
    void boundry_re(Tank*);
    void win();
    bool get_seed();
    bool coll_obs_check(int, int);
};
#endif
