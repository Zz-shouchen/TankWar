#ifndef _REMOVEITEM_H_
#define _REMOVEITEM_H_
#include "Item.h"
#include "Game.h"

class RemoveItem : public Item {
public:
    Game* game;
    RemoveItem(Game* game, int x, int y,name n): Item(game,x, y, n), game(game) {}
    virtual void update(int);
    virtual bool out();
};
#endif