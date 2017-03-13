#ifndef __RELAY_MODULE__
#define __RELAY_MODULE__

#include "libfahw-gpio.h"

#define STATE_BACKWARD 0
#define STATE_FORWARD 1
#define STATE_STOP 3
#ifdef __cplusplus
extern "C" {
#endif
void numberOfMotors(unsigned char,int []);
    void moveForward();
    void moveBackward();
    void moveLeft();
    void moveRight();
    void moveSoftLeft();
    void moveSoftRight();
    void stop();
    unsigned char numOfMotors;
    struct motor{
        unsigned char relay1;
        unsigned char relay2;
    };
    struct motor motors[4];
    void setMotorState(struct motor,int);

    #ifdef __cplusplus
}
#endif
#endif
