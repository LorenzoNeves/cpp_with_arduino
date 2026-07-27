#define A 4
#define B 5
#define C 8
#define D 7
#define E 6
#define F 3
#define G 2
#define H 9
#define btn 13
#define ON LOW
#define OFF HIGH

int contador = 1;    //counter
int btnclicado = 0;  //clicked button
int btnliberado = 0; //not clicked

void setup(){
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(H, OUTPUT);
  pinMode(btn, INPUT);
}

void um(){ //Numero 1 
  digitalWrite(A, OFF);
  digitalWrite(B, ON);
  digitalWrite(C, ON);
  digitalWrite(D, OFF);
  digitalWrite(E, OFF);
  digitalWrite(F, OFF);
  digitalWrite(G, OFF);
  digitalWrite(H, OFF);
}
void dois(){ //Numero 2
  digitalWrite(A, ON);
  digitalWrite(B, ON);
  digitalWrite(C, OFF);
  digitalWrite(D, ON);
  digitalWrite(E, ON);
  digitalWrite(F, OFF);
  digitalWrite(G, ON);
  digitalWrite(H, OFF);
}

void cinco(){ //Numero 5 
  digitalWrite(A, ON);
  digitalWrite(B, OFF);
  digitalWrite(C, ON);
  digitalWrite(D, ON);
  digitalWrite(E, OFF);
  digitalWrite(F, ON);
  digitalWrite(G, ON);
  digitalWrite(H, OFF);
}
void seis(){ //Numero 6 
  digitalWrite(A, ON);
  digitalWrite(B, OFF);
  digitalWrite(C, ON);
  digitalWrite(D, ON);
  digitalWrite(E, ON);
  digitalWrite(F, ON);
  digitalWrite(G, ON);
  digitalWrite(H, OFF);
}

void zero(){ //Numero 0 
  digitalWrite(A, ON);
  digitalWrite(B, ON);
  digitalWrite(C, ON);
  digitalWrite(D, ON);
  digitalWrite(E, ON);
  digitalWrite(F, ON);
  digitalWrite(G, OFF);
  digitalWrite(H, OFF);
}

void traco(){ //Traço
  digitalWrite(A, OFF);
  digitalWrite(B, OFF);
  digitalWrite(C, OFF);
  digitalWrite(D, OFF);
  digitalWrite(E, OFF);
  digitalWrite(F, OFF);
  digitalWrite(G, ON);
  digitalWrite(H, OFF);
}

unsigned long tempoPressionar = 0;
bool troca = false;

void loop(){
  if (digitalRead(btn) == ON) {
    if (tempoPressionar == 0) {
      tempoPressionar = millis();
    }
    btnclicado = 1;
    btnliberado = 0;
    if (millis() - tempoPressionar >= 1000 && !troca) {
      contador++;
      troca = true;
      btnclicado = 0;
      sequencia();
    }

  } else {
    if (btnclicado == 1 && !troca) {
      contador++;
    }
    btnclicado = 0;
    btnliberado = 1;
    tempoPressionar = 0;
    troca = false;
  }

  sequencia();
}

void sequencia(){
  if(contador == 1)      {dois();}
  else if(contador == 2) {seis();}
  else if(contador == 3) {um();}
  else if(contador == 4) {zero();}
  else if(contador == 5) {dois();}
  else if(contador == 6) {seis();}
  else if(contador == 7) {zero();}
  else if(contador == 8) {dois();}
  else if(contador == 9) {traco();}
  else if(contador == 10){cinco();}
  else if(contador <= 11){contador = 1;}
}
