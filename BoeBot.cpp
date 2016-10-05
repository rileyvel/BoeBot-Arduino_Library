/*
   BoeBot.cpp - Boe-Bot Library for Arduino
   @author - Riley Yi.
   Released under GNU GPLv3.
 */

#include "Arduino.h"
#include "BoeBot.h"
#include "Servo.h"

/**
 *  Constructor without scaleFactor;
 *  scaleFactor is set to 1.0;
 *  Program uses default empirical formula.
 */
BoeBot::BoeBot(int leftPin, int rightPin) {
        _leftPin = leftPin;
        _rightPin = rightPin;
        _disableEF = false;
        _scaleFactor = 1.0;
}

/**
 *  Constructor with scaleFactor;
 *  Empirical formula is scaled.
 */
BoeBot::BoeBot(int leftPin, int rightPin, double scaleFactor) {
        _leftPin = leftPin;
        _rightPin = rightPin;
        _disableEF = false;
        _scaleFactor = scaleFactor;
}

/**
 *  Constructor disabling empirical formula for this instance
 */
BoeBot::BoeBot(int leftPin, int rightPin, boolean disableEF) {
        _leftPin = leftPin;
        _rightPin = rightPin;
        _disableEF = true;
}

/**
 *  Moves the Boe-Bot forwards/backwards for a given distance.
 *  @param distance - distance to move, in centimetres
 *  @param forward - true for moving forward, false for moving backward
 */
void BoeBot::walk(int distance, boolean forward) {
        // Attach Both Wheels
        _servoLeft.attach(_leftPin);
        _servoRight.attach(_rightPin);

        // Activate Wheels
        if (forward) {
                _servoLeft.writeMicroseconds(1000);
                _servoRight.writeMicroseconds(2000);
        } else {
                _servoLeft.writeMicroseconds(2000);
                _servoRight.writeMicroseconds(1000);
        }

        // Calculate Delay Time and Do Delay
        if (_disableEF) {
                delay(distance);
        } else {
                int ms = (int) (distance / 0.012 * _scaleFactor);
                delay(ms);
        }

        // Deactivate Wheels
        _servoLeft.detach();
        _servoRight.detach();
}

/**
 *  Turns the Boe-Bot left/right.
 *  @param degree - degrees to turn
 *  @param left - true for turning left, false for turning right
 */
void BoeBot::turn(int degree, boolean left) {
        // Attach Both Wheels
        _servoLeft.attach(_leftPin);
        _servoRight.attach(_rightPin);

        // Activate Wheels
        if (left) {
                _servoLeft.writeMicroseconds(1000);
                _servoRight.writeMicroseconds(1000);
        } else {
                _servoLeft.writeMicroseconds(2000);
                _servoRight.writeMicroseconds(2000);
        }

        // Calculate Delay Time and Do Delay
        if (_disableEF) {
                delay(degree);
        } else {
                int ms = (int) (degree * 10.0 * _scaleFactor);
                delay(ms);
        }

        // Deactivate Wheels
        _servoLeft.detach();
        _servoRight.detach();
}

/**
 *  Get scale on the fly
 *  Does not work if Empirical Formula is disabled
 *  @return - scaleFactor
 */
double BoeBot::getScale() {
        if (_disableEF)
                return 0.0;
        else
                return _scaleFactor;
}

/**
 *  Sets scale on the fly.
 *  Has no effect if empirical formula is disabled.
 *  @param - s - new scale factor
 */
void BoeBot::setScale(double s) {
        _scaleFactor = s;
}
