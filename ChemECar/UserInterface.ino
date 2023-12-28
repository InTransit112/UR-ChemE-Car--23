void displayMenu() {
  Serial.println("Menu:");
  Serial.println("1. Systems Test");
  Serial.println("2. Run Motors");
  Serial.println("3. CV Rxn Data Collection");
  Serial.println("4. Sensor and Absorbance Test (quick)");
  Serial.print("Enter your choice: ");
}

void runProgram(int choice) {
  // Perform action based on user choice
  switch (choice) {
    case -1:  // case: you didnt enter a integer, just recycles main loop
      break;
    case 1:
      systemsTest();
      break;
    case 2:
      motorRoutine();    
      break;
    case 3:
      CvRxnExp();
      break;
    case 4:
      //testSensor();
      testAbsorbance();
      break;
    default:
      Serial.println("Invalid choice. Please enter a number");
  }
}

int getUserChoice() {
  while (!Serial.available()) {
    // Wait for user input
  }

  String userInput = Serial.readStringUntil('\n');  // Read the user's input as a string
  userInput.trim();                                 // Remove leading and trailing whitespaces

  // Check if the input is a valid integer
  for (size_t i = 0; i < userInput.length(); i++) {
    if (!isDigit(userInput.charAt(i))) {
      Serial.println("Invalid input. Please enter a valid number.");
      return -1;  // Return an error code
    }
  }

  int choice = userInput.toInt();  // Convert the string to an integer
  Serial.println(choice);          // Echo the choice back to Serial Monitor
  Serial.flush();                  // Clear the input buffer
  return choice;
}


void runOption1() {
  Serial.println("Running Option 1");
  motorOn();
}

void runOption2() {
  Serial.println("Running Option 2");
  // Add your code for Option 2 here
}

void runOption3() {
  Serial.println("Running Option 3");
  // Add your code for Option 3 here
}
