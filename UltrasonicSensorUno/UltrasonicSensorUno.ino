#define echoPin A0
#define trigPin 9

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  //Clears the TrigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  //Set the trigPin HIGH (ACTIVE) for 10Microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  //Reads EchoPin, returns the sound wave travel...
  duration = pulseIn(echoPin, HIGH);
  //Calcutaion Distance
  distance = duration * 0.034/2;
  //Display th distance on the Serial Monitr
  Serial.print("Distance");
  Serial.print(distance);
  Serial.println("Cm");
}
