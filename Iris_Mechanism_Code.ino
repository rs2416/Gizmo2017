//---------SETUP---------------
//Photoresistor connected to pin A0
//Servo connected to pin 9



//---IRIS LIGHT SENSOR

const int light_pin = A0;  // pin with the photoresistor 
int light_value = 0; // variable to hold the value from the sensor

//----SERVO 

#include <Servo.h>
Servo myservo;  // create servo object to control a servo

//----CONSTANTS
const int ambient_light = 870; //setting ambient conditions/light threshold
const int low_light = ambient_light - 75; //setting the low light condition and high light condition 
const int high_light = ambient_light + 75;


const int iris_neutral = 90;    // variable to store the servo position
const int iris_open = 0; //servo position for open eye
const int iris_closed = 150;  //servo position for closed eye

void setup() {

  //-------SERIAL AND SERVO

  Serial.begin(9600);
  myservo.attach(9);
  myservo.write(iris_neutral);

}

void loop() {
  check_light(); //check_light function
}

void check_light() {
  light_value = analogRead(light_pin); //assigning the light value to the raw analog reading from the light sensor
  Serial.println(light_value);
  delay(500);

  if (low_light <= light_value <= high_light) { //if light value is greater than or equal to "low light" and less than or equal to "high light", the servo moves to neutral position
    myservo.write(iris_neutral);
  }
  
  if (light_value >= high_light) { //if light value is greater or equal to "high light", servo moves to iris open position
    myservo.write(iris_closed);
  }

  if (light_value <= low_light) { //if light value is less than or equal to low light, servo moves to iris open position
    myservo.write(iris_open);
  }

  
}

