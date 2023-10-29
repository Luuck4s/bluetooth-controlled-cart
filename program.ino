// C++ code
/**
* Projeto de Engenharia Unificada II 
* Carrinho de controle remoto controlado por bluetooth
*/

int Engine_A_Number = 9; // Controlador de Ligado/Desligado, motor 1
int Engine_B_Number = 10; // Controlador de Ligado/Desligado, motor 2

int DefaultEngineOnVelocity = 150; // "Velocidade" default do carrinho

int Engine_A_Input_1_Number = 2; // Input 1 do motor 1
int Engine_A_Input_2_Number = 3; // Input 2 do motor 1

int Engine_B_Input_1_Number = 6; // Input 1 do motor 2
int Engine_B_Input_2_Number = 5; // Input 2 do motor 2

char Direction;

void setup()
{
  Serial.begin(9600);

  pinMode(Engine_A_Number, OUTPUT); 
  pinMode(Engine_B_Number, OUTPUT); 

  pinMode(Engine_A_Input_1_Number, OUTPUT);
  pinMode(Engine_A_Input_2_Number, OUTPUT);
  
  pinMode(Engine_B_Input_1_Number, OUTPUT);
  pinMode(Engine_B_Input_2_Number, OUTPUT);
}

void loop()
{
  if(Serial.available()){
    Direction = Serial.read();
    Serial.println(Direction);
  }
  
  if(Direction == 'F')
  {
     startEngine_A_ToFront();
  	 startEngine_B_ToFront();
     return;
  }
  if(Direction == 'B')
  {
    startEngine_A_ToBack();
    startEngine_B_ToBack();
    return;
  }
  if(Direction == 'L')
  {
    startEngine_A_ToBack();
    startEngine_B_ToFront();
    return;
  }
  if(Direction == 'R')
  {
    startEngine_A_ToFront();
    startEngine_B_ToBack();
    return;
  }
  
  stopEngine_A();
  stopEngine_B();
}

#pragma region "Engine A"

void stopEngine_A(){
  analogWrite(Engine_A_Number, 0);
  delay(200);
}

void startEngine_A_ToFront(){
  analogWrite(Engine_A_Number, DefaultEngineOnVelocity);
  digitalWrite(Engine_A_Input_1_Number, HIGH);
  digitalWrite(Engine_A_Input_2_Number, LOW);
}

void startEngine_A_ToBack(){
  analogWrite(Engine_A_Number, DefaultEngineOnVelocity);
  digitalWrite(Engine_A_Input_1_Number, LOW);
  digitalWrite(Engine_A_Input_2_Number, HIGH);
}

#pragma endregion

#pragma region "Engine B"

void stopEngine_B(){
  analogWrite(Engine_B_Number, 0);
  delay(200);
}

void startEngine_B_ToFront(){
  analogWrite(Engine_B_Number, DefaultEngineOnVelocity);
  digitalWrite(Engine_B_Input_1_Number, HIGH);
  digitalWrite(Engine_B_Input_2_Number, LOW);
}


void startEngine_B_ToBack(){
  analogWrite(Engine_B_Number, DefaultEngineOnVelocity);
  digitalWrite(Engine_B_Input_1_Number, LOW);
  digitalWrite(Engine_B_Input_2_Number, HIGH);
}

#pragma endregion
