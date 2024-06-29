#include <LiquidCrystal_I2C.h>
#include  <Wire.h>

LiquidCrystal_I2C lcd(0x27,  16, 2);

byte player[8] = {
  B00000,
  B10000,
  B11100,
  B11111,
  B11111,
  B11100,
  B10000,
  B00000
};

byte alien[8] = {
  B11011,
  B11011,
  B01110,
  B00100,
  B00100,
  B01110,
  B11011,
  B11011
};

uint8_t aliens[6];
uint8_t proxAlien;

void generarAlien(){
  if(aliens[5] == null){
    aliens[5] = random(0, 2)
  }
}

void setup() {
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);            //  Fila, Columna
  lcd.print("Iniciando...");
  delay(1500);
  lcd.clear();

  lcd.createChar(0, player);
  lcd.createChar(1, alien);
}

void loop() {
  
}
