int trigPin = 11;    // Trigger
int echoPin = 12;    // Echo
long duration, cm;
void setup() 
{
  //Serial Port begin
  Serial.begin (9600);
  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(4,OUTPUT);
  pinMode(3,OUTPUT);
  
}
void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
 
  cm = (duration/2) / 29.1;     
  
  if (cm>100)
  {	digitalWrite(3,LOW);
    Serial.println("Parking Slot is empty");
    Serial.print("Object is  ");
    Serial.print(cm);
    Serial.println(" centimeters away");
    digitalWrite(4,HIGH);
    
   }
  else if(cm<90)
  {	digitalWrite(4,LOW);
    Serial.println("Parking Slot is full");
    Serial.print("Object is  ");
    Serial.print(cm);
    Serial.println(" centimeters away");
    digitalWrite(3,HIGH);
    
  
  
  }
}

