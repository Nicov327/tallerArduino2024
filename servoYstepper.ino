#include <Servo.h>
#include <Stepper.h>

Servo servo;
//  Todos los IN son digitales. 2048 es la cantidad de pasos necesarios para dar una vuelta
Stepper motor(2048, IN1, IN3, IN2, IN4);

int lecturaIntSerial;

int movimientoServo(int num){
  return map(num, -180, 179, 0, 179);
}

int movimientoStepper(int num){
  return map(num, -180, 179, -1023, 1024);
}

void setup() {
  Serial.begin(9600);
  servo.attach(9);
  motor.setSpeed(3);
  Serial.print("Ingrese los grados donde ubicarse (-180, 179)");
}

void loop() 
{ 
  if(Serial.available()){
    lecturaIntSerial = Serial.parseInt();
    servo.write(movimientoServo(lecturaIntSerial));
    motor.step(movimientoStepper(lecturaIntSerial));
  }
}
