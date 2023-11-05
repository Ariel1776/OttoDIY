#include <Otto.h>
Otto Otto;  //This is Otto!

#define LeftLeg 1 
#define RightLeg 2
#define LeftFoot 3 
#define RightFoot 4 
#define Buzzer  12

void setup() {
  Otto.init(LeftLeg, RightLeg, LeftFoot, RightFoot, true, Buzzer); //Set the servo pins and Buzzer pin
  Otto.sing(S_connection); //Otto wake up!
  Otto.home();


}

void loop() {
  Otto.sing(S_surprise);
  Otto.jump(1,500); // It doesn't really jumpl ;P
  
  delay(5000);
  Otto.jump(2,500); // It doesn't really jumpl ;P
  Otto.sing(S_sad);
  


}
