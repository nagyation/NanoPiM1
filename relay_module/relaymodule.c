#include "relaymodule.h"
#include "libfahw-gpio.h"

#define STATE_BACKWARD 0
#define STATE_FORWARD 1
#define STATE_STOP 3

void setMotorState(struct motor,int);

unsigned char numOfMotors;

struct motor{
    unsigned char relay1;
    unsigned char relay2;
};

struct motor motors[4];

int intializeMotors(unsigned char numofmotors,int pins[]){
    numOfMotors = numofmotors;
    int i,j;
    if (( boardInit()) < 0) {
        return -1;
    }
    for( i=0,j=0; i < numOfMotors ; i ++,j+=2)
    {
      motors[i].relay1 = GPIO_PIN(pins[j]);
      motors[i].relay2 = GPIO_PIN(pins[j+1]);
      exportGPIOPin(motors[i].relay1);
      exportGPIOPin(motors[i].relay2);
      setGPIODirection(motors[i].relay1,GPIO_OUT);
      setGPIODirection(motors[i].relay2,GPIO_OUT);

    }
    stop();
    return 0;
}


void setMotorState(struct motor m,int state){
    if ( state < 2){ 
       //state forward or backward
        setGPIOValue(m.relay1,state);
        setGPIOValue(m.relay2,!state);
    }
    else
    {
         //case stop state = 2
         //stop the motor
         setGPIOValue(m.relay1,state-1);
         setGPIOValue(m.relay2,state-1);

    }
}

void moveForward(){
    int i; 
    for(i =0; i < numOfMotors; i++)
       setMotorState(motors[i],STATE_FORWARD);

}


void moveBackward(){
    int i;
    for(i =0; i < numOfMotors; i++)
       setMotorState(motors[i],STATE_BACKWARD);

}

void moveLeft(){
    int i=0; 
    for(i =0; i < numOfMotors; i++)
    {  if(i % 2)
           setMotorState(motors[i],STATE_FORWARD);
       else
           setMotorState(motors[i],STATE_BACKWARD);
    }
}

void moveRight(){
    int i; 
    for(i =0; i < numOfMotors; i++)
     {  if(i % 2)
            setMotorState(motors[i],STATE_BACKWARD);
        else
            setMotorState(motors[i],STATE_FORWARD);
     }
}

void moveSoftLeft(){
    int i ;
    for(i =0; i < numOfMotors; i++)
    {  if(i % 2)
           setMotorState(motors[i],STATE_FORWARD);
       else
           setMotorState(motors[i],STATE_STOP);
    }
}

void moveSoftRight(){
   int i;  
    for(i =0; i < numOfMotors; i++)
     {  if(i % 2)
            setMotorState(motors[i],STATE_STOP);
        else
            setMotorState(motors[i],STATE_FORWARD);
     }
}

void stop(){
    int i;
    for(i =0; i < numOfMotors; i++)
       setMotorState(motors[i],STATE_STOP);

}
