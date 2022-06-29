#include<SPI.h>
#define CW 3
#define CLK 2

int time = 0;
int past = 0;

void setup() {

  //begin set
  Serial.begin(9600);


  //pinMode Set
  pinMode(MISO, OUTPUT);
  pinMode(CW, OUTPUT);
  pinMode(CLK, OUTPUT);
  

  //time set
  time = millis();


  //SPI Slave Set
  SPI.setClockDivider(SPI_CLOCK_DIV16);

  SPCR |= _BV(SPE);
  SPCR &= ~_BV(MSTR);
  SPCR |= _BV(SPIE);

  digitalWrite(CW, 1);

  //set end
}

byte C;
byte B;

ISR (SPI_STC_vect) {
  C = SPDR;
  Serial.println(C);
}

void loop() {
  if(C == 11) {
    digitalWrite(CLK, LOW);
    B = C;
    while(B == 11) {
      time = millis();
      if(time - past > 100) {
        past = time;
        B = C;
        Serial.println("Change");
        delayMicroseconds(1000);
      }
      digitalWrite(CLK, HIGH);
      delayMicroseconds(1000);
      digitalWrite(CLK, LOW);
      delayMicroseconds(1000);
    }
  }
  else if(C == 21) {
    digitalWrite(CLK, LOW);
    delay(500);
    digitalWrite(CW, 0);
    B = C;
    while(B == 21) {
      time = millis();
      B = C;
      if(time - past > 100) {
        past = time;
        B = C;
        Serial.println("Change");
        delayMicroseconds(1000);
      }
      digitalWrite(CLK, HIGH);
      delayMicroseconds(1000);
      digitalWrite(CLK, LOW);
      delayMicroseconds(1000);
    }
    delay(10);
    digitalWrite(CW, 1);
  }
  else digitalWrite(CLK, LOW);
  
}
