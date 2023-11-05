#include <Otto.h>
Otto Otto;  // This is Otto!

#define LeftLeg 1
#define RightLeg 2
#define LeftFoot 3
#define RightFoot 4
#define Buzzer 12
#define trigPin 9
#define echoPin 8
const int thresholdDistance = 5;  // Adjust this value to set the detection distance

void setup() {
  Otto.init(LeftLeg, RightLeg, LeftFoot, RightFoot, true, Buzzer); // Set the servo pins and Buzzer pin
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(Buzzer, OUTPUT);
  Otto.home();
}

void loop() {
  long duration, distance;
  // Trigger the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Measure the echo time
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate distance in centimeters
  distance = (duration / 2) / 29.1;
  
  if (distance < thresholdDistance) {
    // Object detected, play the victory gesture
    Otto.playGesture(OttoVictory); // Play the victory gesture
    delay(1000); // Delay to prevent repeated detection
  } else {
    // No object detected, play the sad gesture
    Otto.sing(S_sad);// Play the sad gesture
  }
}
