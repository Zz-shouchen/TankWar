#include <ncurses.h>
#include "Gui.h"
#include <cstring>
using namespace std;

void Gui::init() {
    initscr();                  /* Start curses mode              */
    refresh();                  /* Print it on to the real screen */
    win = stdscr;
    refresh();
    curs_set(0);
    wrefresh(win);
    noecho();
    cbreak();
    keypad(win, true);
    nodelay(win, true);
    flushinp();
}

int Gui::get() {
    int c = wgetch(win);
    flushinp();
    return c;
}

void Gui::paintat(size_t rw, size_t cl, char c) {
    mvwaddch(win, rw, cl, c);
    return;
}

void Gui::printMsg(int row, int col, const char* prompt, int v) {
    mvwprintw(win, row, col, prompt);
    char s[32];
    sprintf(s, "%d", v);
    mvwprintw(win, row, col+strlen(prompt)+1, s);
}

void Gui::prMsg(int row, int col, const char *prompt){
    mvwprintw(win, row, col, prompt);
}


void Gui::clear() {
    werase(win);
    for(int i=0; i<MAXCOL+1; i++){
        mvwaddch(win, 0, i, '-');
        mvwaddch(win, MAXROW+1, i, '-');
    }
    for(int i=1; i<MAXROW+1; i++){
        mvwaddch(win, i, 0, '|');
        mvwaddch(win, i, MAXCOL+1, '|');
    }
    mvwaddch(win, 0, 0, '+');
    mvwaddch(win, 0, MAXCOL+1, '+');
    mvwaddch(win, MAXROW+1, 0, '+');
    mvwaddch(win, MAXROW+1, MAXCOL+1, '+');
}

void Gui::redraw() {
    wrefresh(win);
}
