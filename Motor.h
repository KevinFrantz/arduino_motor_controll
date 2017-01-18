#ifndef Motor_h
#define Motor_h

#include "Arduino.h"
/**
 * Eine Klasse zur Motorsteurung unter Arduino
 * @author kf
 * @since 2016-01-17
 **/
class Motor{
    private:
      int pwmPin;
      int directionPin;
      int forwardValue;
      int speedPwm;
      int directionDelay;
      
      //Liefert die PWM-Geschwindigkeit in Abhängigkeit von der Richtung zurück
      int getSpeed(int direction);
      
      //Liefert den Vorwärtswert;HIGH oder LOW zurück
      int getBackwardsValue();
    public:
        //Initialisierung der Klassenattribute
        Motor(int pwmPin, int directionPin,bool forwardBool,int speedPwm,int directionDelay);
        //Dreht das Rad vorwärts
        void forward();
        //Dreht das Rad rückwärts
        void backward();
        //Stoppt den Motor
        void stop();
};

#endif

