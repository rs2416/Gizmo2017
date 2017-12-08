//-----SETUP------

//Sharp IR sensor 1 connected to A0 pin
//Sharp IR sensor 2 connected to A1 pin

//Stepper Motor connected with dual motor driver


const int IR_threshold = 10;
const int stepper_speed = 10;

int last_position = 0; // 0 = centre, -1 = left, 1 = right


//---MAIN MOVEMENT WITH IR 

#define sensorL A0 // Sharp IR Sensor 1 - LEFT
#define sensorR A1 // Sharp IR Sensor 2 - RIGHT

int left_distance;
int right_distance;


//----STEPPER

#include <Stepper.h>

const int stepsPerRevolution = 30;  // change this to fit the number of steps per revolution
// for your motor

int right = stepsPerRevolution; 
int left = -stepsPerRevolution;
int right_to_left = -2*stepsPerRevolution;
int left_to_right = 2*stepsPerRevolution;

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);


//------------------------------------------------------------SETUP------------------------------------------------------------
void setup() {
  

//-------SERIAL

  Serial.begin(9600);

//------Stepper

  myStepper.setSpeed(stepper_speed);
}


//-----------------------------------------------------------MAIN CODE------------------------------------------------------------------------
void loop() {

//----------SETUP FOR IR Sensors

//IR (Left)
  float voltsL = analogRead(sensorL)*0.0048828125;  // value from sensor * (5/1024)
  left_distance = 13*pow(voltsL, -1);
  delay(100);

//IR (Right)
  float voltsR = analogRead(sensorR)*0.0048828125;  // value from sensor * (5/1024)
  right_distance = 13*pow(voltsR, -1);
  delay(100);








  if (last_position == 0) { //ie. If the eye is in the centre
    if ((left_distance < IR_threshold) && (right_distance > IR_threshold)) { //Left IR sensed, turn left
      Serial.println("Left IR SENSED");
      Serial.println( "Left IR = ");Serial.println(left_distance);
      Serial.println("Right IR = ");Serial.println(right_distance);
      delay(100);

      Serial.println("left from centre");                         
      myStepper.step(left);
      last_position = -1;
      delay(100);
      }

    else if ((left_distance > IR_threshold) && (right_distance < IR_threshold)) { //Right IR sensed, turn right
      Serial.println("Right IR SENSED");
      Serial.println( "Left IR = ");Serial.println(left_distance);
      Serial.println("Right IR = ");Serial.println(right_distance);
      delay(100);

      Serial.println("right from centre");                         
      myStepper.step(right);
      last_position = 1;
      delay(100);
      }

//    else {
//      last_position = 0;
//    }
  }
  
  
  if (last_position == 1) { //ie. Eye is on the right
    if((left_distance < IR_threshold) && (right_distance > IR_threshold)) { //Left IR sensed, go all the way left

      Serial.println("Left IR SENSED");
      Serial.println( "Left IR = ");Serial.println(left_distance);
      Serial.println("Right IR = ");Serial.println(right_distance);
      delay(100);

      Serial.println("left from right");                         
      myStepper.step(right_to_left);
      last_position = -1;
      delay(100);
      }
    
    else if((left_distance > IR_threshold) && (right_distance > IR_threshold)) { //nothing sensed, return to centre
      Serial.println("Nothing sensed");
      Serial.println( "Left IR = ");Serial.println(left_distance);
      Serial.println("Right IR = ");Serial.println(right_distance);
      delay(100);

      Serial.println("right to centre");                         
      myStepper.step(left);
      last_position = 0;
      delay(100);
      }
    else if((left_distance < IR_threshold) && (right_distance < IR_threshold)) { //both sensed, go to centre
      Serial.println("Both sensed");
      Serial.println( "Left IR = ");Serial.println(left_distance);
      Serial.println("Right IR = ");Serial.println(right_distance);
      delay(100);
    
      Serial.println("right to centre");                         
      myStepper.step(left);
      last_position = 0;
      delay(100);
      }
//    else {
//      last_position = 1;
//      }         
  }

  if (last_position == -1) {
    if((left_distance > IR_threshold) && (right_distance < IR_threshold)) { //Right IR sensed, go all the way right
      Serial.println("Right IR SENSED");
      Serial.println( "Left IR = ");Serial.println(left_distance);
      Serial.println("Right IR = ");Serial.println(right_distance);
      delay(100);

      Serial.println("right from left");                         
      myStepper.step(left_to_right);
      last_position = 1;
      delay(100);
      }

    else if((left_distance > IR_threshold) && (right_distance > IR_threshold)) { //nothing sensed, return to centre
      Serial.println("Nothing sensed");
      Serial.println( "Left IR = ");Serial.println(left_distance);
      Serial.println("Right IR = ");Serial.println(right_distance);
      delay(100);

      Serial.println("left to centre");                         
      myStepper.step(right);
      last_position = 0;
      delay(100);
      }

    else if((left_distance < IR_threshold) && (right_distance < IR_threshold)) { //both sensed, go to centre
      Serial.println("Both sensed");
      Serial.println( "Left IR = ");Serial.println(left_distance);
      Serial.println("Right IR = ");Serial.println(right_distance);
      delay(100);
    
      Serial.println("left to centre");                         
      myStepper.step(right);
      last_position = 0;
      delay(100);  
      }

//    else {
//      last_position = -1;
//      }
  }
}




