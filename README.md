# Fire-extinguisher-robot-
Fire Extinguisher Car Project: Autonomous Firefighting Vehicle
​(An educational project demonstrating basic robotics, sensor integration, and fire suppression)
​📝 Description
​This project details the creation of a Fire Extinguisher Car, a small-scale, autonomous robotic vehicle designed to detect and extinguish small fires using an onboard sensor system and a modified fire extinguisher mechanism. It serves as an excellent platform for learning about microcontroller programming (Arduino/Raspberry Pi), sensor data interpretation, and motor control.
​The goal is for the car to navigate a small arena, identify the location of a flame (representing a fire), approach it, and activate the fire suppression system.
​✨ Key Features
​The robot incorporates several key functionalities:
​Autonomous Navigation: Utilizes Infrared (IR) sensors for basic obstacle avoidance.
​Flame Detection: Employs a Flame Sensor to pinpoint the heat and light signature of a fire source.
​Targeting System: Uses a servo motor to adjust the angle of the extinguisher nozzle for accurate targeting.
​Motorized Suppression: A small DC pump (or fan/CO2 canister mechanism) is used to deploy the suppression agent (e.g., water, air, or mist) once the target is acquired.
​Status Indicator: Simple LEDs or an LCD screen to display the current mode (Searching, Targeting, Suppressing).
​⚙ Process & Architecture
​This section breaks down the system's operational flow and the components used.
​Built With
​Microcontroller: Arduino Uno or Raspberry Pi
​Motor Driver: L298N (for controlling DC motors)
​Sensors: Flame Sensor (IR-based), IR Proximity Sensors (for obstacle avoidance)
​Actuators: DC Gear Motors (for movement), Servo Motor (for nozzle positioning), DC Pump/Fan (for suppression)
​Chassis: Custom 3D-printed or pre-fabricated robot car chassis
​Programming Language: C++ (Arduino IDE) or Python (Raspberry Pi)
​Operational Flow (The Process)
​The car follows a simple, iterative detection-and-action loop:
​Search Mode: The car moves forward, continuously sweeping the flame sensor from side to side using the servo motor.
​Detection & Stop: If the flame sensor detects a fire, the car immediately stops movement.
​Targeting: The microcontroller rotates the servo motor slowly to find the exact direction where the flame sensor reading is at its maximum (the direct line of fire).
​Approach: The car drives forward slowly until the flame sensor reading indicates it is at the optimal suppression distance (or until the obstacle avoidance sensors trigger a close range).
​Suppression: The DC pump/suppression mechanism is activated for a set duration (e.g., 5 seconds).
​Verify & Resume: After suppression, the car briefly checks if the flame is gone. If gone, it returns to Search Mode.
​🚧 Challenges and Learnings
​Building an autonomous system always presents unique technical hurdles.
​Major Challenges
​Challenge 1: Sensor False Positives (Ambient Light) - Flame sensors can sometimes be triggered by bright ambient light (e.g., sunlight or halogen lamps), leading to false detection and unnecessary stops.
​Solution/Learning: Implemented a digital filter in the code that requires the sensor to register a maximum value for a sustained period (e.g., 500ms) before confirming a fire, drastically reducing false positives.
​Challenge 2: Steering Accuracy - Getting the car to precisely align its nozzle with the flame using only simple DC motors and a turning algorithm was difficult, often leading to missed shots.
​Solution/Learning: Introduced a proportional-like control loop where the car makes smaller, finer adjustments based on the flame sensor reading (e.g., if the flame is slightly left, turn left for a very short duration) to improve alignment before suppression.
