extern volatile unsigned long timer0_millis;

#define CW 3
#define CLK 2
#define button 4

int cw = 1;
int clk = 0;
char input = 0;

unsigned long past = 0;
int flag = 0;
unsigned long time = millis();

void setup() {
  Serial.begin(9600);
  pinMode(CW, OUTPUT);
  pinMode(CLK, OUTPUT);
  pinMode(button, INPUT);
  digitalWrite(CW, cw);
  digitalWrite(CLK, 1);
}

void loop() {
  input = Serial.read();
  if(input=='1') {
    Serial.print("on");
    digitalWrite(CLK,0);
    delay(500);
    cw = !cw;
    digitalWrite(CLK, 1);
    digitalWrite(CW, cw);
  }
  digitalWrite(CLK, 1);
  delayMicroseconds(1000);
  digitalWrite(CLK, 0);
  delayMicroseconds(1000);
}
