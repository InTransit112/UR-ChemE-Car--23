int readSensor() {
  int sensorValue = analogRead(sensorPin);
  return sensorValue;
}

float beersLaw() {
  float absorb = log10((analogRead(sensorPin) / calibration));
  return absorb;
}

void calibrateSensor() {
  int calibration = 0;
  int sampleSize = 5;
  for (int i = 0; i < sampleSize; i++) {
    calibration += analogRead(sensorPin);
  }
  calibration = calibration / 5;
}

void testSensor() {
  Serial.println("Testing photoresistor:");
  for (int i = 0; i < 5; i++) {
    Serial.print("Reading ");
    Serial.print(i + 1);
    Serial.print("/5: ");
    Serial.println(readSensor());
    delay(1000);
  }
  Serial.println("Photoresistor Test complete");
}

void testAbsorbance() {
  Serial.println("Test absorbance function:");
  for (int i = 0; i < 5; i++) {
    Serial.print(String(i + 1));
    Serial.print("/5: ");
    Serial.println(String(beersLaw(),2));
    delay(1000);
  }
  Serial.println("Absorbance Test complete");
}

void CvRxnExp() {
  Serial.println("Testing CV Rxn: Press any key and enter to exit the test.");
  int i = 0;
  double expStart = millis();
  while (!Serial.available() && millis() - expStart < expRunTime) {  // checks for serial comms and runtime
    absorbanceArray[i] = beersLaw();
    delay(1000);
  }

Serial.println();
for (int i = 0; i < expRunTime; ++i) {
  Serial.print(absorbanceArray[i], 2);  // Print with 2 decimal places
  if (i < expRunTime - 1) {
    Serial.print("\t");  // Use tab as a delimiter (you can change it to "," for CSV)
  }
}

Serial.println();  // Move to the next line after printing all values
}