/*
   moteur.ino : le moteur pas a pas

   http://poubelle.online

*/

#include <Arduino.h>
#include "BasicStepperDriver.h"

// 2-wire basic config, microstepping is hardwired on the driver
BasicStepperDriver stepper(MOTOR_STEPS, DIR, STEP);

void init_moteur() {
  stepper.begin(RPM, MICROSTEPS);
}

void tourner_moteur() {

  // energize coils - the motor will hold position
  // stepper.enable();

  // Moving motor one full revolution using the degree notation
  stepper.rotate(360);

  // Moving motor to original position using steps
  stepper.move(-MOTOR_STEPS*MICROSTEPS);

  // pause and allow the motor to be moved by hand
  // stepper.disable();

  delay(5000);
}

/* vim: set ts=2 sw=2 et : */
