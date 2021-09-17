//ICLUIR LIBRERIA DE SERVOMOTOR
#include<Servo.h>

//DEFINICION DE VALORES DEL SERVO 1
int pMin1 = 300;
int pMax1 = 1550;
int pServo1 = 16; // cambiar acorde a la placa usada
//recomendable usar los puertos pwm del microcontrolador usado

/*valores predeterminados para un microservo sg90
pulso minimo: 500
pulso maximo: 2400
*/

//Creacion del objeto servo
Servo s1;


void setup() {
s1.attach(pServo1,pMin1,pMax1); //DEFINICION DE SERVO 1 
}


void loop() {
//movimientos del servo
s1.write(0); delay(2000);
s1.write(90); delay(2000);
s1.write(180); delay(2000);

}
