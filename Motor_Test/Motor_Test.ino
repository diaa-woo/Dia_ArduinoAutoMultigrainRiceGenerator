#define CW 3
#define CLK 2

void setup() {
  pinMode(CW, OUTPUT);
  pinMode(CLK, OUTPUT);
  digitalWrite(CW, 0);
  digitalWrite(CLK, LO);
}

void loop() {
  
  digitalWrite(CLK, HIGH);
  delayMicroseconds(1000);
  digitalWrite(CLK, LOW);
  delayMicroseconds(1000);

}