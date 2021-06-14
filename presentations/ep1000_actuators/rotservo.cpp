

// Arduino's Servo Library
#include <Servo.h>

const int POT = A0;
const int SERVO = 8;
// create a servo object
Servo myServo;

int oldspeed = 0;

void setup()
{
  myServo.attach(SERVO);
  // set to stop
  myServo.write(90);
  Serial.begin(9600);
  Serial.println("Starting");
}

void loop()
{
  // read potentiometer
  int speed = analogRead(A0);
  if (speed != oldspeed)
  {
    // new speed
    int deg = map(speed, 0, 1023, 0,180);
    myServo.write(deg);
    Serial.print("Pot= "); Serial.print(speed);
    Serial.print("\tDeg= ");Serial.println(deg);
    oldspeed = speed;
  } 
}




