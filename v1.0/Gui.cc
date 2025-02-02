#include <ncurses.h>
#include "Gui.h"
#include <cstring>
using namespace std;

void Gui::init(){
    initscr();//start curses mode
    refresh();//print it on to the real screen
    win = stdscr;
    refresh();//refresh the screen
    curs_set(0);//hide the cursor
    wrefresh(win);//refresh the screen
    noecho();//don't echo keystrokes to the screen
    cbreak();//don't wait for enter key to be pressed
    keypad(win, true);//enable special keys
    nodelay(win, true);//don't wait for input
    flushinp();//flush the input buffer
}

int Gui::get(){
    int c = wgetch(win);
    flushinp();
    return c;
}

void Gui::paintat(size_t rw, size_t cl, char c) {
    mvwaddch(win, rw, cl, c);//add a character to the window
    return;
}

void Gui::printMsg(int row, int col, const char* prompt, int v) {
    mvwprintw(win, row, col, prompt);//print the prompt
    char s[32];
    sprintf(s, "%d", v);
    mvwprintw(win, row, col + strlen(prompt) + 1, s);//print the value
}

void Gui::prMsg(int row, int col, const char *prompt){
    mvwprintw(win, row, col, prompt);//print the prompt
}

void Gui::clear(){//clear the window and draw the border
    werase(win);
    for(int i = 0; i < MAXCOL+1; i++){
        mvwaddch(win, 0, i, '-');
        mvwaddch(win, MAXROW + 1, i, '-');
    }
    for(int i = 1; i < MAXROW + 1; i++){
        mvwaddch(win, i, 0, '|');
        mvwaddch(win, i, MAXCOL + 1, '|');
    }
    mvwaddch(win, 0, 0, '+');
    mvwaddch(win, 0, MAXCOL + 1, '+');
    mvwaddch(win, MAXROW + 1, 0, '+');
    mvwaddch(win, MAXROW + 1, MAXCOL + 1, '+');
}

void Gui::redraw(){
    wrefresh(win);
}
