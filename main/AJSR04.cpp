#include "AJSR04.h"
#include <Arduino.h>

// Constructor: Initializes the AJSR04 sensor with trigPin and echoPin
AJSR04::AJSR04(int trigPin, int echoPin) : trigPin(trigPin), echoPin(echoPin) {}

// Setup function: Configures the trigPin as OUTPUT and echoPin as INPUT
void AJSR04::setupAJ() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

// Measures distance using the ultrasonic sensor and returns the distance value
void AJSR04::printAJValues() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
}