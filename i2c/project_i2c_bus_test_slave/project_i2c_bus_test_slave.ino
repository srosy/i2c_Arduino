/**
   Spencer Rosenvall
   Arduino Slave Code
   Project
*/

#include<Wire.h>
#include <Stepper.h>

int stepsPerRevolution = 200;

Stepper myStepper(stepsPerRevolution, 6, 4, 5, 3);
int x;

void setup() {
  myStepper.setSpeed(60);
  // Start the I2C Bus as Slave on address 9
  Wire.begin(9);
  // Attach a function to trigger when something is received.
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
}

void loop() {
  getCommand();
}
