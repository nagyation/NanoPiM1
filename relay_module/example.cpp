#include <unistd.h>
#include "relaymodule.h"

int main(){
    int pins[4]={7,8,10,11}; 
    numberOfMotors(2,pins);
    while(1){
    moveRight();
    sleep(2);
    moveForward();
    sleep(2);
    moveLeft();
    sleep(2);
    moveBackward();
    sleep(2);
    moveSoftLeft();
    sleep(2);
    moveSoftRight();
    sleep(2);
    }
    return 0;
}
