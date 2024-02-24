int motionPin = 8;
int trigPin = 3;
int echoPin = 2;
int led1Pin = 11;
int led2Pin = 12;

void setup() {
  Serial.begin(9600);
  pinMode(motionPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
}

void loop() {
  int led1Bright = 0;
  
  int motion = digitalRead(motionPin);

  digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(trigPin, LOW);

  float duration = pulseIn(echoPin, HIGH);
  float distance = duration * 340 / 10000 / 2;

  if (distance > 100) {
    led1Bright = 0;
  } else {
    led1Bright = map(distance, 100, 0, 0, 255);
  }
  Serial.println(led1Bright);
  analogWrite(led1Pin, led1Bright);
  if(motion == 1) {
    Serial.println("Motion detected");
    digitalWrite(led2Pin, HIGH);
  } else {
    digitalWrite(led2Pin, LOW);
  } 

  delay(500);
}