/**
   Spencer Rosenvall
   Block Clock Project Library
*/
void stepClockwise(int milliSecs) {
  Serial.println("Master clockwise");
  myStepper.step(stepsPerRevolution * (milliSecs/1000));
  //delay(milliSecs);
}

void stepCounterClockwise(int milliSecs) {
  Serial.println("Master counter-clockwise");
  myStepper.step(-stepsPerRevolution * (milliSecs/1000));
  //delay(milliSecs);
}
