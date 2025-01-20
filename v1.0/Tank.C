#include "Tank.h"

void Tank::update(int){
}

bool Tank::out(){
    if(health <= 0)return true;
    return false;
}

bool Tank::collide(int x, int y){
    if(toward==UP || toward==DOWN){
        for(int i=-1;i<2;i++){
            if(x==row && y==col+i){
                return true;
            }
        }
    }
    else if(toward==LEFT || toward==RIGHT){
        for(int i=-1;i<2;i++){
            if(x==row+i && y==col){
                return true;
            }
        }
    }
    return false;
}
