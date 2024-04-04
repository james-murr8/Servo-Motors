#include <Servo.h>
int servoPin = 9; //
int potpin = A0; //
int val; //variable to read the value from the analog pin

Servo servo; //create Servo object
Servo myservo; // create servo object to control a servo

int angle = 0;

void setup() {
  // put your setup code here, to run once:
  servo.attach(servoPin);
  myservo.attach(servoPin); //attach the servo on pin 9 to the servo object
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(potpin); //reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 0, 180); //scale it to use it with the servo (value between 0 to 180)
  myservo.write(val); //the servo position according to the scaled value
  delay(15); //waits for the servo to get there (this is required)

  //rotate from 0 to 180 degrees
  for(angle = 0; angle < 180; angle++)
  {
    servo.write(angle);
    delay(15);    //wait for servo to reach target pos.
  }

  //now scan back from 180 to 0 degrees
  for(angle = 180; angle > 0; angle--)
  {
    servo.write(angle);
    delay(15);
  }
}