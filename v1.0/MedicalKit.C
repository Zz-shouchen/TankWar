#include "MedicalKit.h"
#include "Game.h"

void MedicalKit::update(int){
    game->paintat(row, col, '+');
}

bool MedicalKit::out(){
    return false;
}
