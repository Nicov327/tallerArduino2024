/*
  El circuito:
  - LED desde el pin (pin 7 en este ejemplo) hasta tierra a través de una resistencia de 220 omh
  - Botón desde pin 2 a +5V
  - Resistencia de 10 kilohmios desde pin 2 a tierra

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Debounce
*/
const int pinDeBoton = 2;  // the number of the pushbutton pin
const int ledPin = 13;    // the number of the LED pin

// Variables will change:
int estadoLed = HIGH;        // the current state of the output pin
int estadoDelBoton;            // the current lectura from the input pin
int ultimoEstadoDelBoton = LOW;  // the previous lectura from the input pin

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long ultimoMomentoDeRebote = 0;  // the last time the output pin was toggled
unsigned long delayRebote = 50;    // the debounce time; increase if the output flickers

void setup() {
  pinMode(pinDeBoton, INPUT);
  pinMode(ledPin, OUTPUT);

  // set initial LED state
  digitalWrite(ledPin, estadoLed);
}

void loop() {
  // read the state of the switch into a local variable:
  int lectura = digitalRead(pinDeBoton);

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH), and you've waited long enough
  // since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (lectura != ultimoEstadoDelBoton) {
    // reset the debouncing timer
    ultimoMomentoDeRebote = millis();
  }

  if ((millis() - ultimoMomentoDeRebote) > delayRebote) {
    // whatever the lectura is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (lectura != estadoDelBoton) {
      estadoDelBoton = lectura;

      // only toggle the LED if the new button state is HIGH
      if (estadoDelBoton == HIGH) {
        estadoLed = !estadoLed;
      }
    }
  }

  // set the LED:
  digitalWrite(ledPin, estadoLed);

  // save the lectura. Next time through the loop, it'll be the ultimoEstadoDelBoton:
  ultimoEstadoDelBoton = lectura;
}
