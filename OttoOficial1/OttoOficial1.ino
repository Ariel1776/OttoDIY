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
  // put your setup code here, to run once:
  Otto.init(LeftLeg, RightLeg, LeftFoot, RightFoot, true, Buzzer); //Set the servo pins and Buzzer pin
  Otto.sing(S_connection); //Otto wake up!
  Otto.home();
    delay(50);
  Otto.playGesture(OttoHappy);
}

void loop() {
  // put your main code here, to run repeatedly:
  distance = Otto.getRestState();

  if(distance < 200){
    danceParty();
  }else{
    Otto.walk(1, 1000, 1);
  }
}

void danceParty(){

  Otto.walk(3, 100, 1); //Walk 3steps
  delay(300);
  Otto.home();

  Otto.playGesture(OttoHappy); //Be happy
  delay(50);

  Otto.turn(2, 800, 1); //Turn left
  delay(50);
  
  Otto.moonwalker(3, 1000, 25,1); //LEFT
  Otto.home();

  Otto.playGesture(OttoLove); //Be happy
  delay(50);

  Otto.turn(2, 800, -1); //Turn right
  delay(50);
  
  Otto.jump(1, 2000); //JUMP
  delay(50);

  Otto.moonwalker(3, 1000, 25,1); //LEFT
  Otto.playGesture(OttoVictory); 
}
