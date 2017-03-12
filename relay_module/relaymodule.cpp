#include "relaymodule.h"
#include "libfahw-gpio.h"

#define STATE_BACKWARD 0
#define STATE_FORWARD 1
#define STATE_STOP 3
relayModule::relayModule(unsigned char numOfMotors){
    this->numOfMotors = numOfMotors;
    for(int i=7; i < 7 +(numOfMotors * 2); i +=2)
    {
      this->motors[i-7].relay1 = GPIO_PIN(i);
      this->motors[i-7].relay2 = GPIO_PIN(i+1);
      setGPIODirection(this->motors[i-7].relay1,GPIO_OUT);
      setGPIODirection(this->motors[i-7].relay2,GPIO_OUT);

    }
    this->stop();
}
relayModule::~relayModule(){

}

void relayModule::setMotorState(struct motor m,int state){
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

void relayModule::moveForward(){
    for(int i =0; i < this->numOfMotors; i++)
       this->setMotorState(this->motors[i],STATE_FORWARD);

}


void relayModule::moveBackward(){
    for(int i =0; i < this->numOfMotors; i++)
       this->setMotorState(this->motors[i],STATE_BACKWARD);

}

void relayModule::moveLeft(){
    for(int i =0; i < this->numOfMotors; i++)
    {  if(i % 2)
           this->setMotorState(this->motors[i],STATE_FORWARD);
       else
           this->setMotorState(this->motors[i],STATE_BACKWARD);
    }
}

void relayModule::moveRight(){
     for(int i =0; i < this->numOfMotors; i++)
     {  if(i % 2)
            this->setMotorState(this->motors[i],STATE_BACKWARD);
        else
            this->setMotorState(this->motors[i],STATE_FORWARD);
     }
}

void relayModule::moveSoftLeft(){
    for(int i =0; i < this->numOfMotors; i++)
    {  if(i % 2)
           this->setMotorState(this->motors[i],STATE_FORWARD);
       else
           this->setMotorState(this->motors[i],STATE_STOP);
    }
}

void relayModule::moveSoftRight(){
     for(int i =0; i < this->numOfMotors; i++)
     {  if(i % 2)
            this->setMotorState(this->motors[i],STATE_STOP);
        else
            this->setMotorState(this->motors[i],STATE_FORWARD);
     }
}

void relayModule::stop(){

    for(int i =0; i < this->numOfMotors; i++)
       this->setMotorState(this->motors[i],STATE_STOP);

}
