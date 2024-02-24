// 0에서 9까지 숫자 표현을 위한 세그먼트 a, b, c, d, e, f, g, dp의 패턴
byte patterns[] = {
  0xFC, 0x60, 0xDA, 0xF2, 0x66, 0xB6, 0xBE, 0xE4, 0xFE, 0xE6 };

int digit_select_pin[] = {66, 67, 68}; // 자릿수 선택 핀

// 7세그먼트 모듈 연결 핀 ‘a, b, c, d, e, f, g, dp’ 순서
int segment_pin[] = {58, 59, 60, 61, 62, 63, 64, 65};

int button = 14;

int counter = 0;
boolean countUp = true;
int buttonState = HIGH;
int lastButtonState = HIGH;

int seconds = 0;
int minutes = 0;
int time_current, time_previous;


void show_digit(int pos, int number) {
  for (int i = 0; i < 3; i++) {
    if (i + 1 == pos) 
      digitalWrite(digit_select_pin[i], LOW);
    else
      digitalWrite(digit_select_pin[i], HIGH);
  }
  for (int i = 0; i < 8; i++) {
    boolean on_off = bitRead(patterns[number], 7 - i);
    digitalWrite(segment_pin[i], on_off);
  }
}

void show_3_digit(int number) {
  number = number % 1000;
  int hundreds = number / 100;
  number = number % 100;
  int tens = number / 10;
  int ones = number % 10;
  show_digit(1, hundreds);
  delay(5);
  show_digit(2, tens);
  delay(5);
  show_digit(3, ones);
  delay(5);
}

void setup() {
  Serial.begin(9600);
  pinMode(button, INPUT);
  for (int i = 0; i < 3; i++) {
    pinMode(digit_select_pin[i], OUTPUT);
  }
  for (int i = 0; i < 8; i++) {
    pinMode(segment_pin[i], OUTPUT);
  }
  time_previous = millis();
}

void loop() {
  time_current = millis();

  if (time_current - time_previous >= 1000) { 
    time_previous = time_current;
    if (countUp) {
      counter++;
      if (counter == 1000) counter = 0;
    } else {
      counter--;
      if (counter < 0) counter = 999;
    }
    show_3_digit(counter);
  }

  buttonState = digitalRead(button);

  if (buttonState != lastButtonState) {
    if (buttonState == LOW) {
      countUp = !countUp;
    }
    delay(50);
  }

  lastButtonState = buttonState;
}
