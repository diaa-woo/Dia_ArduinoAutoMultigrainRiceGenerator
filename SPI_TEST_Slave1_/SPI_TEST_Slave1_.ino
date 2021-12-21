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
byte B;

ISR (SPI_STC_vect) {
  C = SPDR;
  Serial.println(C);
}

void loop() {
  if(C == 11) {
    digitalWrite(CW, HIGH);
    B = C;
    while(B == 11) {
      B = C;
      Serial.println(B);
      digitalWrite(CLK, HIGH);
      delayMicroseconds(1000);
      digitalWrite(CLK, LOW);
      delayMicroseconds(1000);
    }
    Serial.println("Break");
  }
  else digitalWrite(CLK, LOW);
  
}
