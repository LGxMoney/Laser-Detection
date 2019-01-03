/*
Laser Security

This program enables a photoresistor to sense whether
or not a laser is making contact with it. This allows
a simple laser tripwire to be enabled. 

The alarm I use is directly plugged into the arduino nano
and consists of a flashing LED and a fast repetitive siren
noise on a piezo buzzer. Make sure to have a bright light
nearby when testing. 

Hardware components:
  - Microcontroller (Arduino Nano || Arduino Uno || other)
  - photoresistor
  - 10K ohm resistor
  - LED
  - piezzo buzzer

Wiring: 
  - LED from GND to pin 6
  - Buzzer from GND to pin 4
  - photoresistor from 3.3V to pin A6
  - 10K Ohm resistor from A6 to GND
 */
 
#define LED 6
#define BUZZER 4

void setup() 
{
  // to debug
  Serial.begin(9600);

  //setting the outputs of the sensor
  pinMode(LED,OUTPUT);
  pinMode(BUZZER, OUTPUT);
}

void loop() 
{
  // read the sensor:
  int sensorReading = analogRead(A6);
  
  // print the sensor reading so you know its range
  Serial.println(sensorReading);
 
  // play the pitch:
  // Threshold for alarm may vary depending upon room
  if (sensorReading <= 600)
  {
    alarm(sensorReading);  
  }
  else
  {
    digitalWrite(LED,LOW);
    noTone(BUZZER);
  }
}

// Function used to control what the alarm sounds like 
// and what the led does.
void alarm(int sensorReading)
{
  int pitch = 100;
    while(pitch <= 2000)
    {
      tone(BUZZER,pitch);
      pitch = pitch + 30;
      delay(7);
      if(pitch >= 750)
      {
        digitalWrite(LED,HIGH);
      }
      else
      {
        digitalWrite(LED,LOW);
      }
    }
}






