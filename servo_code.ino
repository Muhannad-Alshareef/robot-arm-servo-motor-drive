#include <Servo.h>

Servo Base;  // create servo object to control a servo
Servo Shoulder;
Servo Elbow;
Servo Wrist;
Servo Gripper; 

int BasePot = 5;  // analog pin used to connect the potentiometer
int BaseVal;    // variable to read the value from the analog pin
int ShoulderPot = 4;
int ShoulderVal; 
int ElbowPot = 3;
int ElbowVal;
int WristPot = 2;
int WristVal;
int GripperPot = 1;
int GripperVal;

//-----electronic switching for the servo-motors-----
int powerInput = 2; //a switch is used in the schematics but a signal coming from a wireless module can be used
int powerVal;
int BaseSW = 3;     //signal to turn on or off the mosfet powering the servo-motor 
int ShoulderSW = 4;
int ElbowSW = 5;
int WristSW = 6;
int GripperSW = 7;


void setup() {
  Base.attach(8);  // attaches the servo on pin 8 to the servo object
  Shoulder.attach(9);
  Elbow.attach(10);
  Wrist.attach(11);
  Gripper.attach(12);

  pinMode(powerInput,INPUT);
  pinMode(BaseSW,OUTPUT);
  pinMode(ShoulderSW,OUTPUT);
  pinMode(ElbowSW,OUTPUT);
  pinMode(WristSW,OUTPUT);
  pinMode(GripperSW,OUTPUT);
  
  //---turn the mosfets on-------
  digitalWrite(BaseSW,HIGH);
  digitalWrite(ShoulderSW,HIGH);
  digitalWrite(ElbowSW,HIGH);
  digitalWrite(WristSW,HIGH);
  digitalWrite(GripperSW,HIGH);
  
  //----initialize at 90 degrees--------
  Base.write(90);
  Shoulder.write(90);
  Elbow.write(90);
  Wrist.write(90);
  Gripper.write(90);
  delay(2000);
}

void loop() {
  powerVal=digitalRead(powerInput);
  if (powerVal==1){
  //-----turn on the motors----
  digitalWrite(BaseSW,HIGH);
  digitalWrite(ShoulderSW,HIGH);
  digitalWrite(ElbowSW,HIGH);
  digitalWrite(WristSW,HIGH);
  digitalWrite(GripperSW,HIGH);
  
  //-------------------BASE SERVO-------------------
  BaseVal = analogRead(BasePot);        // reads the value of the potentiometer (value between 0 and 1023)
  BaseVal = map(BaseVal, 0, 1023, 0, 180);  // scale it to use it with the servo (value between 0 and 180)
  Base.write(BaseVal);                  // sets the servo position according to the scaled value
  //-------------------SHOULDER SERVO-------------------
  ShoulderVal = analogRead(ShoulderPot);       
  ShoulderVal = map(ShoulderVal, 0, 1023, 0, 180);  
  Shoulder.write(ShoulderVal);          
  //-------------------ELBOW SERVO-------------------
  ElbowVal = analogRead(ElbowPot);       
  ElbowVal = map(ElbowVal, 0, 1023, 0, 180);  
  Elbow.write(ElbowVal);
  //-------------------WRIST SERVO-------------------
  WristVal = analogRead(WristPot);       
  WristVal = map(WristVal, 0, 1023, 0, 180);  
  Wrist.write(WristVal);
  //-------------------GRIPPER SERVO-------------------
  GripperVal = analogRead(GripperPot);       
  GripperVal = map(GripperVal, 0, 1023, 0, 180);  
  Gripper.write(GripperVal);
  } 
    else {
      digitalWrite(BaseSW,LOW);
      digitalWrite(ShoulderSW,LOW);
      digitalWrite(ElbowSW,LOW);
      digitalWrite(WristSW,LOW);
      digitalWrite(GripperSW,LOW); 
      }
  
}
