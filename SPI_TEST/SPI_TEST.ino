#include <LiquidCrystal_I2C.h>
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


void modeAuto() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Auto mode on");
  delay(1000);
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
  Serial.println("pinMode set completely");

  
  //SPI set
  digitalWrite(Slave1, HIGH);
  digitalWrite(Slave2, HIGH);
  SPI.setClockDivider(SPI_CLOCK_DIV16);
  Serial.println("SPI setup completely");


  //IIC set
  lcd.init();
  lcd.backlight();
  Serial.println("lcd setup completely");


  //Program Start!
  Start();
}

void loop() {
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
  if(mode != buf) {  
    if(mode == 0) mode++;
    switch(mode) {
      case 1:
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Automatic mode");
        lcd.setCursor(0,1);
        lcd.print("It have 3 mode");
      case 2:
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Manual mode");
        lcd.setCursor(0,1);
        lcd.print("How you mode");
      case 3:
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Move Move");
        lcd.setCursor(0,1);
        lcd.print("Move Self!");
      }
      buf = mode;
    }
  digitalWrite(DEBUG_LED, LOW);
}
