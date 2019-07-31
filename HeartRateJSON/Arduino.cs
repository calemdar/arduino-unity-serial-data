using System.Collections;
using UnityEngine;
using System.IO.Ports;
using System.Threading;

public class Arduino : MonoBehaviour
{
    // This class is to create a HeartRate object with the following fields
    [System.Serializable]
    public class HeartRate
    {
        public float bpm;
        public float amplitude;
    }

    // Variables
    private string input = "{'bpm':60,'amplitude':500}";  //default value

    SerialPort stream = new SerialPort("COM3", 9600);
    bool streamRunning = false;

    // Create HeartRate object
    public HeartRate hr = new HeartRate();

    void Start()
    {
        //Threading serial read
        Thread serial = new Thread(new ThreadStart(SerialRead));
        serial.IsBackground = true;
        serial.Start();
    }

    // Read serial input
    void SerialRead()
    {
        stream.Open();
        streamRunning = true;
        //stream.ReadTimeout = 1;

        while (stream.IsOpen)
        {
            //Debug.Log("Stream is OPEN");

            try
            {
                if (streamRunning == false)
                {
                    break;
                }

                // Read line from port
                input = stream.ReadLine();
                hr = JsonUtility.FromJson<HeartRate>(input);
                //Debug.Log(input);

            }

            catch (System.Exception e)
            {
                Debug.LogException(e, this);
                break;
            }
        }

        Debug.Log("Stream is CLOSED");
        
    }

    // Close serial read
    private void OnApplicationQuit()
    {
        streamRunning = false;
        stream.Close();
    }
}
