#include "BME280.h"

#define BME280_I2C_ADDRESS 0x76    // BME280 I2C address
#define SEALEVELPRESSURE_HPA 1000  // Standard Sea Level Pressure in hPa

void setupBME(BME280Sensor& sensor) {
  Wire.begin();  // Initialize I2C bus

  // A5 pin used for SCL
  // A4 pin used for SDA
  // Condition to check if BME sensor is found
  if (!sensor.bme.begin(BME280_I2C_ADDRESS, &Wire)) {
    Serial.println("Couldn't find a valid BME280 sensor. Check wiring or code.");
    // You can add additional error handling here, like blinking an LED or sending an error message.
  }
}

// function for printing the data retrieved from BME
void printBMEValues(BME280Sensor& sensor) {
  // Temperature
  Serial.print("BME280 Temperature = ");
  Serial.print(sensor.bme.readTemperature());
  Serial.println(" °C");

  // Pressure
  Serial.print("BME280 Pressure = ");
  Serial.print(sensor.bme.readPressure() / 100.0F);
  Serial.println(" hPa");

  // Humidity
  Serial.print("BME Humidity = ");
  Serial.print(sensor.bme.readHumidity());
  Serial.println("%");

  // Absolute Altitude
  Serial.print("Absolute Altitude = ");
  Serial.print(sensor.bme.readAltitude(SEALEVELPRESSURE_HPA));
  Serial.print(" m");
  Serial.println();
}