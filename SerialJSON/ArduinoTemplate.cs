using System.Collections;
using UnityEngine;
using System.IO.Ports;

public class ArduinoCoroutine : MonoBehaviour
{
    // This class is to create an object with the JSON data we are collecting

    [System.Serializable]           // This line is important
    public class MyClass
    {
        public int data1;
        public string data2;
        public float data3;
    }

    // Variables
    private string input = "{}";  //default value

    // Check your input port and change the parameter accordingly. I was using COM3
    SerialPort stream = new SerialPort("COM3", 9600);
    bool streamRunning = false;

    // Create object instances
    public MyClass mc = new MyClass();

    // Coroutine
    private IEnumerator coroutine;

    void Start()
    {
        // Start coroutine with a 2 second interval time
        coroutine = SerialRead(2f);
        StartCoroutine(coroutine);
    }


    IEnumerator SerialRead(float waitTime)
    {
        stream.Open();
        streamRunning = true;
        //stream.ReadTimeout = 1;    // this line helps if you decide on not using Coroutine

        while (stream.IsOpen)
        {

            try
            {
                if (streamRunning == false)
                {
                    break;
                }

                // Read line from serial port
                input = stream.ReadLine();

                if (input[0] == '{' && input.Contains("}"))
                {
                    mc = JsonUtility.FromJson<MyClass>(input);
                }
            }

            // Error handling
            catch (System.Exception e)
            {
                Debug.LogException(e, this);
            }
            // Wait for some seconds before running coroutine again
            yield return new WaitForSeconds(waitTime);
        }
    }

    // Close serial read
    private void OnApplicationQuit()
    {
        streamRunning = false;
        stream.Close();
        Debug.Log("Stream is CLOSED");
    }
}
