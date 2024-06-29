#include <LiquidCrystal_I2C.h>
#include  <Wire.h>

LiquidCrystal_I2C lcd(0x27,  16, 2);

const uint8_t pinDeBoton = 2;  // El número del pin que recibirá la señal de que el botón ha sido presionado
const uint8_t ledPin = 4;    // El pin al que está conectado el led
int estadoLed = HIGH;        // El estado actual de salida para el led
int estadoDelBoton;            // La lectura actual del pin de entrada
int ultimoEstadoDelBoton = LOW;  // La lectura anterior del pin de entrada
unsigned long ultimoMomentoDeRebote = 0;  // El último momento que el pin de salida fue activado
const uint8_t delayRebote = 50;    // El tiempo de rebote. Se puede aumentar manualmente si el mismo es muy bajo

bool playerUp = true;
uint8_t contador = 0;

byte player[8] = {
  B00000,
  B10010,
  B11100,
  B00111,
  B00111,
  B11100,
  B10010,
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

byte sonrisa[8] = {
  B00000,
  B01010,
  B01010,
  B01010,
  B00000,
  B10001,
  B11011,
  B01110
};

uint8_t aliens[6] = {80, 80, 80, 80, 80, 80};
uint8_t proxAlien;

void generarAlien(){
  if(aliens[0] == 0 || aliens[0] == 16 || aliens[5] == 80){
    for(int i=0; i < 5; i++){
      aliens[i] = aliens[i+1];
    }
    aliens[5] = (random(0, 2) * 16 + 15);
  }
}

void boton(){
  int lectura = digitalRead(pinDeBoton);
  if (lectura != ultimoEstadoDelBoton) {
    ultimoMomentoDeRebote = millis();
  }

  if ((millis() - ultimoMomentoDeRebote) > delayRebote) {
    if (lectura != estadoDelBoton) {
      estadoDelBoton = lectura;
      if (estadoDelBoton == HIGH) {
        estadoLed = !estadoLed;
        playerUp = !playerUp;
      }
    }
  }
  digitalWrite(ledPin, estadoLed);
  ultimoEstadoDelBoton = lectura;
}

void avanzarPantalla(){
  lcd.scrollDisplayLeft();

  if(playerUp){lcd.setCursor(0,0);}
  else{lcd.setCursor(0,1);}
  lcd.print(char(0));

  for(int i = 0; i < 6; i++){
      lcd.setCursor((aliens[i] - 16*(aliens[i]/15)), (aliens[i]/15));
      lcd.print(char(1));
  }
}

void setup() {
  pinMode(2, INPUT);
  lcd.init();
  lcd.backlight();

  lcd.createChar(0, player);
  lcd.createChar(1, alien);
  lcd.createChar(2, sonrisa);  

  lcd.setCursor(0, 0);            //  Columna, Fila
  lcd.print("Iniciando...");
  delay(1500);
  lcd.clear();
  
  lcd.setCursor(0, 0);
  lcd.print(char(0));
}

void loop() {
  lcd.clear();
  boton();
  if(playerUp == true){lcd.setCursor(0,0);}
  else{lcd.setCursor(0,1);}
  lcd.print(char(0));

  if(contador == 0){generarAlien();}
  contador = (contador%3);
  delay(100);
}
