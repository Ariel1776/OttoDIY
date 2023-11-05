#include <Servo.h>
#include <Oscillator.h>
#include <Otto.h>
Otto Otto;  //This is Otto!

#define LeftLeg 1
#define RightLeg 2
#define LeftFoot 3
#define RightFoot 4
#define Buzzer 12
#define TrigerPin 9
#define EchoPin 8

//Variables for dance routine
bool obstacleDetected = false;
int distance = 0;

void setup() {
  Otto.init(LeftLeg, RightLeg, LeftFoot, RightFoot, true, Buzzer); //Set the servo pins and Buzzer pin
  Otto.home();
  delay(50);
  Otto.sing(S_happy);

}

void loop() {
  // put your main code here, to run repeatedly:
  distance = Otto.getRestState();

  if(distance < 100){
    danceParty();
  }else{
    Otto.walk(1, 1000, 1);
    Otto.sing(S_sad);
  }
}

void danceParty(){
  Otto.playGesture(OttoFart);
 }
