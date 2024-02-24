int vResistor = A0; // Pin A0 connected to a Potentiometer

void setup() {
  Serial.begin(9600); // Open the serial port at 9600 bps
  pinMode(vResistor, INPUT);
}

void loop() {
// Read the value form a potentiometer and print it
  Serial.println(analogRead(vResistor)); 
  delay(1000); // Wait for a second (1000ms)
}