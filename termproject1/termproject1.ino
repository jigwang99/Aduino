#include <SoftwareSerial.h>
#include <LiquidCrystal.h>
#include <Servo.h>

#define BT_RXD 8
#define BT_TXD 7
SoftwareSerial bluetooth(BT_RXD, BT_TXD); // 블루투스 연결

LiquidCrystal lcd(44, 45, 46, 47, 48, 49); // LCD 연결

Servo Servo1, Servo2; // 1번보관함, 2번보관함
int servoPin1 = 11;
int servoPin2 = 12;

int servo1angle = 90;        // 초기값: 잠김
int servo2angle = 90;

int vibrationMotor = 3;     // 진동모터

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  bluetooth.begin(9600);

  Servo1.attach(servoPin1);
  Servo2.attach(servoPin2);
  Servo1.write(servo1angle);
  Servo2.write(servo2angle);

  lcd.begin(16, 2);            // lcd 초기화
  lcd.setCursor(0, 0);

  pinMode(vibrationMotor, OUTPUT);
}

void printState(){
  int state[2];
  if(Serial1.available()){
    state = Serial1.read();
  }
  lcd.setCursor(0, 0);        //  0열
  if(state[0]){
    lcd.print("door1 opened");  
  }
  else if(!state[0]){
    lcd.print("door1 closed");
  }
  lcd.setCursor(0, 1);        //  1열
  if(state[1]){
    lcd.print("door2 opened");
  }
  else if(!state[1]){
    lcd.print("door2 closed");
  }
}


void controlDoor(){

  int controll;
  if(bluetooth.available()){
    controll = bluetooth.read();
  }

  if(controll == 1){                     // 1번 보관함
    if(servo1angle == 0){         // 열림 -> 닫힘
      servo1angle = 90;
    }
    else{                         // 닫힘 -> 열림
      servo1angle = 0;
    }
    Servo1.write(servo1angle);
  }
  if(controll == 2){                     // 2번보관함 
    if(servo2angle == 0){          // 열림 -> 닫힘
      servo2angle = 90;
    }
    else{                           // 닫힘 -> 열림
      servo2angle = 0;
    }
    Servo2.write(servo2angle);
  }
}

void controlVib(){                 // 반복시 20초에 한번 진동모터 작동 -> 수정필요
  digitalWrite(vibrationMotor, 100);
  delay(1000);
  digitalWrite(vibrationMotor, 0);
  delay(19000);
}

void loop() {
  printState();
  controlDoor();
}
