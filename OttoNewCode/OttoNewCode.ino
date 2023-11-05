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
//-----------------------------------------
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
//-----------------------------------------

  if (distance < thresholdDistance) {
    // Object detected, play the victory gesture
    Otto.sing(S_sad);// Play the sad gesture
    Otto.walk(5,1000,-1); //Walk backward
    Otto.turn(3,1000,-1);//3 steps turning RIGHT 
    Otto.shakeLeg(2,1000,1);
    Otto.walk(5,1000,1);//Walk forward
    Otto.jitter(2, 1000, 20); //(small T)
    Otto.playGesture(OttoVictory); // Play the Victory gesture
    Otto.walk(20,1000,1); //Walk forward
    Otto.home();
  } else {
    // No object detected, play the sad gesture
    Otto.walk(15,1000,1); //Walk forward
    Otto.turn(3,1000,1);//3 steps turning LEFT
    Otto.playGesture(OttoWave); // Play the Wave gesture
    Otto.turn(3,1000,-1);//3 steps turning RIGHT 
    Otto.playGesture(OttoFart); // Play the Fart gesture
    Otto.walk(15,1000,1); //Walk forward
    Otto.shakeLeg(2,1000,1);
    Otto.playGesture(OttoFart); // Play the Fart gesture
    Otto.shakeLeg(2,1000,1);
    Otto.playGesture(OttoFart); // Play the Fart gesture
    Otto.walk(15,1000,1); //Walk forward  
  }
}
