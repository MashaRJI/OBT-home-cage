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

if (nose == True) {
  if (noseCount == 0){
  digitalWrite (buzzPin, HIGH);
  delay(dt);
  digitalWrite (buzzPin, LOW);
  }
  delay(dt);
  noseCount++;
  if (nose == True){
    continue;
  }
  else {
    if (noseCount >= rewardCount){
      // give the reward
      noseCount = 0;
      return;
    } else {
      noseCount = 0
      return;
    }
  }
}
