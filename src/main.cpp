#include <Arduino.h>
#include <Wire.h>

// Define the pins for the lamps
const int lamp1Pin = A12; // Replace with the actual pin number for lamp 1
const int lamp2Pin = A13; // Replace with the actual pin number for lamp 2

// Define the soil moisture sensor pin
const int soilMoisturePin = A1; // Replace with the actual pin number for the soil moisture sensor

// Define moisture thresholds
const int dryThreshold = 0;  // Adjust this value based on your sensor readings
const int wetThreshold = 300;  // Adjust this value based on your sensor readings

void setup() {
  // Initialize lamps as OUTPUT
  pinMode(lamp1Pin, OUTPUT);
  pinMode(lamp2Pin, OUTPUT);

  // Initialize serial communication
  Serial.begin(115200);
}

void loop() {
  // Read soil moisture level
  int moistureLevel = analogRead(soilMoisturePin);

  // Print moisture level to Serial Monitor
  Serial.print("Moisture Level: ");
  Serial.println(moistureLevel);

  // Control Lamp 1 based on moisture level
  if (moistureLevel > dryThreshold) {
    digitalWrite(lamp1Pin, HIGH); // Turn on lamp 1
  } else {
    digitalWrite(lamp1Pin, LOW);  // Turn off lamp 1
  }

  // Control Lamp 2 based on moisture level
  if (moistureLevel > wetThreshold) {
    digitalWrite(lamp2Pin, HIGH); // Turn on lamp 2
  } else {
    digitalWrite(lamp2Pin, LOW);  // Turn off lamp 2
  }

  delay(1000);  // Adjust the delay based on your needs
}
