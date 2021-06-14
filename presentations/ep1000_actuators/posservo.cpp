

// Arduino's Servo Library
#include <Servo.h>

const int SERVO = 8;
const int MAXDEG = 120;
// create a servo object
Servo myServo;

void setup()
{
  myServo.attach(SERVO);
  Serial.begin(9600);
  Serial.println("Starting");
}

void loop()
{
  // swing servo full arc
  for(int i=0; i<MAXDEG; i=i+10)
  {
    myServo.write(i);
    Serial.println(i);
    delay(1000);
  }
}




