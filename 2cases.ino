enum {
  NO_MOUSE, WAITING
  };
unsigned char sensorState;

const int sensorPin = 2;
//const int buzzPin = 8;
const int ledPin = 13;

//const int mouseTime = 3000;
//const int buzzTime = 1000;
//unsigned long inMillis = 0;
//unsigned long outMillis = 0;


void setup() {
  // put your setup code here, to run once:
//pinMode(buzzPin, OUTPUT);
pinMode(sensorPin, INPUT);
pinMode(ledPin, OUTPUT);
Serial.begin(9600);


}

void loop() {
  // put your main code here, to run repeatedly:

  switch (sensorState) {
    case NO_MOUSE:
      digitalWrite(ledPin, LOW);
      Serial.println("mouse out");
      if (digitalRead(sensorPin) == 1) {
        
        sensorState = WAITING;     
        break; 
      }
      else {
        break;
      }
    
    case WAITING:
      digitalWrite(ledPin, HIGH);
      Serial.println("mouse in");
      if (digitalRead(sensorPin)==0) {
        
        sensorState = NO_MOUSE;
        break;
      } 
      else {
        break;
      }
}

}

