/*sistemas digitales "mini air hockey" 
se incluye la libreria led control la cual fue descargada a traves del programa de arduino IDE*/
#include "LedControl.h"
int i=6,j=1,aux=0,aux1=0; //variables globales que son utilizadas para el codigo
/*
 la funcion led control es para definir la configuracion de la matriz
 pin 12 es la conexion del DIN o DATA
 pin 11 es la conexion del CLK
 pin 10 es la conexion del CS
 */
LedControl lc=LedControl(12,11,10,1);

unsigned long delaytime=100;

void setup()
{
     
  lc.shutdown(0,false); // como el controlador de la matriz esta en modo de ahorro de energia se incia con lo siguiente
 
  lc.setIntensity(0,8); // se configura el brillo de la matriz 

  lc.clearDisplay(0); // lo que hace esto es limpiar la matriz 
}


void MDD() //MDD hace alucion a movimiento del disco 
{
/* lo que hace el siguiente codigo es que donde inicie el disco tome un comportamiento y rebote en las paredes de la matriz simulando el movimiento del disco*/
  do
  {
    if(aux1==0)
    {
      lc.clearDisplay(0);
      lc.setLed(0,i,j,1); // esta funcion tiene como objetivo el prender un led en la posicion i,j
      delay(700);
      j++;
      if(j==7)
      {
        aux1=1;
      }
      
    }
    else
    {
      lc.clearDisplay(0);
      lc.setLed(0,i,j,1);
      delay(700);
      j--;
      if(j==0)
      {
        aux1=0;
      }
    }
    i++;
    if(i==7)
    {
     aux=1;
    }
    
  }while(aux==0);
  
  do
  {
    if(aux1==0)
    {
      lc.clearDisplay(0);
      lc.setLed(0,i,j,1);
      delay(700);
      j++;
      if(j==7)
      {
        aux1=1;
      }
      
    }
    else
    {
      lc.clearDisplay(0);
      lc.setLed(0,i,j,1);
      delay(700);
      j--;
      if(j==0)
      {
        aux1=0;
      }
    }
    i--;
    if(i==0)
    {
     aux=0;
    } 
  }
  while(aux==1);
  
  
}

void loop()
{ 
  MDD();
  
}
