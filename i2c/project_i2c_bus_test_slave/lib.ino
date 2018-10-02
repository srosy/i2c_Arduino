/**
   Spencer Rosenvall
   Block Clock Project Library
*/
void stepClockwise(int milliSecs) {
  Serial.println("Slave clockwise . . .");
  myStepper.step(stepsPerRevolution * (milliSecs/1000));
}

void stepCounterClockwise(int milliSecs) {
  Serial.println("Slave counter-clockwise . . .");
  myStepper.step(-stepsPerRevolution * (milliSecs/1000));
}

void receiveEvent(int bytes) {
  x = Wire.read();    // read one character from the I2C
}

void getCommand() {
  switch (x) {
    case (1): stepCounterClockwise(2000); break;
    case (2): stepClockwise(2000); break;
    default: return; break;
  }
  delay(500);
}



