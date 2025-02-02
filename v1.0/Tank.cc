#include "Tank.h"

void Tank::update(int){
    return;//do nothing
}

bool Tank::out(){
    return health<=0;
}

bool Tank::collide(int x, int y){
    if(toward == UP || toward == DOWN){
        for(int i = -1;i < 2;i++){
            if(x == row && y == col + i){
                return true;
            }
        }
    }
    else if(toward == LEFT || toward == RIGHT){
        for(int i = -1;i < 2;i++){
            if(x == row + i && y == col){
                return true;
            }
        }
    }
    return false;
}
