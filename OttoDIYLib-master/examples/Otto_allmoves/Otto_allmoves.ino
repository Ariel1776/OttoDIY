//----------------------------------------------------------------
//-- Otto All moves test
//-- Otto DIY invests time and resources providing open source code and hardware, 
//-- please support by purchasing kits from https://www.ottodiy.com/
//-- Make sure to have installed all libraries: https://github.com/OttoDIY/OttoDIYLib
//-----------------------------------------------------------------
#include <Otto.h>
Otto Otto;  //This is Otto!

#define LeftLeg 1 
#define RightLeg 2
#define LeftFoot 3 
#define RightFoot 4 
#define Buzzer  12
#define trigPin = 8
#define echoPin = 9
///////////////////////////////////////////////////////////////////
//-- Setup ------------------------------------------------------//
///////////////////////////////////////////////////////////////////
void setup(){
  Otto.init(LeftLeg, RightLeg, LeftFoot, RightFoot, true, Buzzer); //Set the servo pins and Buzzer pin
  Otto.sing(S_connection); //Otto wake up!
  Otto.home();
    delay(50);
  Otto.playGesture(OttoHappy);
}

///////////////////////////////////////////////////////////////////
//-- Principal Loop ---------------------------------------------//
///////////////////////////////////////////////////////////////////
void loop() { 
  Otto.walk(2,1000,1); //2 steps, "TIME". IF HIGHER THE VALUE THEN SLOWER (from 600 to 1400), 1 FORWARD
  Otto.walk(2,1000,-1); //2 steps, T, -1 BACKWARD 
  Otto.turn(2,1000,1);//3 steps turning LEFT
  Otto._tone(10, 3, 1);
  Otto.bendTones (100, 200, 1.04, 10, 10);
    Otto.home();
    delay(100);  
  Otto.turn(2,1000,-1);//3 steps turning RIGHT 
  Otto.bend (1,500,1); //usually steps =1, T=2000
  Otto.bend (1,2000,-1);     
  Otto.shakeLeg (1,1500, 1);
    Otto.home();
    delay(100);
  Otto.shakeLeg (1,2000,-1);
  Otto.moonwalker(3, 1000, 25,1); //LEFT
  Otto.moonwalker(3, 1000, 25,-1); //RIGHT  
  Otto.crusaito(2, 1000, 20,1);
  Otto.crusaito(2, 1000, 20,-1);
    delay(100); 
  Otto.flapping(2, 1000, 20,1);
  Otto.flapping(2, 1000, 20,-1);
    delay(100);        
  Otto.swing(2, 1000, 20);
  Otto.tiptoeSwing(2, 1000, 20);
  Otto.jitter(2, 1000, 20); //(small T)
  Otto.updown(2, 1500, 20);  // 20 = H "HEIGHT of movement"T 
  Otto.ascendingTurn(2, 1000, 50);
  Otto.jump(1,500); // It doesn't really jumpl ;P
  Otto.home();
     delay(100); 
  Otto.sing(S_cuddly);
  Otto.sing(S_OhOoh);
  Otto.sing(S_OhOoh2);
  Otto.sing(S_surprise);
  Otto.sing(S_buttonPushed);       
  Otto.sing(S_mode1);        
  Otto.sing(S_mode2);         
  Otto.sing(S_mode3);  
  Otto.sing(S_sleeping);
  Otto.sing(S_fart1);
  Otto.sing(S_fart2);
  Otto.sing(S_fart3);
  Otto.sing(S_happy);
  Otto.sing(S_happy_short);                   
  Otto.sing(S_superHappy);   
  Otto.sing(S_sad);               
  Otto.sing(S_confused);
  Otto.sing(S_disconnection);
    delay(100);  

}
