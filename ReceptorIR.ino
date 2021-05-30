#include "KickSort.h"
#define PIN 11
unsigned int  nb = 0;
int pausas[32], pausas2[32], pausas3[32], pausas4[32],pausas1[32],cuentamsj1, cuentamsj, cuentamsj2, cuentamsj3, cuentamsj4;
unsigned long mensaje, mensaje2, mensaje3, mensaje4, mensaje1;
char datos[3];
int checksum=0;
int temperatura=0,humedad=0,agua=0,tierra=0;
int invchecksum=0,sumaxor=0,bitabit=0;
//#if defined(ARDUINO_ARCH_SAMD)
//#define SerialDebugger SerialUSB
//#else
//#define SerialDebugger Serial
//#endif

const uint16_t samples = 4;
//input array from 1 to 100
int suma,inversa;
void setup() {
 // SerialDebugger.begin(9600);
  //while (!SerialDebugger);
  Serial.begin(9600);
  pinMode(PIN, INPUT);
}

void loop() {

  pausas1[0] = pulseIn(PIN, HIGH);
  if (pausas1[0] > 0) {

    for (cuentamsj1 = 31; cuentamsj1 >= 0; cuentamsj1--) {
      pausas1[cuentamsj1] = pulseIn(PIN, HIGH);

    }
    for (cuentamsj1 = 31; cuentamsj1 >= 0; cuentamsj1--) {

      if (pausas1[cuentamsj1] > 500 && pausas1[cuentamsj1] < 700) {
        bitSet(mensaje1, cuentamsj1);

      } else {
        bitClear(mensaje1, cuentamsj1);
      }

    }
  }
////////////////////////////////////77
  ////////////////////////////////7777
  pausas[0] = pulseIn(PIN, HIGH);
  if (pausas[0] > 0) {

    for (cuentamsj = 31; cuentamsj >= 0; cuentamsj--) {
      pausas[cuentamsj] = pulseIn(PIN, HIGH);

    }
    for (cuentamsj = 31; cuentamsj >= 0; cuentamsj--) {

      if (pausas[cuentamsj] > 500 && pausas[cuentamsj] < 700) {
        bitSet(mensaje, cuentamsj);

      } else {
        bitClear(mensaje, cuentamsj);
      }

    }

    //  Serial.print("Mensaje original: 0x48B76C93 Traducido: 0x"); // HEX(0x48B76C93) // TEXT(H·l") // BIN(01001000 10110111 01101100 10010011)
    // if ((mensaje - 1 - cuentamsj) == mensaje);{


    //
  }

  pausas2[0] = pulseIn(PIN, HIGH);
  if (pausas2[0] > 0) {
    for (cuentamsj2 = 31; cuentamsj2 >= 0; cuentamsj2--) {
      pausas2[cuentamsj2] = pulseIn(PIN, HIGH);

    }
    for (cuentamsj2 = 31; cuentamsj2 >= 0; cuentamsj2--) {
      if (pausas2[cuentamsj2] > 500 && pausas2[cuentamsj2] < 700) {
        bitSet(mensaje2, cuentamsj2);
      } else {
        bitClear(mensaje2, cuentamsj2);
      }

    }

    //  Serial.print("Mensaje original: 0x48B76C93 Traducido: 0x"); // HEX(0x48B76C93) // TEXT(H·l") // BIN(01001000 10110111 01101100 10010011)
    // if ((mensaje - 1 - cuentamsj) == mensaje);{


    //
  }

  pausas3[0] = pulseIn(PIN, HIGH);
  if (pausas3[0] > 0) {
    for (cuentamsj3 = 31; cuentamsj3 >= 0; cuentamsj3--) {
      pausas3[cuentamsj3] = pulseIn(PIN, HIGH);

    }
    for (cuentamsj3 = 31; cuentamsj3 >= 0; cuentamsj3--) {
      if (pausas3[cuentamsj3] > 500 && pausas3[cuentamsj3] < 700) {
        bitSet(mensaje3, cuentamsj3);
      } else {
        bitClear(mensaje3, cuentamsj3);
      }
    }

    //  Serial.print("Mensaje original: 0x48B76C93 Traducido: 0x"); // HEX(0x48B76C93) // TEXT(H·l") // BIN(01001000 10110111 01101100 10010011)
    // if ((mensaje - 1 - cuentamsj) == mensaje);{


    //
  }

  pausas4[0] = pulseIn(PIN, HIGH);
  if (pausas4[0] > 0) {
    for (cuentamsj4 = 31; cuentamsj4 >= 0; cuentamsj4--) {
      pausas4[cuentamsj4] = pulseIn(PIN, HIGH);

    }
    for (cuentamsj4 = 31; cuentamsj4 >= 0; cuentamsj4--) {
      if (pausas4[cuentamsj4] > 500 && pausas4[cuentamsj4] < 700) {
        bitSet(mensaje4, cuentamsj4);
      } else {
        bitClear(mensaje4, cuentamsj4);
      }
    }

    //  Serial.print("Mensaje original: 0x48B76C93 Traducido: 0x"); // HEX(0x48B76C93) // TEXT(H·l") // BIN(01001000 10110111 01101100 10010011)
    // if ((mensaje - 1 - cuentamsj) == mensaje);{


    //
  }


  
  int n=1;
    
  while (n==1){
if (mensaje1>= 32 && mensaje1 <= 64){

  temperatura= mensaje1-32;

}

else if (mensaje>= 32 && mensaje <= 64){

  temperatura= mensaje-32;

}

else if (mensaje2>= 32 && mensaje2 <= 64){

  temperatura=mensaje2-32;
}
else if (mensaje3>= 32 && mensaje3 <= 64){

  temperatura=mensaje3-32;
}
else if (mensaje4>= 32 && mensaje4 <= 64){
  
  temperatura = mensaje4-32;
}
else {
  n=1;
}
  

n=2;
  }
///////////////////////////////////////
//////////////////////////////////////
while (n==2){
if (mensaje1>= 128 && mensaje1 < 256){

  humedad= mensaje1-128;
}

else if (mensaje>= 128 && mensaje < 256){

  humedad= mensaje-128;
}

else if (mensaje2>= 128 && mensaje2 < 256){

  humedad=mensaje2-128;
}
else if (mensaje3>= 128 && mensaje3 < 256){

  humedad=mensaje3-128;
}
else if (mensaje4>= 128 && mensaje4 < 256){
  
  humedad = mensaje4-128;
}
else {
n=2;
}

n=3;
}
//////////////////////////////
//////////////////////////////
while(n==3){
if (mensaje1>= 256 && mensaje1 < 1024){

  agua= mensaje1-256;
}

else if (mensaje>= 256 && mensaje < 1024){

  agua= mensaje-256;
}

else if (mensaje2>= 256 && mensaje2 < 1024){

  agua=mensaje2-256;
}
else if (mensaje3>= 256 && mensaje3 < 1024){

  agua=mensaje3-256;
}
else if (mensaje4>= 256 && mensaje4 < 1024){
  
  agua = mensaje4-256;
}
else {
   n=3;
}

n=4;
}
////////////////////////////77
///////////////////////////

while(n=4){
if (mensaje1>= 1024 && mensaje1 <= 2048){

  tierra= mensaje1-1024;
}

else if (mensaje>= 1024 && mensaje <= 2048){

  tierra= mensaje-1024;
}

else if (mensaje2>= 1024 && mensaje2 <= 2048){

  tierra=mensaje2-1024;
}
else if (mensaje3>= 1024 && mensaje3 <= 2048){

  tierra=mensaje3-1024;
}
else if (mensaje4>= 1024 && mensaje4 <= 2048){
  
  tierra = mensaje4-1024;
}

else {
 n=4;  
}

break;
}

if (mensaje1>= 4096){

  invchecksum= mensaje1;
}

else if (mensaje>= 4096 ){

  invchecksum= mensaje;
}

else if (mensaje2>= 4096 ){

  invchecksum=mensaje2;
}
else if (mensaje3>= 4096 ){

  invchecksum=mensaje3;
}
else if (mensaje4>= 4096 ){
  
  invchecksum = mensaje4;
}

else {
  
}
checksum= temperatura + humedad+ agua+ tierra;

suma = checksum + invchecksum;
//bitabit = checksum | invchecksum;
//sumaxor= checksum  ^ invchecksum;

if (suma == -1){
Serial.print(temperatura);
Serial.print(";");
Serial.print(humedad);
Serial.print(";");
Serial.print(agua);
Serial.print(";");
Serial.print(tierra);
Serial.println();
}
else {
  n=1;
}


/*
n=5;
while(n=5){
if (mensaje1>= 4096 && mensaje1 <= 5000){

  invchecksum= mensaje1-4096;
}

else if (mensaje>= 4096 && mensaje <= 5000){

  invchecksum= mensaje-4096;
}

else if (mensaje2>= 4096 && mensaje2 <= 5000){

  invchecksum=mensaje2-4096;
}
else if (mensaje3>= 4096 && mensaje3 <= 5000){

  invchecksum=mensaje3-4096;
}
else if (mensaje4>= 4096 && mensaje4 <= 5000){
  
  invchecksum = mensaje4-4096;
}

else {
 n=5;  
}

Serial.print(invchecksum);
Serial.println();
break;
}
*/

/*
  uint16_t input[samples] = { mensaje, mensaje2, mensaje3, mensaje4};

  KickSort<uint16_t>::quickSort(input, samples);

  //print the sorted array
  for (uint16_t i = 0; i < samples; i++)
  {

    SerialDebugger.print(input[i]);
    SerialDebugger.print("; ");
  }
  SerialDebugger.println();*/
}
