String str[5];
int wordCount = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (wordCount < 5) {
    Serial.print("Enter the ");
    Serial.print(wordCount+1);
    Serial.print("th word -->");
    while (!Serial.available()) {
      // 사용자 입력 대기
    }

    str[wordCount] = Serial.readStringUntil('\n');
    str[wordCount].trim();
    Serial.println(str[wordCount]);
    
    if (str[wordCount].length() > 0) {
      wordCount++;
    }
  } else {
    // 문자열을 오름차순으로 정렬
    for (int i = 0; i < 4; i++) {
      for (int j = i + 1; j < 5; j++) {
        if (str[i].compareTo(str[j]) > 0) {
          String temp = str[i];
          str[i] = str[j];
          str[j] = temp;
        }
      }
    }

    Serial.println("After Sorting");
    for(int i = 0; i<5; i++){
      Serial.println(str[i]);
    }
    
    wordCount = 0;
  }
}