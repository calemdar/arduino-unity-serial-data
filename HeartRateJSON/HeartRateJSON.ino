#define USE_ARDUINO_INTERRUPTS true    // Set-up low-level interrupts for most acurate BPM math.
#include <PulseSensorPlayground.h>     // Includes the PulseSensorPlayground Library.
#include <ArduinoJson.h>               // includes ArduinoJson library

//  Variables
const int PulseWire = 0;       // PulseSensor PURPLE WIRE connected to ANALOG PIN 0
const int LED13 = 13;          // The on-board Arduino LED, close to PIN 13.
int Threshold = 700;           // Determine which Signal to "count as a beat" and which to ignore.
                               // Use the "Gettting Started Project" to fine-tune Threshold Value beyond default setting.
                               // Otherwise leave the default "550" value. 

PulseSensorPlayground pulseSensor;  // Creates an instance of the PulseSensorPlayground object called "pulseSensor"

// Allocate the JSON document
//
// Inside the brackets, 200 is the RAM allocated to this document.
// Don't forget to change this value to match your requirement.
// Use arduinojson.org/v6/assistant to compute the capacity.
StaticJsonDocument<200> doc;

void setup() {
  
  Serial.begin(9600);          // For Serial Monitor

  // Configure the PulseSensor object, by assigning our variables to it. 
  pulseSensor.analogInput(PulseWire);   
  pulseSensor.blinkOnPulse(LED13);       //auto-magically blink Arduino's LED with heartbeat.
  pulseSensor.setThreshold(Threshold);

  if (pulseSensor.begin()) {
    //Serial.println("Started looking for pulse");  //This prints one time at Arduino power-up,  or on Arduino reset.   
  }
}

void loop() {

  int myBPM = pulseSensor.getBeatsPerMinute();      // Calls function on our pulseSensor object that returns BPM as an "int".
                                                    // "myBPM" hold this BPM value now. 
  int pulseAmplitude = pulseSensor.getPulseAmplitude();   // Get pulse amplitude and store it
                                                
  if (pulseSensor.sawStartOfBeat()) {           // Checks if a new beat is detected
    
    // Add object and value in the JSON document
    doc["bpm"] = myBPM;
    doc["amplitude"] = pulseAmplitude;

    serializeJson(doc, Serial);
    // The above line prints the JSON objects with their values
    // {"bpm":60,"amplitude":600}

    Serial.println();
  }
  delay(20);                    // wait for 20 milliseconds for better performance
}
