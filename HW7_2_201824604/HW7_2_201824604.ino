#include <pitches.h>

int speakerPin = 56;
int melody[] = {
  0, NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4
};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(speakerPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int reading = analogRead(A0);
  int note = map(reading, 0, 1023, 0, 8);

  int noteDuration = 500;
  tone(speakerPin, melody[note], noteDuration);

  delay(noteDuration);

  noTone(speakerPin);

  delay(1000);
}
