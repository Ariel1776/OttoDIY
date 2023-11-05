#include <Servo.h>

Servo servoBase;
Servo servoA2;
Servo servoA3;
Servo servoA4;

void setup() {
  servoBase.attach(A1);
  servoA2.attach(A2);
  servoA3.attach(A3);
  servoA4.attach(A4);
  
  servoBase.write(0);
  servoA2.write(0);
  servoA3.write(0);
  servoA4.write(0);
}

void loop() {
  // Control servo on A1
  for (int i = 0; i <= 180; i += 10) {
    servoBase.write(i);
    delay(2000);
  }
  
  // Control servo on A2
  for (int i = 0; i <= 180; i += 10) {
    servoA2.write(i);
    delay(2000);
  }
  
  // Control servo on A3
  for (int i = 0; i <= 180; i += 10) {
    servoA3.write(i);
    delay(2000);
  }
  
  // Control servo on A4
  for (int i = 0; i <= 180; i += 10) {
    servoA4.write(i);
    delay(2000);
  }
}
