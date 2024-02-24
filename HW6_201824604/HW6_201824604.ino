int pin_LED1 = 2;
int pin_LED2 = 3;

unsigned long time_previous1, time_previous2, time_current;
unsigned long interval1 = 1000;
unsigned long interval2 = 1000;
boolean LED_state1 = false;
boolean LED_state2 = false;

void setup() {
  Serial.begin(9600);
  pinMode(pin_LED1, OUTPUT);
  pinMode(pin_LED2, OUTPUT);
  pinMode(A0, INPUT);
  time_previous1 = millis();
  time_previous2 = millis();
}

void loop() {
  time_current = millis();

  int adc = analogRead(A0);
  interval1 = map(adc, 0, 1023, 500, 1500);
  interval2 = map(1023 - adc, 0, 1023, 500, 1500);

  // LED1을 제어
  if (time_current - time_previous1 >= interval1) {
    time_previous1 = time_current;
    LED_state1 = !LED_state1;
    digitalWrite(pin_LED1, LED_state1);
  }

  // LED2를 제어
  if (time_current - time_previous2 >= interval2) {
    time_previous2 = time_current;
    LED_state2 = !LED_state2;
    digitalWrite(pin_LED2, LED_state2);
  }
}
