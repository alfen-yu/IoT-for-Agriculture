#ifndef DHT22_H
#define DHT22_H

#include <Arduino.h>
#include <dht.h>  // dht library

struct DHTSensor {
  const int DHTOUT;  // The digital output pin of the DHT22 sensor goes into the D13 of the Arduino
  float temperature;
  float humidity;

  DHTSensor(int dhtout, float temp, float humid)
    : DHTOUT(dhtout), temperature(temp), humidity(humid) {}
};

void setupDHT(DHTSensor& sensor);
void printDHTValues(DHTSensor& sensor);

#endif