#include <LiquidCrystal_I2C.h>

extern volatile unsigned long timer0_millis;
#include <SPI.h>
#include <Wire.h>

#define Slave1 9
#define Slave2 10
#define DEBUG_LED 5

//setup IIC LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

int leftButton = 2;
int rightButton = 3;
int selectButton = 4;
int mode = 1;
int select = 0;
int buf = 1;
int pin1 = 6;
int pin2 = 7;
int pin3 = 8;


unsigned long past = 0;
int flag = 0;
unsigned long time = millis();

byte C = 0;


void modeAuto() {
  char autoMode[3] = {'B','G','R'};
  int modeCount = 0;
  int check1 = 0;
  int check2 = 0;
  int motor = 0;

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Auto mode on");
  delay(500);
  while(1) {
    time = millis();
    if(time - past > 1000) {
      past = time;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("What you want?");
      lcd.setCursor(0,1);
      lcd.print("C");
      lcd.setCursor(7,1);
      lcd.print(autoMode[modeCount]);
      lcd.setCursor(14,1);
      lcd.print("OK");
    }
    if(digitalRead(leftButton) == 0) {
      return;
    }
    else if(digitalRead(rightButton) == 0) {
      modeCount++;
      delay(100);
      if(modeCount>2) {
        modeCount = 0;
      }
    }
    else if(digitalRead(selectButton) == 0) {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Are you sure?");
      lcd.setCursor(4,1);
      lcd.print("N");
      lcd.setCursor(13,1);
      lcd.print("Y");
      delay(300);
      while(check1 == 0 && check2 == 0) {
        if(digitalRead(leftButton) == 0) check1++;
        else if(digitalRead(selectButton) == 0) check2++;
      }
      if(check1) return;
      else if(check2) {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Runnning...");
        if(autoMode[modeCount] == 'B') {
          digitalWrite(Slave1, LOW);
          SPI.transfer(11);
          while(digitalRead(pin1) == 1);
          SPI.transfer(10);
          digitalWrite(Slave1, HIGH);
          digitalWrite(Slave2, LOW);
          SPI.transfer(14);
          delay(4500);
          digitalWrite(Slave2, HIGH);

          digitalWrite(Slave1, LOW);
          SPI.transfer(11);
          while(digitalRead(pin2) == 1);
          SPI.transfer(10);
          digitalWrite(Slave1, HIGH);
          digitalWrite(Slave2, LOW);
          SPI.transfer(22);
          delay(4500);
          digitalWrite(Slave2, HIGH);

          digitalWrite(Slave1, LOW);
          SPI.transfer(11);
          while(digitalRead(pin3) == 1);
          SPI.transfer(10);
          digitalWrite(Slave1, HIGH);
          digitalWrite(Slave2, LOW);
          SPI.transfer(31);
          delay(4500);
          digitalWrite(Slave2, HIGH);

          digitalWrite(Slave1, LOW);
          SPI.transfer(21);
          while(digitalRead(pin1) == 1);
          SPI.transfer(20);
          digitalWrite(Slave1, HIGH);
        }
        else if(autoMode[modeCount] == 'G') {
          digitalWrite(Slave1, LOW);
          SPI.transfer(11);
          while(digitalRead(pin1) == 1);
          SPI.transfer(10);
          digitalWrite(Slave1, HIGH);
          digitalWrite(Slave2, LOW);
          SPI.transfer(12);
          delay(4500);
          digitalWrite(Slave2, HIGH);

          digitalWrite(Slave1, LOW);
          SPI.transfer(11);
          while(digitalRead(pin2) == 1);
          SPI.transfer(10);
          digitalWrite(Slave1, HIGH);
          digitalWrite(Slave2, LOW);
          SPI.transfer(23);
          delay(4500);
          digitalWrite(Slave2, HIGH);

          digitalWrite(Slave1, LOW);
          SPI.transfer(11);
          while(digitalRead(pin3) == 1);
          SPI.transfer(10);
          digitalWrite(Slave1, HIGH);
          digitalWrite(Slave2, LOW);
          SPI.transfer(35);
          delay(4500);
          digitalWrite(Slave2, HIGH);

          digitalWrite(Slave1, LOW);
          SPI.transfer(21);
          while(digitalRead(pin1) == 1);
          SPI.transfer(20);
          digitalWrite(Slave1, HIGH);
        }
        else if(autoMode[modeCount] == 'R') {
          digitalWrite(Slave1, LOW);
          SPI.transfer(11);
          while(digitalRead(pin1) == 1);
          SPI.transfer(10);
          digitalWrite(Slave1, HIGH);
          digitalWrite(Slave2, LOW);
          SPI.transfer(17);
          delay(4500);
          digitalWrite(Slave2, HIGH);

          digitalWrite(Slave1, LOW);
          SPI.transfer(11);
          while(digitalRead(pin2) == 1);
          SPI.transfer(10);
          digitalWrite(Slave1, HIGH);
          digitalWrite(Slave2, LOW);
          SPI.transfer(21);
          delay(4500);
          digitalWrite(Slave2, HIGH);

          digitalWrite(Slave1, LOW);
          SPI.transfer(11);
          while(digitalRead(pin3) == 1);
          SPI.transfer(10);
          digitalWrite(Slave1, HIGH);
          digitalWrite(Slave2, LOW);
          SPI.transfer(35);
          delay(4500);
          digitalWrite(Slave2, HIGH);

          digitalWrite(Slave1, LOW);
          SPI.transfer(21);
          while(digitalRead(pin1) == 1);
          SPI.transfer(20);
          digitalWrite(Slave1, HIGH);
        }
        digitalWrite(Slave1, HIGH);
        break;
      }
    }
  }
  return;
}

