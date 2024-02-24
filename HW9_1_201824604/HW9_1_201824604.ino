#include <Servo.h>

Servo servoMotor; // 서보 모터 객체 생성
int buttonPinIncrease = 14; // 증가 버튼에 연결된 디지털 핀 번호
int buttonPinDecrease = 15; // 감소 버튼에 연결된 디지털 핀 번호
int angle = 90; // 초기 서보 모터 위치

void setup() {
  servoMotor.attach(9); // 서보 모터를 9번 핀에 연결
  pinMode(buttonPinIncrease, INPUT); // 증가 버튼을 풀업으로 설정
  pinMode(buttonPinDecrease, INPUT); // 감소 버튼을 풀업으로 설정
}

void loop() {
  // 증가 버튼이 눌리면 서보 모터 위치 증가
  if (digitalRead(buttonPinIncrease) == HIGH) {
    angle += 10;
    if (angle > 180) angle = 180; // 최대 각도를 180도로 제한
    servoMotor.write(angle);
    delay(200); // 디바운싱을 위한 지연
  }

  // 감소 버튼이 눌리면 서보 모터 위치 감소
  if (digitalRead(buttonPinDecrease) == HIGH) {
    angle -= 10;
    if (angle < 0) angle = 0; // 최소 각도를 0도로 제한
    servoMotor.write(angle);
    delay(200); // 디바운싱을 위한 지연
  }
}
