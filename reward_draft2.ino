int nose;
int buzzPin = 8;
int sensorPin = 10;
int noseCount = 0;
int dt = 100;
int rewardCount = 200;



void setup() {
  // put your setup code here, to run once:
pinMode(buzzPin, OUTPUT);
pinMode(sensorPin, INPUT);
pinMode(13, OUTPUT);
Serial.begin(9600);
}



void loop() {
  // put your main code here, to run repeatedly:
nose = digitalRead(sensorPin);

noseCount = 0;
if (nose == 1) {
  if (noseCount == 0){
    digitalWrite (buzzPin, HIGH);
    delay(dt);
    digitalWrite (buzzPin, LOW);
  }
  while ((noseCount < rewardCount) && (nose == 1)){
    noseCount++;
    Serial.println(noseCount);
    delay(dt);
  }
  if (noseCount >= rewardCount){
      // give the reward
      digitalWrite(13, HIGH);
      delay(1000);
      digitalWrite(13, LOW);
    }
  while (nose == 1) { 
    nose = digitalRead(sensorPin);
  }
  }
}
