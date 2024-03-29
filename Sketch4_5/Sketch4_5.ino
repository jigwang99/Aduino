void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  // array of strings
  String str[5] = {"abc", "ABC", "!@#", "라라라", "123"};

  // string sort
  for(int i = 0; i < 4; i++){
    for(int j = i+1; j < 5; j++) {
      int compare = str[i].compareTo(str[j]);
      if (compare > 0){ // sorts an array in ascending order
        String temp = str[i];
        str[i] = str[j];
        str[j] = temp;
      }
    }
  }

  //prints an sorted array of strings
  for (int i = 0; i < 5; i++){
    Serial.println(String(i) + " : " + str[i]);
  }

  while(true);
}
