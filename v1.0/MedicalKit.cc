#include "MedicalKit.h"
#include "Game.h"

void MedicalKit::update(int){//paint the medical kit on the map
    game->paintat(row, col, '+');
}

bool MedicalKit::out(){
    return false;
}
