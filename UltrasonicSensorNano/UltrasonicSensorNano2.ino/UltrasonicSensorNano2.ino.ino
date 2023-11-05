#include <Otto.h>
Otto Otto;  // This is Otto!

#define LeftLeg 1
#define RightLeg 2
#define LeftFoot 3
#define RightFoot 4
#define Buzzer 12
#define Trigger 9
#define Echo 8



const int sensorPin = 8;
const int victoryDistance = 9; // Define the distance to trigger the victory gesture (in centimeters)

void setup() {
  Otto.init(LeftLeg, RightLeg, LeftFoot, RightFoot, true, Buzzer); // Set the servo pins and Buzzer pin
  pinMode(sensorPin, INPUT);
  pinMode(Trigger, OUTPUT);
  pinMode(Echo, INPUT);
  Otto.home();
}

void loop() {
  int distance = ultrasound();
  if (distance <= victoryDistance) {
    // An object is detected
    Otto.playGesture(OttoVictory); // Play the victory gesture
  } else {
    // No object is detected
    Otto.sing(S_sad);// Play the sad gesture
  }
  delay(1000); // Delay to avoid continuous detection and gestures
}

long ultrasound() {
  long duration;
  int distance;
  // Clears the TrigPin condition
  digitalWrite(Trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trigger, LOW);
  // Reads EchoPin, returns the sound wave travel...
  duration = pulseIn(Echo, HIGH);
  // Calculation Distance
  distance = duration * 0.034 / 2;
  // Display the distance on the Serial Monitor
  Serial.print("Distance ");
  Serial.print(distance);
  Serial.println("Cm");
  return distance;
}
