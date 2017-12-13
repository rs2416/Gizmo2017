//---------SETUP---------------
//Photoresistor connected to pin A0
//Servo connected to pin 9



//---IRIS LIGHT SENSOR

const int light_pin = A0;  // pin with the photoresistor 
int light_value = 0; // variable to hold the value from the sensor

//----SERVO 

#include <Servo.h> //use the Arduino servo library
Servo myservo;  // create servo object to control a servo

//----CONSTANTS
const int ambient_light = 870; //setting ambient conditions/light threshold - can vary substantially from one plact to another
const int low_light = ambient_light - 80; //setting the low light condition and high light condition 
const int high_light = ambient_light +80;


const int iris_neutral = 65;    // variable to store the servo position for when the light is in the ambient level range
const int iris_open = 120; //servo position for open eye
const int iris_closed = 10;  //servo position for closed eye

void setup() {

  //-------SERIAL AND SERVO

  Serial.begin(9600);
  myservo.attach(9); //set servo to pin 9
  myservo.write(iris_neutral); //ensure the initial position is that of the iris in neutral position

}

void loop() {
  check_light(); //check_light function
  //a sub function was used here in anticipation of potentially using 'millis' to run this code and the stepper motor code on one board.
}

void check_light() {
  light_value = analogRead(light_pin); //assigning the light value to the raw analog reading from the light sensor
  Serial.println(light_value); //printing this value is useful for calibration and debugging
  delay(250); //a short delay to avoid allow some time for the eye to respond

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

