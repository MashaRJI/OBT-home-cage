int nose;
int buzzPin = ???;
int sensorPin = ???;


void setup() {
  // put your setup code here, to run once:
pinMode(buzzPin, OUTPUT);
pinMode(sensorPin, INPUT);
}


void loop() {
  // put your main code here, to run repeatedly:
nose = analogRead(sensorPin);

if (nose == ???) {
  delay(10);
  if (nose == ???){
    //continue
  } else{
    
  }
}

}
