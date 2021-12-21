#include <Servo.h> 
 
int servoPin = 2;

Servo servo; 

int angle = 0; // servo position in degrees 

void setup() 
{ 
    servo.attach(servoPin); 
} 


void loop() 
{ 
  servo.write(90);
} 
