// MQ4 Gas Sensor Integrated

#ifndef MQ4_H
#define MQ4_H

#include <Arduino.h>

struct MQ4Sensor {
  const int AOUTpin;    // The AOUT pin of the methane sensor goes into analog pin A0 of the Arduino
  const int DOUTpin;    // The DOUT pin of the methane sensor goes into digital pin D8 of the Arduino
  const int buzzerPin;  // The anode (positive node) of the LED connects to digital pin D3 of the Arduino

  int CH4Value;            // Current value of the Methane Gas
  const int CH4threshold;  // The threshold of the Methane Gas

  MQ4Sensor(int aoutPin, int doutPin, int buzzerPin, int threshold)
    : AOUTpin(aoutPin), DOUTpin(doutPin), buzzerPin(buzzerPin), CH4threshold(threshold) {}
};

void setupMQ4(MQ4Sensor& sensor);
void thresholdCheck(MQ4Sensor& sensor);
void printMethaneValues(MQ4Sensor& sensor);

#endif