void modeManual() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Manual mode on");
  delay(1000);
  return;
}

void modeMove() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Move mode on");
  delay(1000);
  return;
}

void Start() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Starting machine...");
  //뭐 채울거 있음 채우기
  lcd.clear();
  lcd.print("Done!");
  delay(500);
  return;
}

void setup() {

  //begin code
  SPI.begin();
  Serial.begin(9600);
  while(!Serial);
  Serial.println("SPI, Serial setup completely");

  //pinmode set
  pinMode(Slave1, OUTPUT);
  pinMode(Slave2, OUTPUT);
  pinMode(leftButton, INPUT_PULLUP);
  pinMode(rightButton, INPUT_PULLUP);
  pinMode(selectButton, INPUT_PULLUP);
  pinMode(DEBUG_LED, OUTPUT);
  pinMode(pin1, INPUT);
  pinMode(pin2, INPUT);
  pinMode(pin3, INPUT);
  Serial.println("pinMode set completely");

  
  //SPI set
  digitalWrite(Slave1, HIGH);
  digitalWrite(Slave2, HIGH);
  SPI.setClockDivider(SPI_CLOCK_DIV16);
  Serial.println("SPI setup completely");


  //IIC set
  lcd.begin();
  lcd.backlight();
  Serial.println("lcd setup completely");


  //Program Start!
  Start();
  past = 0;
  timer0_millis = 1000;
}

void loop() {
  flag = 0;
  time = millis();
  if(!digitalRead(leftButton)) {
    digitalWrite(DEBUG_LED, HIGH);
    mode--;
    if(mode<1) mode = 3;
    delay(100);
  }
  else if(!digitalRead(rightButton)) {
    digitalWrite(DEBUG_LED, HIGH);
    mode++;
    if(mode>3) mode = 1;
    delay(100);
  }
  else if(!digitalRead(selectButton)) {
    digitalWrite(DEBUG_LED, HIGH);
    switch(mode) {
      case 1:
        past = 0;
        timer0_millis = 1000;
        modeAuto();
        break;
      case 2:
        modeManual();
        break;
      case 3:
        modeMove();
        break;
    }
    mode = 0;
  }
  if(time - past >= 1000) {  
    if(mode == 0) mode++;
    switch(mode) {
      case 1:
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Automatic mode");
        lcd.setCursor(0,1);
        lcd.print("It have 3 mode");
        break;
      case 2:
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Manual mode");
        lcd.setCursor(0,1);
        lcd.print("How you mode");
        break;
      case 3:
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Move mode");
        lcd.setCursor(0,1);
        lcd.print("Move Self!");
        break;
      }
      past = time;
    }
  digitalWrite(DEBUG_LED, LOW);
}
