#include "DS18B20.h"

// Define the oneWire instance here
OneWire oneWire(ONE_WIRE_BUS);

// Pass oneWire reference to DallasTemperature library
DallasTemperature sensors(&oneWire);

void setupDS() {
  sensors.begin();
}

void printDSValues() {
  // Send the command to get temperatures
  sensors.requestTemperatures();

  // Print the temperature in Celsius
  Serial.print("DS18B20 Temperature: ");
  Serial.print(sensors.getTempCByIndex(0));
  Serial.println(" °C");
}