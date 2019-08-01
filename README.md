# arduino-unity-serial-data
Transfer JSON data from an Arduino device to Unity

# HeartRateJSON
This is an example code from a Unity project I was working on. Recieving heart rate pulses using Arduino and a pulse sonsor, and getting this sensor information into Unity.
The Arduino outputs the data in JSON format: {"bpm":value,"amplitude":value}

# SerialJSON
This directory has template versions of the Arduino (.ino) and Unity (.cs) files to output JSON from Arduino, read the serial input in Unity, and put it inside a Unity object. 

# How to set it up
Download arduinoJSON library by navigating to Tools -> Manage Libraries.
 
![alt text](https://github.com/calemdar/arduino-unity-serial-data/blob/master/images/manage-libs.png "Manage Libraries")

![alt text](https://github.com/calemdar/arduino-unity-serial-data/blob/master/images/lib-arduinoJSON.png "arduinoJSON")

Upload SerialJSON.ino to your Arduino device. Change the code to fit the data you want to send. And make sure you are outputting in the correct format by checking the "Serial Monitor". 




