/*sistemas digitales "mini air hockey" 
se incluye la libreria led control la cual fue descargada a traves del programa de arduino IDE*/
#include "LedControl.h"
int i=3,j=4,aux=0,aux1=0; //variables globales que son utilizadas para el codigo
const int analogInPin = A1; // Pin analogico 1 para la lectura del Fototransistor
const int analogInPin2 = A2;
const int OutPin = 53;      // Pin para el led indicador

int sensorValue = 0;        // Inicializamos el valor del sensor
int sensorValue2 = 0;
/*
 la funcion led control es para definir la configuracion de la matriz
 pin 12 es la conexion del DIN o DATA
 pin 11 es la conexion del CLK
 pin 10 es la conexion del CS
 */
LedControl lc=LedControl(12,11,10,2);

unsigned long delaytime=1;

void setup()
{
     
  lc.shutdown(0,false); // como el controlador de la matriz esta en modo de ahorro de energia se incia con lo siguiente
  lc.setIntensity(0,8); // se configura el brillo de la matriz 
  lc.clearDisplay(0); // lo que hace esto es limpiar la matriz 

   lc.shutdown(1,false);
   lc.setIntensity(1,8);
   lc.clearDisplay(1);
   // Inicializamos la comunicacion serial a 9600 bps:
  Serial.begin(9600);
  pinMode(OutPin, OUTPUT);
}


/*Codigo prueba para encender las barras laterales
 * 
 * void S()
{
  sensorValue = analogRead(analogInPin);
  sensorValue2 = analogRead(analogInPin2);
  // Si el valor obtenido es mayor a 900 se activa el LED

  if(sensorValue > 900)
  {
    
    lc.setLed(0,0,0,1); 
    lc.setLed(0,0,1,1); 
    lc.setLed(0,0,2,1); 
  }

  if(sensorValue2 > 900)
  {
    
    lc.setLed(0,0,4,1);   
    lc.setLed(0,0,5,1);  
    lc.setLed(0,0,6,1); 
  }

  // Imprimimos el valor en el monitor.
  Serial.print("sensor = " );
  Serial.println(sensorValue);
  Serial.println(sensorValue2);
  delay(100);
  
}*/

void MDD() //MDD hace alucion a movimiento del disco 
{
  int k;
/* lo que hace el siguiente codigo es que donde inicie el disco tome un comportamiento y rebote en las paredes de la matriz simulando el movimiento del disco*/
  do
  {
    if(aux1==0)
    {
      if(i<8)
      {
      lc.clearDisplay(0);
      lc.setLed(0,i,j,1); // esta funcion tiene como objetivo el prender un led en la posicion i,j
      delay(delaytime);
      }
      else
      {
        lc.clearDisplay(0);
        lc.clearDisplay(1);
        k=i-8;
        lc.setLed(1,k,j,1); // esta funcion tiene como objetivo el prender un led en la posicion i,j
        delay(delaytime);
      }
      j++;
      if(j==7)
      {
        aux1=1;
        delaytime+=10;
      }
      
    }
    else
    {
      if(i<8)
      {
      lc.clearDisplay(1);
      lc.clearDisplay(0);
      lc.setLed(0,i,j,1); // esta funcion tiene como objetivo el prender un led en la posicion i,j
      delay(delaytime);
      }
      else
      {
        lc.clearDisplay(0);
        lc.clearDisplay(1);
        k=i-8;
        lc.setLed(1,k,j,1); // esta funcion tiene como objetivo el prender un led en la posicion i,j
        delay(delaytime);
      }
      j--;
      if(j==0)
      {
        aux1=0;
        delaytime+=10;
      }
    }
    i++;
    if(i==15)
    {
     aux=1;
    }
/*Prueba para encender las barras laterales*/
    
    sensorValue = analogRead(analogInPin);
  sensorValue2 = analogRead(analogInPin2);
  // Si el valor obtenido es mayor a 900 se activa el LED
  if(sensorValue > 900)
  {
    //Se encienden los pines 0,1 y 2 de la columna 0
    lc.setLed(0,0,0,1); 
    lc.setLed(0,0,1,1); 
    lc.setLed(0,0,2,1);  
  }

  if(sensorValue2 > 900)
  {
    //Se encienden los pines 4,5 y 6 de la columna 0
    lc.setLed(0,0,4,1);     
    lc.setLed(0,0,5,1);  
    lc.setLed(0,0,6,1); 
  }
    
  }while(aux==0);
  
  do
  {
    if(aux1==0)
    {
      if(i<8)
      {
      lc.clearDisplay(1);
      lc.clearDisplay(0);
      lc.setLed(0,i,j,1); // esta funcion tiene como objetivo el prender un led en la posicion i,j
      delay(delaytime);
      }
      else
      {
        lc.clearDisplay(0);
        lc.clearDisplay(1);
        k=i-8;
        lc.setLed(1,k,j,1); // esta funcion tiene como objetivo el prender un led en la posicion i,j
        delay(delaytime);
      }
      j++;
      if(j==7)
      {
        aux1=1;
        delaytime+=10;
      }
      
    }
    else
    {
      if(i<8)
      {
      lc.clearDisplay(1);
      lc.clearDisplay(0);
      lc.setLed(0,i,j,1); // esta funcion tiene como objetivo el prender un led en la posicion i,j
      delay(delaytime);
      }
      else
      {
        lc.clearDisplay(0);
        lc.clearDisplay(1);
        k=i-8;
        lc.setLed(1,k,j,1); // esta funcion tiene como objetivo el prender un led en la posicion i,j
        delay(delaytime);
      }
      j--;
      if(j==0)
      {
        aux1=0;
        delaytime+=10;
      }
    }
    i--;
    if(i==0)
    {
     aux=0;
    }
    sensorValue = analogRead(analogInPin);
  sensorValue2 = analogRead(analogInPin2);
 
  // Si el valor obtenido es mayor a 900 se activan los led definidos
  if(sensorValue > 900)
  {
    //Se encienden los pines 0,1 y 2 de la columna 0
    lc.setLed(0,0,0,1); 
    lc.setLed(0,0,1,1); 
    lc.setLed(0,0,2,1);  
  }

  if(sensorValue2 > 900)
  {
    //Se encienden los pines 4,5 y 6 de la columna 0
    lc.setLed(0,0,4,1);     
    lc.setLed(0,0,5,1);  
    lc.setLed(0,0,6,1); 
  }
  }
  while(aux==1);
  
  
}
void loop()
{ 
  MDD();
}
