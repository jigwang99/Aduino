int motorPin = 9; 
int buttonPin = 14;
int state = 0;
int speed = 255;

void setup() {
  pinMode(buttonPin, OUTPUT);
  pinMode(38, OUTPUT);
  pinMode(39, OUTPUT);
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
 if(digitalRead(buttonPin) == HIGH){
    state++;
    if(state == 3) state = 0;
    if(state == 0){
      analogWrite(motorPin, speed/2);
    }
    else if(state == 1){
      analogWrite(motorPin, speed);
    }
    else{
      analogWrite(motorPin, 0);
    }

    delay(100);
 } 
}