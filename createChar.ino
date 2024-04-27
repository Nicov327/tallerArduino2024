#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

uint8_t corazon[8] = {      //  Array de ints de tamaño 8 que describe un corazón
  0b00000,
  0b01010,
  0b10101,
  0b10001,
  0b01010,
  0b00100,
  0b00000
};

uint8_t smile[8] = {       //  Misma idea de arriba pero describe una sonrisa
  0b00000,
  0b11011,
  0b01010,
  0b00000,
  0b10001,
  0b11011,
  0b01110,
  0b00000
};

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.createChar(0, corazon);      //  Creo el caracter del corazón y lo guardo en el espacio 0 de los 8 posibles
  lcd.createChar(1, smile);        //  Misma idea de arriba. Guardo la sonrisa en el espacio 1
}

void loop() {
  for(int i = 0; i < 2; i++){      //  Estos dos for son para iterar sobre todo el lcd y dibujando corazón-sonrisa en cada posición
    for(int j = 0; j < 16; j++){
      lcd.clear();
      lcd.setCursor(j,i);
      lcd.write(byte(0));        
      delay(250);
      lcd.setCursor(j,i);
      lcd.write(byte(1));
      delay(250);
    }
  }
}
