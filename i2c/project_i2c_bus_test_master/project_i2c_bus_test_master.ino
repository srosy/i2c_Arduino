/**
   Spencer Rosenvall
   Arduino Master Code
*/
/**
 * Spencer Roesnvall
 * Arduino Master Code
 * Project
 */
#include<Wire.h>
#include <Stepper.h>

int stepsPerRevolution = 200;

Stepper myStepper(stepsPerRevolution, 6, 4, 5, 3);
unsigned int x;

void setup() {
  myStepper.setSpeed(60);
  // Start the I2C Bus as Master
  Wire.begin();
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    x = Serial.read() - 48;
    switch (x) {
      case (1): sendCommand(x, 2000); break;
      case (2): sendCommand(x, 2000); break;
      case (3): stepCounterClockwise(2000); break;
      case (4): stepClockwise(2000); break;
      default: return; break;
    }
  }
}

void sendCommand(int n, int milliSecs) {
  Wire.beginTransmission(9); // transmit to device #9
  Wire.write(n);              // sends x
  Wire.endTransmission();    // stop transmitting
  Serial.print("Sending: ");
  Serial.print(n);
  Serial.print(" for ");
  Serial.print(milliSecs);
  Serial.println(" milliseconds");
  delay(milliSecs);
  Wire.beginTransmission(9); // transmit to device #9
  Wire.write(0);              // sends stop command
  Wire.endTransmission();    // stop transmitting
}



