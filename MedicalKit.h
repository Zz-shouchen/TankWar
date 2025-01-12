#ifndef _MEDICALKIT_H_
#define _MEDICALKIT_H_
#include "UnmoveItem.h"
#include "Game.h"
class MedicalKit : public UnmoveItem {
public:
    bool is_taken=false;
    MedicalKit(Game* game, int x, int y):UnmoveItem(game, x, y, medicalkit){}
    void update(int);
    bool out();
};
#endif