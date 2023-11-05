#include <Servo.h>

Servo servoBase;
Servo servoA2;
Servo servoA3;
Servo servoA4;

void setup() {
  servoBase.attach(A1);
  servoBase.write(0);
}

void loop() {
  // Control servo on A1
  for (int i = 0; i <= 180; i += 10) {
    servoBase.write(i);
    delay(500);
  }
}
