#include "SoftwareSerial.h"

// Incluímos la librería para poder controlar el servo
#include <Servo.h>
 
// Declaramos la variable para controlar el servo
Servo servoMotor;

SoftwareSerial BT(4,2); // RX, TX recorder que se cruzan
// Motor 1
int ENA = 10;
int IN1 = 9;
int IN2 = 8;

// Motor 2
int ENB = 5;
int IN3 = 7;
int IN4 = 6;

void setup() {
 Serial.begin(9600);
 BT.begin(9600);

 // Iniciamos el servo para que empiece a trabajar con el pin 11
  servoMotor.attach(11);
    // Inicializamos al ángulo 0 el servomotor
  servoMotor.write(0);
  
 pinMode (ENA, OUTPUT);
 pinMode (ENB, OUTPUT);
 pinMode (IN1, OUTPUT);
 pinMode (IN2, OUTPUT);
 pinMode (IN3, OUTPUT);
 pinMode (IN4, OUTPUT);  

 
 
  
}

void loop() {




  if (BT.available()){
    char dato=BT.read();

    switch(dato){
      case 'a':
        Adelante();
        break;
      case 'r':
        Atras();
        break;
      case 'd':
        Derecha();
        break;
      case 'i':
        Izquierda();
        break;
      case 'p':
        Parar();
        break;
      case 'o':
        Espada();
        break;
        /*
      case 'h':
        Tranquilo();
        break;
        */
    }    
  }
}

void Adelante (){
 //Dirección motor A
 digitalWrite (IN1, LOW);
 digitalWrite (IN2, HIGH);
 analogWrite (ENA, 255); //Velocidad motor A
 //Dirección motor B
 digitalWrite (IN3, HIGH);
 digitalWrite (IN4, LOW);
 analogWrite (ENB, 255); //Velocidad motor B
}

void Derecha (){
 //Dirección motor A
 digitalWrite (IN1, HIGH);
 digitalWrite (IN2, LOW);
 analogWrite (ENA, 255); //Velocidad motor A
 //Dirección motor B
 digitalWrite (IN3, HIGH);
 digitalWrite (IN4, LOW);
 analogWrite (ENB, 255); //Velocidad motor A
}

void Izquierda (){
 //Dirección motor A
 digitalWrite (IN1, LOW);
 digitalWrite (IN2, HIGH);
 analogWrite (ENA, 255); //Velocidad motor A
 //Dirección motor B
 digitalWrite (IN3, LOW);
 digitalWrite (IN4, HIGH);
 analogWrite (ENB, 255); //Velocidad motor A
}

void Atras (){
 //Dirección motor A
 digitalWrite (IN1, HIGH);
 digitalWrite (IN2, LOW);
 analogWrite (ENA, 255); //Velocidad motor A
 //Dirección motor B
 digitalWrite (IN3, LOW);
 digitalWrite (IN4, HIGH);
 analogWrite (ENB, 255); //Velocidad motor B
}

void Parar (){
 //Dirección motor A
 digitalWrite (IN1, LOW);
 digitalWrite (IN2, LOW);
 analogWrite (ENA, 0); //Velocidad motor A
 //Dirección motor B
 digitalWrite (IN3, LOW);
 digitalWrite (IN4, LOW);
 analogWrite (ENB, 0); //Velocidad motor A
}

void Espada(){


   // Vamos a tener dos bucles uno para mover en sentido positivo y otro en sentido negativo
  // Para el sentido positivo
  for (int i = 0; i <= 180; i++)
  {
    // Desplazamos al ángulo correspondiente
    servoMotor.write(i);
    // Hacemos una pausa de 25ms
    delay(3);
  }
 
  // Para el sentido negativo
  for (int i = 179; i > 0; i--)
  {
    // Desplazamos al ángulo correspondiente
    servoMotor.write(i);
    // Hacemos una pausa de 25ms
    delay(2.5);
  }


}

/*
void Tranquilo(){

  servoMotor.write(0);
}
*/
