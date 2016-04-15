#include "Arduino.h"
#include <Servo.h>


Servo myServo;
//int const potPin = A0;
int tempSensor = 0;
int potVal = 0;
int angle = 0;
int tempMap = 0;
unsigned int currTemp = 0;


//The setup function is called once at startup of the sketch
void setup()
{
	myServo.attach(9);
	myServo.write(0);
	Serial.begin(9600);
}

// The loop function is called in an endless loop
void loop()
{
//Add your repeated code here
	//potVal = analogRead(potPin);
	tempSensor = analogRead(A0);
	Serial.print("\ntempSensor is ");
	Serial.print(tempSensor);

	float voltage = (tempSensor/1024.0 ) *5;
	Serial.print("\t Voltage is ");
	Serial.print(voltage);

	float ActualTemp = (voltage - 0.5)*100;
	Serial.print("\t ActualTemp is ");
	Serial.print(ActualTemp);

	//angle = map(potVal,0,1023,0,179);
	angle = map(ActualTemp,15,30,0,179);
	Serial.print("\nangle: ");
	Serial.print(angle);


	if (abs(currTemp - ActualTemp) > 10)
	{
		Serial.print("temp error");
	}
	else
	{
		myServo.write(angle);
	}

	currTemp = ActualTemp;
	delay(5000);
}
