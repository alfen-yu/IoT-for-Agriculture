/* MQ-4 Methane Sensor on Arduino */
/* DHT22 Temperature and Humidity Sensor on Arduino */
/* BME280 for Temperature, Humidity, Pressure, Relative and Absolute Altitude*/
/* DS18B20 for Water Temperature */
/* AJ-SR04M for Ultrasonic Distance to detect Tidal Height */

#include <Arduino.h>
#include "MQ4.h"
#include "DHT22.h"
#include "BME280.h"
#include "DS18B20.h"
#include "AJSR04.h"

// Values for MQ4 Sensor
const int methaneAOUTpin = A0;
const int methaneDOUTpin = 8;
const int methaneBuzzerPin = 3;
const int methaneThreshold = 500;

// Values for DHT22
const int DHTOut = 13;

// Values for AJ-SR04M 
const int TRIG_PIN = 4;
const int ECHO_PIN = 7;

// Structs Instances
MQ4Sensor methaneSensor(methaneAOUTpin, methaneDOUTpin, methaneBuzzerPin, methaneThreshold);  // Creates an instance of the MQ4Sensor struct with the given values
DHTSensor dhtSensor(DHTOut, 0.0, 0.0);
BME280Sensor bmeSensor;  // Creates an instance of the DHT22Sensor struct with the passed values
AJSR04 tidalSensor(TRIG_PIN, ECHO_PIN); // Create an instance of the AJSR04 class

void setup() {
  Serial.begin(115200);  // sets the baud rate, needs to match with the serial monitor baud rate

  // Initialize each sensor
  setupMQ4(methaneSensor);
  setupDHT(dhtSensor);
  setupBME(bmeSensor);
  setupDS();
  tidalSensor.setupAJ(); 
  delay(500);
}

void loop() {
  printMethaneValues(methaneSensor);  // Pass the instance of the struct to the printMethaneValues function
  printDHTValues(dhtSensor);
  printBMEValues(bmeSensor);
  printDSValues();
  tidalSensor.printAJValues(); 
  
  thresholdCheck(methaneSensor); // Check the threshold after printing the values
  Serial.println("\n");
  delay(1000);
}
