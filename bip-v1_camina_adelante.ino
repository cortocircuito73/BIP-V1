//ICLUIR LIBRERIA DE SERVOMOTOR
#include<Servo.h>

//DEFINICION DE VALORES DEL SERVO 1
int pMin1 = 300;
int pMax1 = 1550;
int pServo1 = 16;

//DEFINICION DE VALORES DEL SERVO 2
int pMin2 = 300;
int pMax2 = 1650;
int pServo2 = 5;

//DEFINICION DE VALORES DEL SERVO 3
int pMin3 = 300;
int pMax3 = 1650;
int pServo3 = 4;

//DEFINICION DE VALORES DEL SERVO 4
int pMin4 = 400;
int pMax4 = 1700;
int pServo4 = 0;

/*valores predeterminados para un microservo sg90
pulso minimo: 500
pulso maximo: 2400
*/
Servo s1,s2,s3,s4;

//VARIABLE DE TIEMPO
int t =2000;

void setup() {
s1.attach(pServo1,pMin1,pMax1); //DEFINICION DE SERVO 1
s2.attach(pServo2,pMin2,pMax2); //DEFINICION DE SERVO 2
s3.attach(pServo3,pMin3,pMax3); //DEFINICION DE SERVO 3
s4.attach(pServo4,pMin4,pMax4); //DEFINICION DE SERVO 4

s1.write(90);
s2.write(90);
s3.write(90);
s4.write(90);
delay(t);
}

void loop() {
int s=10;
int l=80;
boolean gir=false;

//*********************************paso pie izq**********************
//dobla el pie izq
for(int i=90; i<=110; i++){ s4.write(i); delay(s);} delay(l);

//dobla el pie der
for(int i=90; i<=160; i++){ s1.write(i); delay(s);} delay(l);

//alza el pie izq por completo
for(int i=110; i<=140; i++){ s4.write(i); delay(s);} delay(l);

//regresa el pie der a 90 grados
for(int i=160; i>=90; i--){ s1.write(i); delay(s);} delay(l);

//gira las piernas a 70 gradosS
for(int i=90; i>=70; i--){ s3.write(i); delay(s);} delay(l);

//baja el pie izq
for(int i=140; i>=90; i--){ s4.write(i); delay(s);}delay(l);

//************************* paso pie derecho ************************
//dobla el pie der
for(int i=90; i>=70; i--){ s1.write(i); delay(s);} delay(l);

//dobla el pie izq
for(int i=90; i>=20; i--){ s4.write(i); delay(s);} delay(l);

//dobla el pie der por completo
for(int i=70; i>=40; i--){ s1.write(i); delay(s);} delay(l);

//gira el s3
for(int i=70; i<=90; i++){ s3.write(i); delay(s);} delay(l);

// gira los pies
for(int i=90; i<=110; i++){ s2.write(i); delay(s);} delay(l);

// regresa el pie izq a 90 grados
for(int i=20; i<=90; i++){ s4.write(i);  delay(s);} delay(l);

//baja el pie der
for(int i=40; i<=90; i++){ s1.write(i);  delay(s);} delay(l);

}
