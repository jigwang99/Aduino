int pins_LED[] = {2, 3, 4, 5}; // Pins connected to LEDs
  void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 4; i++) {
    pinMode(pins_LED[i], OUTPUT);
  }
  pinMode(A0, INPUT); // Pin A0 connected to a Potentiometer
}
void loop() {
  int ADC_value = analogRead(A0); // ADC value
  int PWM_value = ADC_value >> 2; // PWM value
  Serial.print(String("ADC value : ") + ADC_value);
  Serial.println(String(", PWM value : ") + PWM_value);
  for (int i = 0; i < 4; i++) { // Adjusting the brightness of LEDs
    analogWrite(pins_LED[i], PWM_value);
  }
  delay(1000);
}