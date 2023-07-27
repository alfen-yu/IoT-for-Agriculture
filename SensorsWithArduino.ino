/* MQ-4 Methane Sensor on Arduino */
/* DHT22 Temperature and Humidity Sensor on Arduino */

#include <dht.h>
#include <Wire.h>

const int AOUTpin = 0;    //the AOUT pin of the methane sensor goes into analog pin A0 of the arduino
const int DOUTpin = 8;    //the DOUT pin of the methane sensor goes into digital pin D8 of the arduino
const int buzzerPin = 3;  //the anode (positive node) of the LED connects to digital pin D3 of the arduino
const int DHTDOUT = 13;   // the Digital Output pin of the DHT22 sensor goes into the D13 of the arduino


dht DHT;  // creates a DHT object

int limit;               // Digital output or the limit of 1 or 0
int CH4Value;            // Current value of the Methane Gas
int CH4threshold = 500;  // the threshold of the Methane Gas

int DHTReadData;  // reads the data from the pin for DHT22
float temp;
float humid;

void setup() {
  Serial.begin(115200);        // sets the baud rate, needs to match with the serial monitor baud rate
  pinMode(DOUTpin, INPUT);     // sets the pin as an input to the arduino
  pinMode(buzzerPin, OUTPUT);  // sets the pin as an output of the arduino
}

void loop() {
  CH4Value = analogRead(AOUTpin);  //reads the analaog value from the methane sensor's AOUT pin
  DHTReadData = DHT.read22(DHTDOUT);

  temp = DHT.temperature;  // Gets the values of temperature
  humid = DHT.humidity;    // Gets the values of humidity

  Serial.print("Temperature = ");
  Serial.print(temp);
  Serial.print("°C");
  Serial.println(" ");
  Serial.print("Humidity = ");
  Serial.print(humid);
  Serial.println("%");
  Serial.println("");

  if (CH4Value > CH4threshold) {
    limit = 1;  //reads the digital value from the methane sensor's DOUT pin
  } else {
    limit = 0;
  }

  Serial.print("Methane Value PPM: ");
  Serial.println(CH4Value);  // prints the methane value

  delay(100);  // delay of 0.1s

  if (limit == HIGH) {
    digitalWrite(buzzerPin, HIGH);
    delay(500);
    digitalWrite(buzzerPin, LOW);
    delay(500);
    Serial.print("Limit: ");
    Serial.print(limit);  //prints the limit reached as either LOW or HIGH (above or underneath)
    Serial.print(" ");
  } else {
    digitalWrite(buzzerPin, LOW);  //if threshold not reached, LED remains off
  }
}