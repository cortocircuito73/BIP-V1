//INCLUIR LIBRERIA DE SERVOMOTOR
#include<Servo.h>

//DEFINICION DE VALORES DEL SERVO 1
int pMin1 = 350;
int pMax1 = 2200;
int pServo1 = 16;

//DEFINICION DE VALORES DEL SERVO 2
int pMin2 = 500;
int pMax2 = 2500;
int pServo2 = 5;

//DEFINICION DE VALORES DEL SERVO 3
int pMin3 = 500;
int pMax3 = 2500;
int pServo3 = 4;

//DEFINICION DE VALORES DEL SERVO 4
int pMin4 = 400;
int pMax4 = 2400;
int pServo4 = 0;

/*valores predeterminados para un microservo sg90
pulso minimo: 500
pulso maximo: 2400
*/

Servo s1,s2,s3,s4;

//VARIABLES
int echo=14;
int trig=12;
int led=15;

long dist,dur;
int condi=0; //contador de repeticiones del bucle principal

void setup() {
  Serial.begin(115200);
  //definiciones de servomotores
  s1.attach(pServo1,pMin1,pMax1); //DEFINICION DE SERVO 1
  s2.attach(pServo2,pMin2,pMax2); //DEFINICION DE SERVO 2
  s3.attach(pServo3,pMin3,pMax3); //DEFINICION DE SERVO 3
  s4.attach(pServo4,pMin4,pMax4); //DEFINICION DE SERVO 4

  pinMode(echo,INPUT);
  pinMode(trig,OUTPUT);
  pinMode(led,OUTPUT);

  s1.write(90);
  s2.write(90);
  s3.write(90);
  s4.write(90);
  delay(500);
  digitalWrite(led,1); delay(200);
  digitalWrite(led,0); delay(200);
  digitalWrite(led,1); delay(200);
}

void loop() {
  digitalWrite(trig,LOW);
  delayMicroseconds(4);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);

  dur=pulseIn(echo,HIGH);
  dist=dur/58.3;
  delay(10);
  
  if (dist<=5){ //distancia de deteccion
  digitalWrite(led,0);
  delay(800);
  if (condi==0){atras(1);} 
  else if (condi==1){atras(1); giro_izquierda(1);}
  else if (condi==2){atras(1); giro_derecha(1);}

  }
  
  else if (dist>5 && dist<=50){ //distancia mayor a la deteccion
  delay(200);
  digitalWrite(led,1);
  adelante(1);
  condi+=1;
  if (condi>2){condi=1;}
  }
}

void adelante(int aux1){
  do{
  //*********************************paso pie izq**********************
//dobla el pie der
  for(int i=90; i<=140; i+=2){ s1.write(i); } 

//gira la pierna a 110 gradosS
  for(int i=90; i<=150; i+=2){ s3.write(i); }
   
//regresa el pie der a 90 grados
  for(int i=140; i>=90; i-=2){ s1.write(i); } 
  
//regresa el s3 a 90 grados
  for(int i=150; i>=90; i-=2){ s3.write(i); }
  
//************************* paso pie derecho ************************

//dobla el pie izq
  for(int i=90; i>=40; i-=2){ s4.write(i); } 

// gira el servo s2
  for(int i=90; i>=30; i-=2){ s2.write(i); } 

// regresa el pie izq a 90 grados
  for(int i=40; i<=90; i+=2){ s4.write(i);  } 

// gira el servo s2
  for(int i=30; i<=90; i+=2){ s2.write(i); } 
 
  aux1+=1;

  }while (aux1<=2);
  
 }
void atras(int aux2){

  do{
  //*********************************paso pie izq**********************
//dobla el pie der
  for(int i=90; i<=140; i+=2){ s1.write(i); } 

//gira la pierna a 70 gradosS
  for(int i=90; i>=50; i-=2){ s3.write(i); }
   
//regresa el pie der a 90 grados
  for(int i=140; i>=90; i-=2){ s1.write(i); } 
  
//regresa el s3 a 90 grados
  for(int i=50; i<=90; i+=2){ s3.write(i); }
  
//************************* paso pie derecho ************************

//dobla el pie izq
  for(int i=90; i>=40; i-=2){ s4.write(i); } 

// gira el servo s2
  for(int i=90; i<=130; i+=2){ s2.write(i); } 

// regresa el pie izq a 90 grados
  for(int i=40; i<=90; i+=2){ s4.write(i);  } 

// gira el servo s2
  for(int i=130; i>=90; i-=2){ s2.write(i); }

   aux2+=1;
  }while (aux2<=3);
   
 }

 //derecha
void giro_derecha(int aux3){
  do{
    for(int i=90; i>=20; i-=2){ s2.write(i);s3.write(i); }
    for(int i=20; i<=90; i+=2){ s2.write(i);s3.write(i); }
  aux3+=1;

  }while (aux3<=7);
 }

//izquierda 
void giro_izquierda(int aux4){
    do{
    for(int i=90; i<=160; i+=2){ s2.write(i);s3.write(i); }
    for(int i=160; i>=90; i-=2){ s2.write(i);s3.write(i); }
  aux4+=1;

  }while (aux4<=7);
 }
