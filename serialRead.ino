//  Comunicación por puerto serie con el arduino

#define rojo 12
#define amarillo 11
#define verde 10

bool rB = false;
bool aB = false;
bool vB = false;
unsigned short int led;

void setup() {
  pinMode(rojo, OUTPUT);
  pinMode(amarillo, OUTPUT);
  pinMode(verde, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if(Serial.available() != 0){      //  Cargo el dato a led cuando lo tenga disponible
    led = Serial.parseInt();
    Serial.println(led);
  }

  if(led == 1){                     //  Si led == 1, opero en el rojo
    rB = !rB;
    if(rB){
      digitalWrite(rojo, HIGH);
    }
    else{
      digitalWrite(rojo, LOW);
    }
  }
  else if(led == 2){              //  Si led == 2, opero en el amarillo
    aB = !aB;
    if(aB){
      digitalWrite(amarillo, HIGH);
    }
    else{
      digitalWrite(amarillo, LOW);
    }
  }
  else if(led == 3){            //  Si led == 3, opero en el verde
    vB = !vB;
    if(vB){
      digitalWrite(verde, HIGH);
    }
    else{
      digitalWrite(verde, LOW);
    }
  }
}
