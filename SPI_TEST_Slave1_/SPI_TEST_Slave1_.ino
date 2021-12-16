#include<SPI.h>

void setup() {
  Serial.begin(9600);

  pinMode(MISO, OUTPUT);

  SPI.setClockDivider(SPI_CLOCK_DIV16);

  SPCR |= _BV(SPE);
  SPCR &= ~_BV(MSTR);
  SPCR |= _BV(SPIE);


}

byte C;

ISR (SPI_STC_vect) {
  C = SPDR;
  Serial.println(C);
}

void loop() {

}
