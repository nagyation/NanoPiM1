#ifndef __RELAY_MODULE__
#define __RELAY_MODULE__

class relayModule{
    public:
    relayModule(unsigned char);
    ~relayModule();
    void moveForward();
    void moveBackward();
    void moveLeft();
    void moveRight();
    void moveSoftLeft();
    void moveSoftRight();
    void stop();
    private:
    unsigned char numOfMotors;
    struct motor{
        unsigned char relay1;
        unsigned char relay2;
    };
    struct motor motors[4];
    void setMotorState(struct motor,int);
};

#endif
