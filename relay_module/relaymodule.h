#ifndef __RELAY_MODULE__
#define __RELAY_MODULE__

#ifdef __cplusplus
extern "C" {
#endif
    int intializeMotors(unsigned char,int []);
    void moveForward();
    void moveBackward();
    void moveLeft();
    void moveRight();
    void moveSoftLeft();
    void moveSoftRight();
    void stop();

    #ifdef __cplusplus
}
#endif
#endif
