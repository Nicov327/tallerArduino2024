#include <Servo.h>
Servo servo;

bool habilitado = true;           // El estado actual de salida para el led
int estadoDelBoton;               // La lectura actual del pin de entrada
int ultimoEstadoDelBoton = LOW;   // La lectura anterior del pin de entrada
int datoJoystick;                 // Variable sobre la que se guarda lo que venga del joystick
int lectura;                      // Esta varable almacena la lectura del botón

unsigned long ultimoMomentoDeRebote = 0;
unsigned long delayRebote = 50;

void botonApretado(){             // Esta función es la que se encarga de los eventos del botón
  lectura = digitalRead(2);

  if (lectura != ultimoEstadoDelBoton) {
    ultimoMomentoDeRebote = millis();
  }

  if ((millis() - ultimoMomentoDeRebote) > delayRebote) {
    if (lectura != estadoDelBoton) {
      estadoDelBoton = lectura;

      if (estadoDelBoton == HIGH) {
        habilitado = !habilitado;     // Si estoy en esta linea, es porque el botón está apretado y no es ruido
      }
    }
  }

  ultimoEstadoDelBoton = lectura;
}

void moverServo(){      // Esta sencilla función lee el joystick, mapea su valor, y lo escribe en el servo
    datoJoystick = map(analogRead(A0), 0, 1023, 0, 179);
    servo.write(datoJoystick);
}

void setup() {
  servo.attach(3);      // Servo conectado al pin 3
  pinMode(2, INPUT);    // Entrada del dato del botón por el pin 2
  lectura = digitalRead(2);    // Doy un valor inicial a lectura
}

void loop() {
  botonApretado();      // Una vez ejecutada esta función, la variable puede o no haber cambiado
  if(habilitado){       // Si ahora tengo habilitado el uso del servo, ejecuto su función
    moverServo();
  }
}
