#ifndef DS18B20_H
#define DS18B20_H

#include <OneWire.h>
#include <DallasTemperature.h>

// Data Wire is plugged into the digital pin 2 of Arduino
#define ONE_WIRE_BUS 2

// Setup a oneWire instance to communicate with any OneWire device
extern OneWire oneWire;

// Pass oneWire reference to DallasTemperature library
extern DallasTemperature sensors;

void setupDS();
void printDSValues();

#endif