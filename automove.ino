// 定義左右馬達的控制引腳
const int leftMotorPin1 = 10;  //左正
const int leftMotorPin2 = 11;  //左負
const int rightMotorPin1 = 5;  //右負
const int rightMotorPin2 = 6;  //右正
String movement;
int x ;

void setup() {
  // 將馬達控制引腳設置為輸出
  pinMode(leftMotorPin1, OUTPUT);
  pinMode(leftMotorPin2, OUTPUT);
  pinMode(rightMotorPin1, OUTPUT);
  pinMode(rightMotorPin2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    movement = Serial.readString();
    x = movement.toInt();
  }
  Serial.print(x);
  if(x<-100)
  {
    x = -100;    
  }
  if(x>100)
  {
    x = 100;
  }

  if (x >= -100 && x < -50) {
    analogWrite(leftMotorPin1, 100);
    analogWrite(leftMotorPin2, 0);
    analogWrite(rightMotorPin1, 0);
    analogWrite(rightMotorPin2, 220);
     Serial.print("ok1");
  } else if (x >= -50 && x < 0) {
    analogWrite(leftMotorPin1, 0);
    analogWrite(leftMotorPin2, 100);
    analogWrite(rightMotorPin1, 0);
    analogWrite(rightMotorPin2, 220);
    Serial.print("ok2");
  } else if (x == 0) {
    analogWrite(leftMotorPin1, 0);
    analogWrite(leftMotorPin2, 220);
    analogWrite(rightMotorPin1, 0);
    analogWrite(rightMotorPin2, 220);
    Serial.print("ok3");
  } else if (x > 0 && x <= 50) {
    analogWrite(leftMotorPin1, 0);
    analogWrite(leftMotorPin2, 210);
    analogWrite(rightMotorPin1, 0);
    analogWrite(rightMotorPin2, 100);
    Serial.print("ok4");
  } else if (x > 50 && x <= 100) {
    analogWrite(leftMotorPin1, 0);
    analogWrite(leftMotorPin2, 210);
    analogWrite(rightMotorPin1, 0);
    analogWrite(rightMotorPin2, 0);
    Serial.print("ok5");
  }
}
