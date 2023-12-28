const int expRunTime = 120; // seconds                                                   // preparation for multidimensional(?)
int sampleArray[expRunTime];
float absorbanceArray[expRunTime];
int calibration;

//const int analogPin = A0;
#define sensorPin A0
const int motorPin = 13;

void setup() {
  // Initialize serial communication at a baud rate of 9600
  Serial.begin(9600);
  pinMode(motorPin, OUTPUT);
  calibrateSensor();
}

void loop() {
  displayMenu();                 // Display the menu options
  int choice = getUserChoice();  // Get user input
  runProgram(choice);            // just a switch statement for diff funcs
  delay(1000);
}

void systemsTest() {
  testMotors();
  testSensor();
  testAbsorbance();
}