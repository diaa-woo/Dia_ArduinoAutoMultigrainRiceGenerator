#include <SPI.h>
#define Slave1 9
#define Slave2 10

int leftButton = 2;
int rightButton = 3;
int selectButton = 4;
int count = 0;

void setup() {
  pinMode(Slave1, OUTPUT);
  pinMode(Slave2, OUTPUT);
  pinMode(leftButton, INPUT_PULLUP);
  pinMode(rightButton, INPUT_PULLUP);
  pinMode(selectButton, INPUT_PULLUP);
  pinMode(5, OUTPUT);
  SPI.begin();
  Serial.begin(9600);
  digitalWrite(Slave1, HIGH);
  digitalWrite(Slave2, HIGH);

  SPI.setClockDivider(SPI_CLOCK_DIV16);
}

void loop() {
  
  if(!digitalRead(leftButton)) {
    digitalWrite(5, HIGH);
    count--;
    delay(100);
  }
  else if(!digitalRead(rightButton)) {
    digitalWrite(5, HIGH);
    count++;
    delay(100);
  }
  else if(!digitalRead(selectButton)) {
    digitalWrite(5, HIGH);
    digitalWrite(Slave2, LOW);

    SPI.transfer(count);
  
    digitalWrite(Slave2, HIGH);
    
    delay(100);
    count = 0;
  }
  else digitalWrite(5, LOW);

}
