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
  // put your   // put your setup code here, to run once:
  Otto.init(LeftLeg, RightLeg, LeftFoot, RightFoot, true, Buzzer); //Set the servo pins and Buzzer pin
  Otto.home();

}

void loop() {
  Otto.walk(5,100,1); // FORWARD
  // Declare the Star Wars melody as a character array
  const char StarWars[] PROGMEM = "StarWars:d=4,o=5,b=160:32p,32f5,8f5,8a5,16p,16d6,16p,16c6,16p,16a#,16p,16a5,8p,16c6,16p,16f6,16p,16d6,16p,16c6,16p,16a#,16p,16a5,8p,16e6,16p,16f6,16p,16d6,16p,16c6,16p,16a#,16p,16a5,8p,16f5,16p,16d5,16p,16c5,16p,16a,16p,16a#,16p,16c,16p,16d,16p,16f,16p,16a,16p,16g,16p,16f#,16p,16f,16p,16c5,16p,16e5,16p,16a5,16p,16b5,16p,16c6,16p,16e6,16p,16f6,16p,16g6,16p,16a6,16p,16b6,16p,16c7,16p,16d7,16p,16e7,16p,16f7,16p,16g7,16p,16a7,16p,16b7,16p,16c8,16p,16a7,16";

  Otto.home();

}
