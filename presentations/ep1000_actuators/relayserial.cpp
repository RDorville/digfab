
const int RIN = 4;
int state = 0;

void setup()
{
  pinMode(RIN, OUTPUT);
  digitalWrite(RIN, state);
  Serial.begin(9600);
  Serial.println("Starting");
}

void loop()
{
  if (Serial.available()){
    // data available
    int data = Serial.read();
    Serial.print("Received: ");
    Serial.println(data);
    if (data != '0'){
      // request to turn ON
      if (state == LOW){
        digitalWrite(RIN, HIGH);
        state = HIGH;
        Serial.println("...Turn ON");
      }
    }
    else {
      // request to turn ODD
      if (state == HIGH){
        digitalWrite(RIN, LOW);
        state = LOW;
        Serial.println("...Turn OFF");
      }
    }
  }
}






