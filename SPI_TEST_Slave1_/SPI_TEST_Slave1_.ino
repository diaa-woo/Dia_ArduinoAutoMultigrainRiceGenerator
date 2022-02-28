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
    while(1) {
      B = C;
      if(B == 10) {
        Serial.println("Change");
        break;
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
    while(1) {
      B = C;
      if(B == 20) {
        Serial.println("Change");
        break;
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
