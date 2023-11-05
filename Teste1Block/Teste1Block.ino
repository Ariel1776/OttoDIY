#include <Servo.h>
#include <Oscillator.h>
#include <Otto.h>
Otto Otto;  //Esse é o Otto!!!

//DECLARANDO VARIÁVEIS
#define LeftLeg 1 //Perna Esquerda
#define RightLeg 2 //Perna Direita
#define LeftFoot 3 //Pé Esquerdo
#define RightFoot 4 //Pé Direito
#define Buzzer 12 //Buzzer
#define TrigerPin 9 //Buzzer
#define EchoPin 8 //Buzzer


void setup() {
  // put your setup code here, to run once:
  pinMode(12, OUTPUT);
  Otto.init(LeftLeg, RightLeg, LeftFoot, RightFoot, true, Buzzer); //Set the servo pins and Buzzer pin
  Otto.home();

}

void loop() {
  Otto.walk(5,1000,1); // FORWARD
  Otto.sing(S_superHappy);
  delay(500);

  Otto.moonwalker(1, 1000, 25, 1);
  delay(500);
  
  Otto.walk(5,1000,-1); // BACKWARD
  delay(500);
  
  Otto.sing(S_fart3);
  Otto.flapping(1, 1000, 25, 1);
  Otto.home();
}
