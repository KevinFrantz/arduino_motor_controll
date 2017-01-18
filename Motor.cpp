#include "Arduino.h"
#include "Motor.h"

int Motor::getBackwardsValue(){
  if(this->forwardValue==0){
    return 1;
  }
  return 0;
}

int Motor::getSpeed(int direction){
  if(direction==LOW){
    return 255-this->speedPwm;
  }
  return this->speedPwm;
}

Motor::Motor(int pwmPin, int directionPin,bool forwardValue, int speedPwm, int directionDelay){
  this->pwmPin        = pwmPin;
  this->directionPin  = directionPin;
  this->forwardValue  = forwardValue;
  this->speedPwm      = speedPwm;
  this->directionDelay= directionDelay;
  
  //Pins auf Output setzen
  pinMode(pwmPin, OUTPUT );
  pinMode(directionPin, OUTPUT );
  digitalWrite(pwmPin, LOW );
  digitalWrite(directionPin, LOW );
}

void Motor::forward(){
  //Motor vor Änderungen stoppen
  this->stop();
  digitalWrite(this->directionPin,this->forwardValue);
  analogWrite(this->pwmPin, this->getSpeed(this->forwardValue));
} 

void Motor::backward(){
  //Motor vor Änderungen stoppen
  this->stop();
  digitalWrite(this->directionPin,this->getBackwardsValue());
  analogWrite(this->pwmPin, this->getSpeed(this->getBackwardsValue()));
} 

void Motor::stop(){
  digitalWrite(this->directionPin, LOW);
  digitalWrite(this->pwmPin, LOW);
  //Abwarten bis Rad gestoppt wurde
  delay(this->directionDelay);
}
