int vResistor = A0; // Pin A0 connected to a Potentiometer
int pins_LED[] = {2, 3, 4, 5}; // Pins connected to LEDs
void setup() {
  Serial.begin(9600); // Open the serial port at 9600 bps
  pinMode(vResistor, INPUT);
  for (int i = 0; i < 4; i++) {
    pinMode(pins_LED[i], OUTPUT);
    digitalWrite(pins_LED[i], LOW);
  }
}
void loop() {
  int adc = analogRead(vResistor); // Read the value form a potentiometer
  int count_led = (adc >> 8) + 1; // Calculate the number of LEDs turned on
  for (int i = 0; i < 4; i++) { // LEDs output
    if (i < count_led)
      digitalWrite(pins_LED[i], HIGH);
    else
      digitalWrite(pins_LED[i], LOW);
  }
  // Printing out the ADC value and the number of LEDs turned on
  Serial.println(String("ADC : ") + adc + ", LED count : " + count_led);
  delay(1000); // Wait for a second (1000ms)
}
