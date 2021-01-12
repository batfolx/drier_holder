#include <Servo.h>


Servo servo;
int MIDPOINT = 110;
int END = 180;
int START = 30;
bool hold_door;
int val;
int inputPin = 8;
int yellowLedPin = 7;


void setup() {
  int servoPin = 9;
  pinMode(inputPin, INPUT);
  pinMode(yellowLedPin, OUTPUT);
  
  
  servo.attach(servoPin);

  
  Serial.begin(9600);
  
  // write to midpoint
  servo.write(MIDPOINT);
  digitalWrite(yellowLedPin, HIGH);
  hold_door = false;
  
  
  delay(500);
}

void loop() {

  // read value from pin
  val = digitalRead(inputPin);
  Serial.print("This is value ");
  Serial.println(val);

  // if button was pressed then switch boolean value
  if (val == HIGH) hold_door = true;
  else hold_door = false;

  // go downwards at 90 degree angle
  if (hold_door) {
    // if we hold the door then we want to turn led green on 
    // and yellow off
    servo.write(START);
    digitalWrite(yellowLedPin, LOW);
    delay(250);

  } else {
    servo.write(MIDPOINT);
    digitalWrite(yellowLedPin, HIGH);
    delay(250);

  }

  

}
