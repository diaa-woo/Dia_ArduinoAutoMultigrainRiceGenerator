#include<SPI.h>
#include<Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;

int motor1 = 2;
int motor2 = 3;
int motor3 = 4;

int runServo(int motorNum, int clockSec) {
  if(motorNum == 1) {
    servo1.write(115);
    delay(clockSec*1000);
    servo1.write(90);
  }
  else if(motorNum == 2) {
    servo2.write(115);
    delay(clockSec*1000);
    servo2.write(90);
  }
  else if(motorNum == 3) {
    servo3.write(115);
    delay(clockSec*1000);
    servo3.write(90);
  }
  return 1;
}

void setup() {

  Serial.begin(9600);
  

  pinMode(MISO, OUTPUT);
  servo1.attach(motor1);
  servo2.attach(motor2);
  servo3.attach(motor3);
  
  
  SPI.setClockDivider(SPI_CLOCK_DIV16);

  SPCR |= _BV(SPE);
  SPCR &= ~_BV(MSTR);
  SPCR |= _BV(SPIE);

  servo1.write(90);
  servo2.write(90);
  servo3.write(90);
}

byte C;

ISR (SPI_STC_vect) {
  C = SPDR;
  Serial.println(C);
}

void loop() {
  if(C > 10 && C < 20) {
    C = runServo(1, C-10);
    SPDR = C;
  }
  else if(C > 20 && C < 30) {
    C = runServo(2, C-20);
    SPDR = C;
  }
  else if(C > 30 && C < 40) {
    C = runServo(3, C-30);
    SPDR = C;
  }
}
