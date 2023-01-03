enum {
  NO_MOUSE, DETECTED, WAITING, //REWARD as a case?
  };
unsigned char sensorState;

bool isReward = TRUE;
const int sensorPin = 2;
const int buzzPin = 8;
const int ledPin = 13;
volatile int mouseFlag;

const int mouseTime = 3000;
const int buzzTime = 1000;
unsigned long prevMillis = 0;
unsigned long crntMillis = 0; //start, end millis better?



void setup() {
  // put your setup code here, to run once:
pinMode(buzzPin, OUTPUT);
pinMode(sensorPin, INPUT);
pinMode(ledPin, OUTPUT);
Serial.begin(9600);

attachInterrupt(digitalPinToInterrupt(sensorPin), ISR_mouse, RISING);
}


void loop() {
  // put your main code here, to run repeatedly:
switch (sensorState) {
  case NO_MOUSE:
    Serial.println('no mouse');
    
    if (mouseFlag) { //mouse appeared, isr run
      prevMillis = millis();
      digitalWrite(buzzPin, HIGH);
      sensorState = WAITING;
      break;

    } else { //as in the reference, but is it necessary?
      break;
    }
  
  case WAITING:
    Serial.println('waiting');
    if ( millis() - prevMillis > buzzTime ){
      digitalWrite(buzzPin, LOW);
    }
    if ( digitalRead(sensorPin == 0) ){
      crntMillis = millis();
      if ( prevMillis - crntMillis >= mouseTime ) {
        Serial.println('reward');
        digitalWrite(ledPin, HIGH);
        //sweet water valve
      }
      mouseFlag = 0;
      sensorState = NO_MOUSE;
      break;
    }
    } 
  
  case REWARD: 
    // open the valve

}
}


void ISR_mouse() {
  mouseFlag = 1; //or mouseState = DETECTED
}
