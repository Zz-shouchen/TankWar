#ifndef _UNMOVEITEM_H_
#define _UNMOVEITEM_H_
#include "RemoveItem.h"
#include "Game.h"

class UnmoveItem : public RemoveItem {
public:
    UnmoveItem(Game* game, int x, int y, name n): RemoveItem(game, x, y, n){}
    virtual void update(int);
    virtual bool out();
};
#endif
