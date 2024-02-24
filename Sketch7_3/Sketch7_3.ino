int RGB_LED[] = {6,7,8};

void setup() {
  // put your setup code here, to run once:
  for(int i = 0; i<3; i++){
    pinMode(RGB_LED[i], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(RGB_LED[1], HIGH);
  digitalWrite(RGB_LED[2], HIGH);
  for(int i =255; i>=0; i--){
    analogWrite(RGB_LED[0], i);
    delay(10);
  }

  digitalWrite(RGB_LED[0], HIGH);
  digitalWrite(RGB_LED[2], HIGH);
  for(int i =255; i>=0; i--){
    analogWrite(RGB_LED[1], i);
    delay(10);
  }
  digitalWrite(RGB_LED[0], HIGH);
  digitalWrite(RGB_LED[1], HIGH);
  for(int i =255; i>=0; i--){
    analogWrite(RGB_LED[2], i);
    delay(10);
  }
}
