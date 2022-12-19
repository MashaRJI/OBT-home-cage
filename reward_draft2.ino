int nose;
int buzzPin = 8;
int sensorPin = 10;
int noseCount = 0
int dt = 100
int rewardCount = 10


void setup() {
  // put your setup code here, to run once:
pinMode(buzzPin, OUTPUT);
pinMode(sensorPin, INPUT);
}


void loop() {
  // put your main code here, to run repeatedly:
nose = analogRead(sensorPin);

noseCount = 0
while (nose == True) {
  if (noseCount == 0){
    digitalWrite (buzzPin, HIGH);
    delay(dt);
    digitalWrite (buzzPin, LOW);
  }
  while (noseCount < rewardCount){
    noseCount++
    delay(dt);
  }
  else {
    if (noseCount >= rewardCount){
      // give the reward
      return;
    }
  }
}
