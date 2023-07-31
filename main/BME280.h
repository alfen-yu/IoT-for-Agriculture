// BME280 Integration

#ifndef BME280SENSOR_H
#define BME280SENSOR_H

#include <Adafruit_BME280.h>  // Library for BME280 Sensor

struct BME280Sensor {
  Adafruit_BME280 bme;  // BME280 object

  BME280Sensor()
    : bme() {}  // Constructor to initialize BME280 object
};

void setupBME(BME280Sensor& sensor);
void printBMEValues(BME280Sensor& sensor);

#endif
