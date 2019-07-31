#include <ArduinoJson.h>               // includes ArduinoJson library

// Allocate the JSON document
//
// Inside the brackets, 200 is the RAM allocated to this document.
// Don't forget to change this value to match your requirement.
// Use arduinojson.org/v6/assistant to compute the capacity.
StaticJsonDocument<200> doc;

// Global data variables 
// change these variables to fit your data
int data1 = 10;
const char* data2 = "hello";
float data3 = 3.1415926;

void setup() {
  
  Serial.begin(9600);          // Set up Serial Monitor
}

void loop() {
  // Add object and value in the JSON document
  // doc["object"] = value;
  
  doc["data1"] = data1;
  doc["data2"] = data2;
  doc["data3"] = data3;

  
  serializeJson(doc, Serial);
  // The above line prints the JSON objects with their values
  // {"data1":10,"data2":"hello","data3":3.1415926}

  Serial.println();
  delay(50);                // wait for 50 milliseconds for better performance

}
