#include <SoftwareSerial.h>
SoftwareSerial mySerial(4, 5);

int illuminance;
bool illuminanceState = false;

int door;
bool doorState = false;

int rtc;

void setup() {
  mySerial.begin(9600);
  Serial.begin(9600);
}

bool readIlluminance(){         // 조도센서
  int illuminance = analogRead(55);
  if(illuminance > 100){                 // 임의의 조도센서값(조정 필요)
    if(illuminanceState == false){       // 닫힘 -> 열림  
      illuminanceState = true;
    }
  }
  else{                                 // 열림 -> 닫힘 
    if(illuminanceState == true){
      illuminanceState = false;
    }
  }
  return illuminanceState;
}

bool readDoor(){                   //마그네틱센서
  int pre_door = door;
  int door = analogRead(56);
  if(pre_door != door){            // 문열림센서 변화 감지
    if(door == HIGH){              // 닫힘
      doorState = false;
    }
    else                           // 열림 
      doorState = true;
  }
  return doorState;
}

void readRTC(){                    // RTC
  int rtc = analogRead(57);
}

void loop() {
  int state[2] = {readIlluminance(), readDoor()};  // (1번보관함, 2번보관함)
  mySerial.write(state);  

}
