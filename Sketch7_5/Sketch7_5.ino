int pins_LED[] = {2,3,4,5};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int i = 0; i < 4; i++){
    pinMode(pins_LED[i], OUTPUT);
  }
  pinMode(A0, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int ADC_value = analogRead(A0); // ADC value
  int PWM_value[4] = {0, };

  Serial.println(String("ADC value : ") + ADC_value);
  for (int i = 3; i >= 0; i--) { 
  // Calculating the brightness of each LED
    if (ADC_value >= 256 * i) {
      PWM_value[i] = ADC_value - 256 * i;
      ADC_value -= (PWM_value[i] + 1);
    }
    // Adjusting the brightness of LEDs
    analogWrite(pins_LED[i], PWM_value[i]); 
    Serial.print(" ");
    Serial.print(PWM_value[i]);
  }
  Serial.println();
  delay(500);
}
