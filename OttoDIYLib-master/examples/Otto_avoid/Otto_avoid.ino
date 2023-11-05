//---------------------------------------------------------------------------------------------------------------------------------------------------------------------
// Otto avoid obstacles with ultrasonic sensor sample sketch code
//-- Otto DIY invests time and resources providing open source code and hardware, 
//-- please support by purchasing kits from https://www.ottodiy.com/
//-- Make sure to have installed all libraries: https://github.com/OttoDIY/OttoDIYLib
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <Otto.h>
Otto Otto;  //This is Otto!
//----------------------------------------------------------------------
#define LeftLeg 1
#define RightLeg 2
#define LeftFoot 3
#define RightFoot 4
#define Buzzer 12
#define TrigerPin 9
#define EchoPin 8

long ultrasound() {
   long duration, distance;
   digitalWrite(TrigerPin,LOW);
   delayMicroseconds(2);
   digitalWrite(TrigerPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(TrigerPin, LOW);
   duration = pulseIn(EchoPin, HIGH);
   distance = duration/58;
   return distance;
}


void setup() {
  Otto.init(LeftLeg, RightLeg, LeftFoot, RightFoot, true, Buzzer); //Set the servo pins and Buzzer pin
  pinMode(TrigerPin, OUTPUT); 
  pinMode(EchoPin, INPUT); 

}

void loop() {
    if (ultrasound() <= 15) {
      Otto.sing(S_surprise);
      Otto.playGesture(OttoConfused);
      Otto.walk(2,1000,-1); // BACKWARD x2
      Otto.turn(3,1000,1); // LEFT x3
    }
    Otto.walk(1,1000,1); // FORWARD x1

}
