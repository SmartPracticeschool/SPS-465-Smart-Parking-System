int trigPin = 11;    // Trigger
int echoPin = 12;    // Echo
long duration, cm, inches;
void setup() {
  //Serial Port begin
  Serial.begin (9600);
  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(4,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(7,OUTPUT);
}
void loop() {
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
 
  // Convert the time into a distance
  cm = (duration/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
    // Divide by 74 or multiply by 0.0135
  
  if (cm>100)
  {	
    Serial.println("Parking Slot is empty");
    Serial.print(cm);
    Serial.println(" centimeters away");
    digitalWrite(3,HIGH);
    delay(500);
    digitalWrite(3,LOW);
    delay(500);
    
  }
  else if(cm>50&&cm<=100)
  {
    Serial.println("Parking might be full");
    Serial.print(cm);
    Serial.println(" centimeters away");
    digitalWrite(2,HIGH);
    delay(500);
    digitalWrite(2,LOW);
    delay(500);
  }
  else if(cm>20&&cm<=50)
  {
    Serial.println("Parking slot full");
    Serial.print(cm);
    Serial.println(" centimeters away");
    
    digitalWrite(4,HIGH);
    delay(500);
    digitalWrite(4,LOW);
    delay(500);
  }
  else if(cm<20)
  {
    Serial.println("STOP");
    Serial.print(cm);
    Serial.println(" centimeters away");
    
    digitalWrite(7,HIGH);
    delay(500);
    digitalWrite(7,LOW);
    delay(500);
  }
}

  