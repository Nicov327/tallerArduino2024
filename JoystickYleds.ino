//  Enciendo leds (de a uno a la vez) con un joystick
// Tales leds se pueden apagar al llevar la palanca en el eje Y hacia 0

#define rojo 12
#define amarillo 11
#define verde 10
unsigned int x, y;

void setup() {
  pinMode(rojo, OUTPUT);
  pinMode(amarillo, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(A0, INPUT);       //  Entrada del eje X
  pinMode(A1, INPUT);       //  Entrada del eje Y
}

void loop() {
  x = analogRead(A0);
  y = analogRead(A1);

  if(y >= 800){                         //  Este bloque es para prender el amarillo
    digitalWrite(rojo, LOW);
    digitalWrite(amarillo, HIGH);
    digitalWrite(verde, LOW);
  }
  else{
    if(x >=800){                        //  Caso de que no ocurra, pruebo con el rojo
      digitalWrite(rojo, HIGH);
      digitalWrite(amarillo, LOW);
      digitalWrite(verde, LOW);
    }
    else if(x <= 300){                  //  Caso que tampoco se dé, pruebo con el verde
      digitalWrite(rojo, LOW);
      digitalWrite(amarillo, LOW);
      digitalWrite(verde, HIGH);
    }
  }
  if(y <= 300){                         //  Este bloque es para apagar simplemente
    digitalWrite(rojo, LOW);
    digitalWrite(amarillo, LOW);
    digitalWrite(verde, LOW);
  }
}
