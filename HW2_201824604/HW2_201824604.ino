int nState = 1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(nState){
    Serial.println("Enter 2 Integers to add");
    nState = 0;
  }

  while(Serial.available() == 0) {}
  int num1 = Serial.parseInt();

  while(Serial.available() == 0) {}
  int num2 = Serial.parseInt();

  int sum = num1 + num2;

  Serial.print(num1);
  Serial.print(" + ");
  Serial.print(num2);
  Serial.print(" = ");
  Serial.println(sum);
  
  nState = 1;
}
