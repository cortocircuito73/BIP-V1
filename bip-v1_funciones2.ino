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
boolean g=false; //condicional para caminata
int cont=1; //contador de repeticiones del bucle principal

void setup() {

  //definiciones de servomotores
  s1.attach(pServo1,pMin1,pMax1); //DEFINICION DE SERVO 1
  s2.attach(pServo2,pMin2,pMax2); //DEFINICION DE SERVO 2
  s3.attach(pServo3,pMin3,pMax3); //DEFINICION DE SERVO 3
  s4.attach(pServo4,pMin4,pMax4); //DEFINICION DE SERVO 4


}

void loop() {
    while(cont<=1){
    para(500); 
    adelante(1); 
    para(500);
    atras(1);
    para(500);
    derecha(1);
    para(500); 
    izquierda(1);
    para(500); 
    equilibrio(1);
    para(500);
    equilibrio(2);
    para(500);
    arriba(1);
    para(500);
    cont+=1;
    }

  }

// ********************************************** SUBPROCESOS *******************************************
//para el movimiento
void para(int temp){
  s1.write(90);
  s2.write(90);
  s3.write(90);
  s4.write(90);
  delay(temp);
 }

//adelante  
void adelante(int aux1){
  do{
  //*********************************paso pie izq**********************
//dobla el pie der
  for(int i=90; i<=140; i+=3){ s1.write(i); } 

//gira la pierna a 110 gradosS
  for(int i=90; i<=150; i+=3){ s3.write(i); }
   
//regresa el pie der a 90 grados
  for(int i=140; i>=90; i-=3){ s1.write(i); } 
  
//regresa el s3 a 90 grados
  for(int i=150; i>=90; i-=3){ s3.write(i); }
  
//************************* paso pie derecho ************************

//dobla el pie izq
  for(int i=90; i>=40; i-=3){ s4.write(i); } 

// gira el servo s2
  for(int i=90; i>=30; i-=3){ s2.write(i); } 

// regresa el pie izq a 90 grados
  for(int i=40; i<=90; i+=3){ s4.write(i);  } 

// gira el servo s2
  for(int i=30; i<=90; i+=3){ s2.write(i); } 
 
  aux1+=1;

  }while (aux1<=5);
  
 }

//atras
void atras(int aux2){

  do{
  //*********************************paso pie izq**********************
//dobla el pie der
  for(int i=90; i<=140; i+=3){ s1.write(i); } 

//gira la pierna a 70 gradosS
  for(int i=90; i>=30; i-=3){ s3.write(i); }
   
//regresa el pie der a 90 grados
  for(int i=140; i>=90; i-=3){ s1.write(i); } 
  
//regresa el s3 a 90 grados
  for(int i=30; i<=90; i+=3){ s3.write(i); }
  
//************************* paso pie derecho ************************

//dobla el pie izq
  for(int i=90; i>=40; i-=3){ s4.write(i); } 

// gira el servo s2
  for(int i=90; i<=150; i+=3){ s2.write(i); } 

// regresa el pie izq a 90 grados
  for(int i=40; i<=90; i+=3){ s4.write(i);  } 

// gira el servo s2
  for(int i=150; i>=90; i-=3){ s2.write(i); }

   aux2+=1;
  }while (aux2<=5);
   
 }

//derecha
void derecha(int aux3){
  do{
  // levanta el pie izq
  for(int i=90; i>=40; i-=3){ s4.write(i);} 
  //baja el pie izq y levanta el derecho
  for(int i=40; i<=90; i+=3){ s4.write(i); s1.write(50+i);  } 
  //baja el pie derecho
  for(int i=140; i>=90; i-=3){ s1.write(i);  } 
  
  aux3+=1;

  }while (aux3<=7);
 }

//izquierda 
void izquierda(int aux4){
    do{
  //llevanta el pie der
  for(int i=90; i<=140; i+=3){ s1.write(i);} 
  //baja el pie derecho y levanta el pie izq
  for(int i=140; i>=90; i-=3){ s1.write(i); s4.write(i-50);  } 
  //baja el pie izq
  for(int i=40; i<=90; i+=3){ s4.write(i);  } 
  
  aux4+=1;

  }while (aux4<=7);
 }

void equilibrio(int aux5){

  if (aux5==1){
//*********************************paso pie izq**********************
//dobla el pie izq
for(int i=90; i<=110; i+=2){ s4.write(i); } 

//dobla el pie der
for(int i=90; i<=160; i+=2){ s1.write(i); } 

//alza el pie izq por completo
for(int i=110; i<=140; i+=2){ s4.write(i); } 

//regresa el pie der a 90 grados
for(int i=160; i>=90; i-=2){ s1.write(i); }

for(int i=30; i<=150; i+=2){ s2.write(i); } 
for(int i=150; i>=30; i-=2){ s2.write(i); } 
for(int i=30; i<=150; i+=2){ s2.write(i); } 
for(int i=150; i>=90; i-=2){ s2.write(i); }

delay(2000);
//baja
for(int i=140; i>=90; i-=1){ s4.write(i); } 
  }
 
 else if (aux5==2){
  //************************* paso pie derecho ************************
//dobla el pie der
for(int i=90; i>=70; i-=2){ s1.write(i); } 

//dobla el pie izq
for(int i=90; i>=20; i-=2){ s4.write(i); } 

//dobla el pie der por completo
for(int i=70; i>=40; i-=2){ s1.write(i); } 

// regresa el pie izq a 90 grados
for(int i=20; i<=90; i+=2){ s4.write(i);  }

for(int i=30; i<=150; i+=2){ s3.write(i); } 
for(int i=150; i>=30; i-=2){ s3.write(i); }
for(int i=30; i<=150; i+=2){ s3.write(i); } 
for(int i=150; i>=90; i-=2){ s3.write(i); }
delay(2000);
//baja
for(int i=40; i<=90; i+=1){ s1.write(i);} 
  }
 }

 void arriba(int aux6){
  do{
  for(int i=90; i>=20; i-=1){ s4.write(i); s1.write(180-i);} 
  delay(1000);
  for(int i=20; i<=90; i+=1){ s4.write(i);s1.write(180-i); }
   delay(1000);
   aux6+=1;
  }while(aux6<=3);
  }
