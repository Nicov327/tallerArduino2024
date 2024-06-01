/*
  El circuito:
  - LED desde el pin (pin 4 en este ejemplo) hasta tierra a través de una resistencia de 220 omh
  - Botón desde pin 2 a +5V
  - Resistencia de 10 kilohmios desde pin 2 a tierra

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Debounce
*/
const int pinDeBoton = 2;  // El número del pin que recibirá la señal de que el botón ha sido presionado
const int ledVerde = 4;    // El pin al que está conectado el led
const int ledAmarillo = 5;

int estadoLed = HIGH;        // El estado actual de salida para el led
int estadoDelBoton;            // La lectura actual del pin de entrada
int ultimoEstadoDelBoton = LOW;  // La lectura anterior del pin de entrada

unsigned long ultimoMomentoDeRebote = 0;  // El último momento que el pin de salida fue activado
unsigned long delayRebote = 50;    // El tiempo de rebote. Se puede aumentar manualmente si el mismo es muy bajo

void setup() {
  pinMode(pinDeBoton, INPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarillo, OUTPUT);

  // Damos un valor inicial al led
  digitalWrite(ledVerde, estadoLed);
}

void loop() {
  leoBoton();
  digitalWrite(ledVerde, estadoLed);
  digitalWrite(ledAmarillo, !estadoLed);
}

void leoBoton(){
  int lectura = digitalRead(pinDeBoton);

  if (lectura != ultimoEstadoDelBoton) {
    ultimoMomentoDeRebote = millis();
  }

  if ((millis() - ultimoMomentoDeRebote) > delayRebote) {
    if (lectura != estadoDelBoton) {
      estadoDelBoton = lectura;

      if (estadoDelBoton == HIGH) {
        estadoLed = !estadoLed;
      }
    }
  }

  ultimoEstadoDelBoton = lectura;
}
