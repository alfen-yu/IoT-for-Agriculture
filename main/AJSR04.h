#ifndef AJSR04_H
#define AJSR04_H

// A class to manage the AJSR04 Ultrasonic Sensor
class AJSR04 {
public:
  // Constructor: Initializes the sensor with the specified trigPin and echoPin
  AJSR04(int trigPin, int echoPin);
  
  // Sets up the ultrasonic sensor
  void setupAJ();
  
  // Measures distance using the ultrasonic sensor and returns the distance value
  void printAJValues();
  
private:
  int trigPin;     // The digital pin connected to the trigger pin of the sensor
  int echoPin;     // The digital pin connected to the echo pin of the sensor
  long duration;   // The time taken for the ultrasonic pulse to travel and return
  int distance;    // The calculated distance based on the time duration
};

#endif
