#include "DHT22.h"

dht DHT;  // Creates a DHT object

void setupDHT(DHTSensor& sensor) {
  DHT.read22(sensor.DHTOUT);  // Read data from the DHT22 sensor connected to the specified pin and stores it in the DHT object
}

void printDHTValues(DHTSensor& sensor) {
  int chk = DHT.read22(sensor.DHTOUT);  // Read data from the DHT22 sensor again before accessing values

  if (chk == DHTLIB_OK) {  // checks for the success or error from the returned integer value by read22 function

    sensor.temperature = DHT.temperature;  // Gets the values of temperature
    sensor.humidity = DHT.humidity;        // Gets the values of humidity

    Serial.print("DHT22 Temperature = ");
    Serial.print(sensor.temperature);
    Serial.println(" °C");
    Serial.print("DHT22 Humidity = ");
    Serial.print(sensor.humidity);
    Serial.println(" %");
    // Serial.print("\n");
  } else {
    Serial.println("DHT22 Read Error");
  }
}
