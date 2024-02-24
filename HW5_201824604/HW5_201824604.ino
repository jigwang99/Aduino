int pins_LED[] = {2,3,4,5};
int PWM_value[] = {0,63,127,191};

void setup() {
  Serial.begin(9600);
  for(int i = 0; i < 4; i++){
    pinMode(pins_LED[i], OUTPUT);
  }
}

void loop() {
  analogWrite(pins_LED[0], PWM_value[0]);
  analogWrite(pins_LED[1], PWM_value[1]);
  analogWrite(pins_LED[2], PWM_value[2]);
  analogWrite(pins_LED[3], PWM_value[3]);
  
  for(int i = 0; i<4; i++){
    PWM_value[i]++;
  }
  
  for(int i = 0; i<4; i++){
    if(PWM_value[i] == 255){
      if(i == 0){
        PWM_value[i] = 0;
        delay(500);
      }
      else if(i == 1){
        PWM_value[i] = 63;
        delay(500);
      }
      else if(i == 2){
        PWM_value[i] = 127;
        delay(500);
      }
      else if(i == 3){
        PWM_value[i] = 191;
        delay(500);
      }
    }
  }
  delay(10);
}
