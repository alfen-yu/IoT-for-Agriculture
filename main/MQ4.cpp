#include "MQ4.h"

void setupMQ4(MQ4Sensor& sensor) {
  pinMode(sensor.DOUTpin, INPUT);     // sets the DOUT pin as an input to the Arduino
  pinMode(sensor.buzzerPin, OUTPUT);  // sets the buzzer pin as an output of the arduino
}

void printMethaneValues(MQ4Sensor& sensor) {
  Serial.print("Methane Value: ");
  Serial.print(sensor.CH4Value);  // Prints the methane value
  Serial.println(" PPM");
}

void thresholdCheck(MQ4Sensor& sensor) {
  sensor.CH4Value = analogRead(sensor.AOUTpin);  // Reads the analog value from the methane sensor's AOUT pin

  if (sensor.CH4Value > sensor.CH4threshold) {
    digitalWrite(sensor.buzzerPin, HIGH);
    delay(500);
    digitalWrite(sensor.buzzerPin, LOW);
    delay(500);
    Serial.print("CH4 Limit: ");
    Serial.print(HIGH);  // Prints the limit reached as HIGH (above threshold)
  } else {
    digitalWrite(sensor.buzzerPin, LOW);  // If the threshold is not reached, the buzzer remains off
    Serial.print("CH4 Limit: ");
    Serial.print(LOW);  // Prints the limit reached as LOW (below threshold)
  }
}