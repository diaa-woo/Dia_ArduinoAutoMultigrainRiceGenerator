#include<SPI.h>
#define CW 3
#define CLK 2

int pin1 = 4;
int pin2 = 5;
int pin3 = 6;

void setup() {

  //begin set
  Serial.begin(9600);


  //pinMode Set
  pinMode(MISO, OUTPUT);
  pinMode(CW, OUTPUT);
  pinMode(CLK, OUTPUT);
  pinMode(pin1, INPUT);
  pinMode(pin2, INPUT);
  pinMode(pin3, INPUT);


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
  
  if(C == 'B') {
    digitalWrite(CW, LOW);
    while(digitalRead(pin1) == 0) {
      digitalWrite(CLK, HIGH);
      SPDR = 0;
    }
    digitalWrite(CLK, LOW);
    SPDR = 1;
  }
}
