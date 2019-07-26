int IRsensor = 3;
int sensorPinRight = 10; // Right sensor pin
int sensorPinLeft = 9; // Left sensor pin

int lightReadingRight;
int lightToleranceRight = 1000; // Sensor reading needed to trigger right turn

int lightReadingCenter;
int lightToleranceCenter = 1000; // Sensor reading needed to trigger forward movement

int lightReadingLeft;
int lightToleranceLeft = 1000; // Sensor reading needed to trigger left turn

int readingDelay = 100; // Delay between readings

void setup()
{
pinMode(10,INPUT);
pinMode(9,INPUT);  
pinMode(3,INPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
pinMode(8,OUTPUT);

// Uncomment the serial feed for calibration purposes
Serial.begin(9600);
}

void loop()
{
// Uncomment the serial print lines for calibration purposes

// Take reading from right sensor
lightReadingRight = analogRead(sensorPinRight);
Serial.print("Right Sensor Reading :");
Serial.println(lightReadingRight);

IRsensor = digitalRead(3);
Serial.print("IRsensor:");
Serial.println(IRsensor);

// Take reading from left sensor
lightReadingLeft = analogRead(sensorPinLeft);
Serial.print("Left Sensor Reading :");
Serial.println(lightReadingLeft);


// Turn left if enough light is detected from left sensor
if (lightReadingLeft > lightToleranceLeft)
{
digitalWrite(5, HIGH); 
digitalWrite(6, LOW); 
digitalWrite(7, LOW); 
digitalWrite(8, LOW);
delay(1000);
digitalWrite(5, LOW); 
digitalWrite(6, LOW); 
digitalWrite(7, LOW); 
digitalWrite(8, LOW);

}

// Turn right if enough light is detected from right sensor
if (lightReadingRight > lightToleranceRight)
{
digitalWrite(5, LOW); 
digitalWrite(6, LOW); 
digitalWrite(7, HIGH); 
digitalWrite(8, LOW);
delay(1000);
digitalWrite(5, LOW); 
digitalWrite(6, LOW); 
digitalWrite(7, LOW); 
digitalWrite(8, LOW);

}
if (lightReadingRight ==1&&lightReadingLeft ==1)
{
digitalWrite(5, HIGH); 
digitalWrite(6, LOW); 
digitalWrite(7, HIGH); 
digitalWrite(8, LOW);


// Backward

if(digitalRead(3)==1)

digitalWrite(5, LOW); 
digitalWrite(6, HIGH); 
digitalWrite(7, LOW); 
digitalWrite(8, HIGH);
//stop
digitalWrite(5, LOW); 
digitalWrite(6, LOW); 
digitalWrite(7, LOW); 
digitalWrite(8, LOW);
// delay(5000);// Uncomment this long delay for motor calibration purposes
}
}

