int pin_LED[4] = {2, 3, 4, 5};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int i = 0; i<4; i++){
    pinMode(pin_LED[i], OUTPUT);
  }
}

void readIlluminance() {
  int reading = analogRead(56);
  
  if(reading < 150){
    for(int i = 0; i < 4; i++){
      digitalWrite(pin_LED[i], HIGH);
    }
  }
  else {
    for(int i = 0; i< 4; i++){
      if(reading >= map(i+1, 1, 4, 150, 1023)){
        digitalWrite(pin_LED[i], HIGH);
      }
      else {
        digitalWrite(pin_LED[i], LOW);
      }
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  readIlluminance();
  delay(1000);
}
