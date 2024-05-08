#include <Servo.h>
#define sg90Pin A0
#define motorPin A1

Servo sg90;
int datoX;
int datoY;

void setup() {
  sg90.attach(4);
  pinMode(sg90Dato, INPUT);
  pinMode(motorDato, INPUT);
}

void loop() {
  datoX = analogRead(sg90Pin);
  datoY = analogRead(motorPin)
  datoX = map(datoX, 0, 1023, 0 179);
  datoY = map(datoY, 0, 1023, 0, 179);
  sg90.write(dato);
}
