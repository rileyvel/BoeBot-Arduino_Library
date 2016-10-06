# BoeBot-Arduino-Library
A very simple Arduino Library for Boe-Bot Shield

# Features
1. Move robot forwards/backwards for a given distance
1. Turn robot left/right for a given angle

# Installation
Create a new folder named `BoeBot` in the `libraries` folder in your Arduino
sketchbook (usually in your Documents folder), and copy `BoeBot.h` and `BoeBot.cpp`
inside.

# Usage
*Exemplar 1*  
``` Arduino
#include <BoeBot.h>

BoeBot myCuteRobot(12, 13);
// Left wheel is connected to Pin 12, right wheel to Pin 13
// Using Empirical Formula (See notes below)

void setup() {
  // No need to do anything for BoeBot to work
}

/**
 *  Robot will move in a 20-cm square.
 */
void loop() {
  // BoeBot.walk(int distance_in_cm, boolean forward);
  myCuteRobot.walk(20, true); // Moving 20 cm forwards

  delay(500);

  // BoeBot.turn(int degree, boolean left);
  myCuteRobot.turn(90, true); // Turning left for 90 degrees

  delay(1000);
}
```

*Exemplar 2*
``` Arduino
#include <BoeBot.h>

BoeBot stupidRobot(9, 6, 1.25);
// Left wheel is connected to Pin 9, right wheel to Pin 6
// Empirical Formula is scaled to 1.25 to fit hardware configurations of this robot
// (See notes below)

void setup() {
  // No need to do anything for BoeBot to work
}

/**
 *  Robot will move in a 33-cm square but backwards.
 */
void loop() {
  // BoeBot.walk(int distance_in_cm, boolean forward);
  stupidRobot.walk(33, false); // Moving 33 cm backwards

  delay(500);

  // BoeBot.turn(int degree, boolean left);
  stupidRobot.turn(90, false); // Turning right for 90 degrees

  delay(1000);
}
```

*Exemplar 3*
``` Arduino
#include <BoeBot.h>

BoeBot myOwnBot(4, 8, true);
// Left wheel is connected to Pin 4, right wheel to Pin 8
// Empirical Formula is disabled because there is a boolean parameter in the end
// It doesn't matter if the boolean variable is true or false
// (See notes below)

void setup() {
  // No need to do anything for BoeBot to work
}

/**
 *  Robot will move in who knows what shape.
 */
void loop() {
  // BoeBot.walk(int ms_to_delay, boolean forward);
  myOwnBot.walk(2000, false); // Moving backwards for 2000 milliseconds

  delay(500);

  // BoeBot.turn(int ms_to_delay, boolean left);
  myOwnBot.turn(500, false); // Turning right for 500 milliseconds

  delay(1000);
}
```

*To be Updated with New Features Added*

## The Empirical Formula
This library converts the given centimetres / degrees to time lengths (in milliseconds)
of motor activation with two linear, empirical formulas.

These formulas are derived from my Boe-bot under USB power.
Different Boe-Bots under different power sources often behave differently. If
your Boe-bot behaves differently than parametres given to this library, please correct it by adding
a scale factor while initialising this library (as in exemplar 2).

If you do not wish to use the empirical formula, please put add a boolean parameter
(value doesn't matter) while initialising this library (as in exemplar 3).


# License
GNU GPLv3
