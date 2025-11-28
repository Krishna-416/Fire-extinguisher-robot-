// --- Motor Driver Pins (L298N) - NO CHANGE ---
// Left Motor
const int ENA = 10;   // Enable pin for Left Motors (PWM)
const int IN1 = 9;   // Input 1 Left
const int IN2 = 8;   // Input 2 Left

// Right Motor
const int ENB = 5;   // Enable pin for Right Motors (PWM)
const int IN3 = 7;   // Input 3 Right
const int IN4 = 6;   // Input 4 Right

// --- Flame Sensor= Pins (Digital Inputs) - NO CHANGE ---
const int leftSensorPin = A1;   // The leftmost sensor
const int rightSensorPin = A2;  // The rightmost sensor

// --- Extinguisher Motor Pin (Driven by Transistor) - NO CHANGE ---
const int extinguisherMotorPin = A5; 

// --- Motor Speed Settings - NO CHANGE ---
const int baseSpeed = 150; 
const int turnSpeed = 100; 
const int searchSpeed = 80; 

// --- Flame Detection Threshold - NO CHANGE ---
const int FLAME_DETECTED = LOW; // Assuming sensors output LOW on detection

void setup() {
  // Set Motor Driver Pins as Outputs
  pinMode(ENA, 10);
  pinMode(IN1, 9);
  pinMode(IN2, 8);
  pinMode(ENB, 5);
  pinMode(IN3, 7);
  pinMode(IN4, 6);
  
  // Set Sensor Pins as Inputs
  pinMode(A1, INPUT_PULLUP);
  pinMode(A2, INPUT_PULLUP);

  // Set Extinguisher Motor Pin as Output
  pinMode(A5, OUTPUT);
  digitalWrite(A5,LOW); // Ensure it is OFF initially

  Serial.begin(9600);
  Serial.println("No-Servo Fire Extinguisher Robot Initialized.");
}

void loop() {
  // 1. Read Sensor States
  int leftFlame = analogRead(A1);
  int rightFlame = analogRead(A2);

  // 2. Check for Flame
  if (leftFlame == FLAME_DETECTED && rightFlame == FLAME_DETECTED) {
    // Both detect flame: Assume fire is straight ahead and close
    aimAndExtinguish();
    
  } else if (leftFlame == FLAME_DETECTED) {
    // Flame on the Left: Turn Left
    turnLeft(turnSpeed);
    
  } else if (rightFlame == FLAME_DETECTED) {
    // Flame on the Right: Turn Right
    turnRight(turnSpeed);
    
  } else {
    // No Flame Detected: Search Pattern 
    searchForFlame();
  }
}

// --- Movement Functions (NO CHANGE) ---

void moveForward(int speed) {
  // Set Left and Right Motors Forward
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW); analogWrite(ENA, speed);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW); analogWrite(ENB, speed);
}
void backword(int speed){ //backword
 digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH); analogWrite(ENA, speed);
  digitalWrite(IN3, LOW);digitalWrite(IN4, HIGH);analogWrite(ENB, speed);
 }

void turnLeft(int speed) {
  // Left Motors Backward, Right Motors Forward (Pivot Left)
  digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH); analogWrite(ENA, speed);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW); analogWrite(ENB, speed);
}

void turnRight(int speed) {
  // Left Motors Forward, Right Motors Backward (Pivot Right)
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW); analogWrite(ENA, speed);
  digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH); analogWrite(ENB, speed);
}

void stopRobot() {
  digitalWrite(IN1, LOW); digitalWrite(IN2, LOW); analogWrite(ENA, 0); 
  digitalWrite(IN3, LOW); digitalWrite(IN4, LOW); analogWrite(ENB, 0); 
}

// --- Logic Functions (Simplified) ---

void searchForFlame() {
  // Move slightly forward to continue searching
  moveForward(searchSpeed);
}

void aimAndExtinguish() {
  // Stop and Extinguish - No servo movement needed
  stopRobot();
  
  Serial.println("FIRE DETECTED - EXTINGUISHING!");
  
  // Activate Extinguisher Motor (e.g., fan or pump)
  digitalWrite(A5, HIGH); 
  delay(4000); // *Wait 4 seconds* to extinguish the fire
  
  // Deactivate Extinguisher Motor and pause
  digitalWrite(A5, LOW); 
  delay(1000); // Pause before the robot starts moving again
}