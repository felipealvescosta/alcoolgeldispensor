//Projeto: Alcool Gel Dispensor
//Autor: Felipe Alves
//Github: htts://github.com/felipealvescosta

#include <Servo.h>
#define SERVO 6

Servo servo;
int pos;
int pinoSensor = 3;
int movimento; 

void setup() {
  pinMode(pinoSensor, INPUT);
  Serial.begin(9600);
  servo.attach(SERVO);
  servo.write(0);
  Serial.print("iniciando");
}

void loop() {
  movimento = digitalRead(pinoSensor);
  Serial.println(movimento);  
  delay(300);
  if(movimento == 1){
    acionaMotor();
    Serial.print("dispensando");
    delay(3100);
  }
}

void acionaMotor(){
  for(pos = 0; pos < 90; pos++){
    servo.write(pos);
  }
  delay(500);
  for(pos = 90; pos >= 0; pos--){
    servo.write(pos);
  }
}
