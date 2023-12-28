void motorOn() {
  digitalWrite(motorPin, HIGH);
}

void motorOff() {
  digitalWrite(motorPin, LOW);
}

void testMotors() {
  int motordt = 5000;
  Serial.println("Testing motors, LIFT THE CAR:");
  for (int i = 0; i < 5; i++) {
    motorOn();
    delay(motordt);
    motorOff();
    delay(motordt);
  }
  Serial.println("Test complete");
}

void motorRoutine() {
   Serial.println("Turning on motors in 15 seconds.");
      Serial.println("Please unplug computer or lift car.");
      for (int i = 15; i > 1; i--) {
        Serial.println();
        Serial.println(i);
      }
      motorOn();
}
