/*
  El circuito:
  - LED desde el pin (pin 7 en este ejemplo) hasta tierra a través de una resistencia de 220 omh
  - Botón desde pin 2 a +5V
  - Resistencia de 10 kilohmios desde pin 2 a tierra

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Debounce
*/
const int pinDeBoton = 2;  // El número del pin que recibirá la señal de que el botón ha sido presionado
const int ledPin = 7;    // El pin al que está conectado el led

int estadoLed = HIGH;        // El estado actual de salida para el led
int estadoDelBoton;            // La lectura actual del pin de entrada
int ultimoEstadoDelBoton = LOW;  // La lectura anterior del pin de entrada


// Las siguientes variables son longs sin signo porque el tiempo, almacenado en milisegundos,
// rápidamente se convertirá en un número más grande del que puede ser almacenado en int
unsigned long ultimoMomentoDeRebote = 0;  // El último momento que el pin de salida fue activado
unsigned long delayRebote = 50;    // El tiempo de rebote. Se puede aumentar manualmente si el mismo es muy bajo

void setup() {
  pinMode(pinDeBoton, INPUT);
  pinMode(ledPin, OUTPUT);

  // Damos un valor inicial al led
  digitalWrite(ledPin, estadoLed);
}

void loop() {
  // Leoo el estado del switch en una variable local read the state of the switch into a local variable:
  int lectura = digitalRead(pinDeBoton);

  // Observo si el botón fue presionado, y si pasó el tiempo suficiente desde la última vez que se lo presionó
  // Si no pasó suficiente tiempo, la señal es ignorada

  // Si el switch cambió, sea por ruido o presionado:
  if (lectura != ultimoEstadoDelBoton) {
    // Actualizo el momento del último rebote
    ultimoMomentoDeRebote = millis();
  }

  if ((millis() - ultimoMomentoDeRebote) > delayRebote) {
    // Si entré a este if, es porque el tiempo desde
    // whatever the lectura is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // Si el estado del botón cambió:
    if (lectura != estadoDelBoton) {
      estadoDelBoton = lectura;

      // Sólo cambio el valor del led si el nuevo estado del botón es HIGH
      if (estadoDelBoton == HIGH) {
        estadoLed = !estadoLed;
      }
    }
  }

  // Actualizo el estado del led
  digitalWrite(ledPin, estadoLed);

  // save the lectura. Next time through the loop, it'll be the ultimoEstadoDelBoton:
  ultimoEstadoDelBoton = lectura;
}
