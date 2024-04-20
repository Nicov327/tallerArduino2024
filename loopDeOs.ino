//  Conexión: GND -> GND / VCC -> 5v / SDA -> A4 / SCL -> A5

#include <LiquidCrystal_I2C.h>

#define direccion    0x27  // Puede ser 0x3F, rara vez 0x20
#define columnas 20
#define lineas   4

uint8_t heart[8] = {      // Corazón es ASCII
  0b00000,
  0b01010,
  0b11111,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000,
};

LiquidCrystal_I2C lcd(direccion, columnas, lineas);

void setup() {
  lcd.init();
  lcd.backlight();  // ldc.nobacklight() para tenerla apagada
}


void loop() {
  for (int i = 0; i<4; i++){
    for (int j = 0; j<20; j++){
      lcd.clear();
      lcd.setCursor(j, i);
      lcd.print("o");
      delay(100);
    }
  }
}
