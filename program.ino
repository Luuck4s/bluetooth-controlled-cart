// C++ code
/**
* Projeto de Engenharia Unificada II 
* Carrinho de controle remoto controlado por bluetooth
*/
#include <AFMotor.h>    // Inclui a Biblioteca AFMotor.h - Adafruit-Motor-Shield-library

AF_DCMotor engine_a(1);
AF_DCMotor engine_b(2);

char Direction;

int state_rec;
int vSpeed = 400; // Velocidade Default dos motores

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  if(Serial.available() > 0){
    state_rec = Serial.read();
    Direction = state_rec;
    Serial.println(state_rec);
    Serial.println(state_rec == 1);
  }
  
  if(Direction == 1 || Direction == 51)
  {
    stopEngine_A();
    stopEngine_B();
    startEngine_A_ToFront();
  	startEngine_B_ToFront();
  }
  if(Direction == 2 || Direction == 52)
  {
    stopEngine_A();
    stopEngine_B();
    startEngine_A_ToBack();
    startEngine_B_ToBack();
  }
  if(Direction == 3 || Direction == 53)
  {
    stopEngine_A();
    stopEngine_B();
    startEngine_A_ToBack();
    startEngine_B_ToFront();
  }
  if(Direction == 4 || Direction == 54)
  {
    stopEngine_A();
    stopEngine_B();
    startEngine_A_ToFront();
    startEngine_B_ToBack();
  }

  if(Direction == 'S')
  {
    stopEngine_A();
    stopEngine_B();
  }
}

#pragma region "Engine A"

void stopEngine_A(){
  engine_a.setSpeed(0);
  engine_a.run(RELEASE);
  delay(200);
}

void startEngine_A_ToFront(){
  engine_a.run(FORWARD);
  engine_a.setSpeed(vSpeed);
}

void startEngine_A_ToBack(){
  engine_a.run(BACKWARD);
  engine_a.setSpeed(vSpeed);
}

#pragma endregion

#pragma region "Engine B"

void stopEngine_B(){
  engine_b.setSpeed(0);
  engine_b.run(RELEASE);
  delay(200);
}

void startEngine_B_ToFront(){
  engine_b.run(FORWARD);
  engine_b.setSpeed(vSpeed);
}


void startEngine_B_ToBack(){
  engine_b.run(BACKWARD);
  engine_b.setSpeed(vSpeed);
}

#pragma endregion
