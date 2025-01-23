#include <ncurses.h>
#include "Gui.h"
#include <sys/time.h>
#include <ctime>
#include <unistd.h>
#include <iostream>
#include <cstddef>
#include "Game.h"
using namespace std;

size_t play_game(size_t score_pr);

int main(){
    srand(time(0));
    initscr();//initialize curses
    if(has_colors() == FALSE){
        exit(1);//exit if color support is not available
    }
    size_t score_pr=0;
    start_color();
    while(true){
        score_pr=play_game(score_pr);
    }
    return 0;
}

size_t play_game(size_t score_pr) {
    struct timeval time_now {};
    gettimeofday(&time_now, NULL);
    time_t oldTime = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
    time_t currentTime =  oldTime;
    Game game;
    game.score=score_pr;
    bool se=true;
    while(se){
        gettimeofday(&time_now, NULL);
        currentTime = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
        if (currentTime - oldTime < 50) {usleep(25);continue;}
        se=game.get_seed();
        oldTime = currentTime;
    }
    bool re=true;
    while (re) {
        gettimeofday(&time_now, NULL);
        currentTime = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
        if (currentTime - oldTime < 50) {usleep(25);continue;}
        re = game.update();
        oldTime = currentTime;
    }
    return game.score;
}
