
const int IN1 = 9;
const int IN2 = 8;
const int EN1 = 10;
const int SW = 12;
const int POT = A0;
int speed = 0;

void setup()
{
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  // pinMode(EN1, OUTPUT);
  pinMode(SW, INPUT_PULLUP);
}

void loop()
{
  int ain = analogRead(POT);
  int newspeed = map(ain, 0, 1023, 0, 255);
  if (newspeed != speed){
    // change the speed
    speed = newspeed;
  }
  // set direction
  if (digitalRead(SW) == HIGH)
  {
    // forward
  	digitalWrite(IN1, LOW);
  	digitalWrite(IN2, HIGH);
  }
  else
  {
    // reverse
  	digitalWrite(IN1, HIGH);
  	digitalWrite(IN2, LOW);
  }
  // set the speed using PWM
  analogWrite(EN1, speed);
}