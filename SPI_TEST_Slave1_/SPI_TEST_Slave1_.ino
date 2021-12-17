#include<SPI.h>
#define CW 3
#define CLK 2

void setup() {

  //begin set
  Serial.begin(9600);


  //pinMode Set
  pinMode(MISO, OUTPUT);
  pinMode(CW, OUTPUT);
  pinMode(CLK, OUTPUT);


  //SPI Slave Set
  SPI.setClockDivider(SPI_CLOCK_DIV16);

  SPCR |= _BV(SPE);
  SPCR &= ~_BV(MSTR);
  SPCR |= _BV(SPIE);


  //set end
}

byte C;

ISR (SPI_STC_vect) {
  C = SPDR;
  Serial.println(C);
}

void loop() {
  if(C == 1) {
      digitalWrite(CW,LOW);
      delayMicroseconds(1000);
      digitalWrite(CLK, HIGH);
      delay(1000);
      digitalWrite(CLK, LOW);
      C = 0;
  }
}
