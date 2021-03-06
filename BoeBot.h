/*
   BoeBot.h - Arduino Library for the Boe-Bot Shield
   @author - Riley Yi.
   Released under GNU GPLv3.
 */
#ifndef BoeBot_h
#define BoeBot_h

#include "Arduino.h"
#include "Servo.h"

class BoeBot {
public:
        BoeBot(int leftPin, int rightPin);
        BoeBot(int leftPin, int rightPin, boolean disableEF);
        BoeBot(int leftPin, int rightPin, double scaleFactor);
        BoeBot(int leftPin, int rightPin, double scaleFactor, double powerFactor);
        void walk(int distance, boolean forward);
        void turn(int degree, boolean left);
        double getScale();
        void setScale(double s);
        double getPower();
        void setPower(double p);
private:
        int _leftPin;
        int _rightPin;
        double _scaleFactor;
        Servo _servoLeft;
        Servo _servoRight;
        boolean _disableEF;
        double _powerFactor;
};

#endif
