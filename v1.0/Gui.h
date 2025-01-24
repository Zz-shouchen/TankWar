// www.trainsimchina.com/Session7/Gui.h
#ifndef _GUI_H_
#define _GUI_H_
#include <ncurses.h>

int const MAXCOL=80;
int const MAXROW=30;

class Gui {
    size_t row;
    size_t col;
    WINDOW* win;
public:
    Gui ():row(20),col(50) {init();}
    ~Gui() {endwin();}
    void init();
    int get();
    void paintat(size_t, size_t, char);
    void printMsg(int row, int col, const char* prompt, int v);
    void prMsg(int row, int col, const char* prompt);
    void clear();
    void redraw();
    void end() {endwin();}
};
#endif
