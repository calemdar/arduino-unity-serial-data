# arduino-unity-serial-data
Transfer JSON data from an Arduino device to Unity

# HeartRateJSON
This is an example code from a Unity project I was working on. Recieving heart rate pulses using Arduino and a pulse sonsor, and getting this sensor information into Unity.
The Arduino outputs the data in JSON format: **{"bpm":value,"amplitude":value}**

# SerialJSON
This directory has a template version of the Arduino (.ino) and Unity (.cs) files that output JSON from Arduino, read the serial input in Unity, and put the collected data inside an object. 

# How to set up Arduino
Download ArduinoJSON library by navigating to **Tools -> Manage Libraries**. Using the search bar, look for ArduinoJSON and get the latest version.
 
![alt text](https://github.com/calemdar/arduino-unity-serial-data/blob/master/images/manage-libs.png "Manage Libraries")

![alt text](https://github.com/calemdar/arduino-unity-serial-data/blob/master/images/lib-arduinoJSON.png "ArduinoJSON")

Upload SerialJSON.ino to your Arduino device, and make sure you are outputting in the correct format by checking the "Serial Monitor". It should be printing:
**{"data1":10,"data2":"hello","data3":3.14159}**


# How to set up Unity
For my project I was using Unity version 2019.1.9f1. Inside your Unity project import ArduinoTemplate.cs and assign the script to an empty game object. Make sure to check that the serial ports match. You can do this by navigating to Tools -> Port inside the Arduino IDE or just check the port at the bottom right of the Arduino IDE. The first parameter in SerialPort() method in ArduinoTemplate.cs should be matching with the port used by the Arduino. Make sure to close the "Serial Monitor" because it will block Unity from looking at the port.

Once you have all those in, try to run the Unity Engine, and check the values inside the game object. You should be able to see a variable called "json". Click on the arrow next to it to see the values it stores. If you are seeing the same values you were printing for data1, data2, and data3, you should be all set up.

![alt text](https://github.com/calemdar/arduino-unity-serial-data/blob/master/images/unity-data.png "Unity")

If you are getting errors read the instructions again and make sure you followed them exactly. If you are not sure why you are getting an error, create an issue through GitHub and I will see if I can be of some help. 

# All set up, now what?
The goal of this Arduino-Unity integration is to collect any type of sensor data using the Arduino, and send it directly into Unity. Now you can change the Arduino code to collect and send the type of data you want. Just make sure ArduinoJSON library handles that data type. 
You should also make sure the name of the JSON objects you are sending should match with the fields inside the "JSONClass" class in the C# script. The types of the fields are important. As long as the variable types in the Arduino matches the field types in the class, Unity's JSON parser should be able to convert the incoming text into the right type, and store them in the correct fields.
Now you can use these values anywhere in Unity, as long as you have access to the "json" object instance.

