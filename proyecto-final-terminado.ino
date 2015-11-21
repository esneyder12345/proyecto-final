/*sistemas digitales "mini air hockey" 
se incluye la libreria led control la cual fue descargada a traves del programa de arduino IDE*/
#include "LedControl.h"
#define A  49 
#define B  50 
#define C  51 
#define D  52

int i=3,j=6,aux=0,aux1=0,der,iz,a; //variables globales que son utilizadas para el codigo
const int analogInPin0 = A0; // Pin analogico 1 para la lectura del Fototransistor
const int analogInPin1 = A1;
const int analogInPin2 = A2;
const int analogInPin3 = A3;
const int analogInPin4 = A4;
const int analogInPin5 = A5;

const int analogInPin8 = A8;
const int analogInPin9 = A9;
const int analogInPin10= A10;
const int analogInPin11= A11;
const int analogInPin12= A12;
const int analogInPin13= A13;

int sensorValue0 = 0;        // Inicializamos el valor del sensor
int sensorValue1 = 0;
int sensorValue2 = 0;
int sensorValue3 = 0;
int sensorValue4 = 0;
int sensorValue5 = 0;
int sensorValue[6]={0,0,0,0,0,0};

int sensorValor0 = 0; 
int sensorValor1 = 0; 
int sensorValor2 = 0; 
int sensorValor3 = 0; 
int sensorValor4 = 0; 
int sensorValor5 = 0; 
int sensorVal[6]={0,0,0,0,0,0};
/*
 la funcion led control es para definir la configuracion de la matriz
 pin 12 es la conexion del DIN o DATA
 pin 11 es la conexion del CLK
 pin 10 es la conexion del CS
 */
LedControl lc=LedControl(12,11,10,2);

unsigned long delaytime=200;

int direccion(int b) //hace el ultimo ciclo de la columna 1 o 14
{
  S();
  if(b==1)
  {
    lc.setLed(1,i,j,1); // esta funcion tiene como objetivo el prender un led en la posicion i,j
    delay(delaytime);
    lc.setLed(1,i,j,0);
  }
  else
  {
    lc.setLed(0,i,j,1); // esta funcion tiene como objetivo el prender un led en la posicion i,j
    delay(delaytime);
    lc.setLed(0,i,j,0);
  }
  return 1;
}
void mierdisplay(int contador) //funcion que tiene como objetivo visualizar un numero en el display
{
  switch(contador)
  {
    case 0:
       //NUMERO 0
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
    break;

    case 1:
      //NUMERO 1
      digitalWrite(A, HIGH);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
    break;

    case 2:
      //NUMERO 2
      digitalWrite(A, LOW);
      digitalWrite(B, HIGH);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
    break;
  
    case 3:
      //NUMERO 3
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
    break;
  
    case 4:
      //NUMERO 4
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
    break;
  
    case 5:
      //NUMERO 5
      digitalWrite(A, HIGH);
      digitalWrite(B, LOW);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
    break;
  
  case 6:
      //NUMERO 6
      digitalWrite(A, LOW);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
    break;

  case 7:
      //NUMERO 7
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
  }
}

void S() //tiene como objetivo el leer los valores de cada pin analogico donde estan los sensores infrarojo
{
  sensorValue0 = analogRead(analogInPin0);
  sensorValue1 = analogRead(analogInPin1);
  sensorValue2 = analogRead(analogInPin2);
  sensorValue3 = analogRead(analogInPin3);
  sensorValue4 = analogRead(analogInPin4);
  sensorValue5 = analogRead(analogInPin5);

  sensorValor0 = analogRead(analogInPin8);
  sensorValor1 = analogRead(analogInPin9);
  sensorValor2 = analogRead(analogInPin10);
  sensorValor3 = analogRead(analogInPin11);
  sensorValor4 = analogRead(analogInPin12);
  sensorValor5 = analogRead(analogInPin13);
  
  // Si el valor obtenido es mayor a 900 se activa el LED
//if((sensorValue0 > 900)||(sensorValue1 > 900)||(sensorValue2 > 900)||(sensorValue3 > 900)||(sensorValue4 > 900)||(sensorValue5 > 900))

  if(sensorValue0 > 900)
  {
    lc.clearDisplay(0);
    lc.setLed(0,0,0,1); 
    lc.setLed(0,0,1,1); 
    lc.setLed(0,0,2,1); 
    sensorValue[0]=1;
    for(a=0;a<6;a++)
    {
      sensorValue[a]=0;
    }
    sensorValue[0]=1;
  }

  if(sensorValue1 > 900)
  {
    lc.clearDisplay(0);
    lc.setLed(0,0,1,1);   
    lc.setLed(0,0,2,1);  
    lc.setLed(0,0,3,1); 
    for(a=0;a<6;a++)
    {
      sensorValue[a]=0;
    }
    sensorValue[1]=1;
  }

  if(sensorValue2 > 900)
  {
    lc.clearDisplay(0);
    lc.setLed(0,0,2,1); 
    lc.setLed(0,0,3,1); 
    lc.setLed(0,0,4,1); 
    for(a=0;a<6;a++)
    {
      sensorValue[a]=0;
    }
    sensorValue[2]=1;
  }

  if(sensorValue3 > 900)
  {
    lc.clearDisplay(0);
    lc.setLed(0,0,3,1); 
    lc.setLed(0,0,4,1); 
    lc.setLed(0,0,5,1); 
    for(a=0;a<6;a++)
    {
      sensorValue[a]=0;
    }
    sensorValue[3]=1;
  }
  if(sensorValue4 > 900)
  {
    lc.clearDisplay(0);
    lc.setLed(0,0,4,1); 
    lc.setLed(0,0,5,1); 
    lc.setLed(0,0,6,1);
    for(a=0;a<6;a++)
    {
      sensorValue[a]=0;
    } 
    sensorValue[4]=1;
  }
  if(sensorValue5 > 900)
  {
    lc.clearDisplay(0);
    lc.setLed(0,0,5,1); 
    lc.setLed(0,0,6,1); 
    lc.setLed(0,0,7,1); 
    for(a=0;a<6;a++)
    {
      sensorValue[a]=0;
    }
    sensorValue[5]=1;
  }


  if(sensorValor0 > 900)
  {
    lc.clearDisplay(1);
    lc.setLed(1,7,0,1); 
    lc.setLed(1,7,1,1); 
    lc.setLed(1,7,2,1); 
    sensorVal[0]=1;
    for(a=0;a<6;a++)
    {
      sensorVal[a]=0;
    }
    sensorVal[0]=1;
  }

  if(sensorValor1 > 900)
  {
    lc.clearDisplay(1);
    lc.setLed(1,7,1,1); 
    lc.setLed(1,7,2,1); 
    lc.setLed(1,7,3,1); 
    sensorVal[0]=1;
    for(a=0;a<6;a++)
    {
      sensorVal[a]=0;
    }
    sensorVal[1]=1;
  }
  if(sensorValor2 > 900)
  {
    lc.clearDisplay(1);
    lc.setLed(1,7,2,1); 
    lc.setLed(1,7,3,1); 
    lc.setLed(1,7,4,1); 
    sensorVal[0]=1;
    for(a=0;a<6;a++)
    {
      sensorVal[a]=0;
    }
    sensorVal[2]=1;
  }
  if(sensorValor3 > 900)
  {
    lc.clearDisplay(1);
    lc.setLed(1,7,3,1); 
    lc.setLed(1,7,4,1); 
    lc.setLed(1,7,5,1); 
    sensorVal[0]=1;
    for(a=0;a<6;a++)
    {
      sensorVal[a]=0;
    }
    sensorVal[3]=1;
  }
  if(sensorValor4 > 900)
  {
    lc.clearDisplay(1);
    lc.setLed(1,7,4,1); 
    lc.setLed(1,7,5,1); 
    lc.setLed(1,7,6,1); 
    sensorVal[0]=1;
    for(a=0;a<6;a++)
    {
      sensorVal[a]=0;
    }
    sensorVal[4]=1;
  }
  if(sensorValor5 > 900)
  {
    lc.clearDisplay(1);
    lc.setLed(1,7,5,1); 
    lc.setLed(1,7,6,1); 
    lc.setLed(1,7,7,1); 
    sensorVal[0]=1;
    for(a=0;a<6;a++)
    {
      sensorVal[a]=0;
    }
    sensorVal[5]=1;
  }
}


void movto_filas() //funcion que habilita el movimiento de la barra
{
  int k;
  if(i<8)
  {
    lc.setLed(0,i,j,1); // esta funcion tiene como objetivo el prender un led en la posicion i,j
    delay(delaytime);
    lc.setLed(0,i,j,0);
    S();
  }
  else
  {
    k=i-8;
    lc.setLed(1,k,j,1); // esta funcion tiene como objetivo el prender un led en la posicion i,j
    delay(delaytime);
    lc.setLed(1,k,j,0);
    S();
  }
}


int contador=0, acu=0, acu1;

void MDD() //MDD hace alucion a movimiento del disco 
{
  int op,variable=0,b;
  
/* lo que hace el siguiente codigo es que donde inicie el disco tome un comportamiento y rebote en las paredes de la matriz simulando el movimiento del disco*/
  do
  {
    acu1=acu;
    if(aux1==0)
    {
      movto_filas();
      j++;
      acu=j;
      if(j==7)
      {
        aux1=1;
      }
      
    }
    else
    {
      movto_filas();
      j--;
      acu=j;
      if(j==0)
      {
        aux1=0;
      }
    }

    op=acu1-acu;
    if(op>0)
    {
      der=1;
      iz=0;
    }
    else
    {
      iz=1;
      der=0;
    }
    i++;
    b=1;
    if(i==14)
    {
      for(a=0;a<6;a++)
      {  
        if(sensorVal[a]==1)
        {
          if(der==1)
          {
            if((j==(a+2))||(j==(a+1))||(j==a))
            {
              S();
              lc.setLed(1,i,j,1); // esta funcion tiene como objetivo el prender un led en la posicion i,j
              delay(delaytime);
              lc.setLed(1,i,j,0);
              aux=1;
              variable=1;
              j--; 
              i=13;
            } 
          }
          if(iz==1)
          {
            if((j==(a+2))||(j==(a+1))||(j==(a)))
            {
              S();
              lc.setLed(1,i,j,1); // esta funcion tiene como objetivo el prender un led en la posicion i,j
              delay(delaytime);
              lc.setLed(1,i,j,0);
              aux=1;
              variable=1;
              j++; 
              i=13;
            }  
          }
        }
      }
    }
    
    if(variable==0)
    {
      if(i==15)
      {
        aux=1;
      }
    }
    
  }while(aux==0);


  
  do
  {
    acu1=acu;
    if(aux1==0)
    {
      movto_filas();
      j++;
      acu=j;
      if(j==7)
      {
        aux1=1;
        delaytime+=4;
      }  
    }
    else
    {
      movto_filas();
      j--;
      acu=j;
      
      if(j==0)
      {
        aux1=0;
        delaytime+=10;
      }
    }
    
    op=acu1-acu;
    if(op>0)
    {
      der=1;
      iz=0;
    }
    else
    {
      iz=1;
      der=0;
    }
    
    i--;
    b=0;
    if(i==1)
    {
      for(a=0;a<6;a++)
      {  
        if(sensorValue[a]==1)
        {
          if(der==1)
          {
            if((j>=3)&&(j<7)&&(j==(a+3)))
            {
              variable=direccion(b);
              i=2;
              j++;
              aux=0;
              aux1=0;
            }
            else if(((j==(a+2))||(j==(a+1))||(j==a))&&(j>=0))
            {
              variable=direccion(b);
              j--; 
              i=2;
              aux=0;
              aux1=1;
              
            } 
          }
          
          if(iz==1)
          {
            if((j>1)&&(j<=4)&&(j==(a-1)))
            {
              variable=direccion(b);
              j--; 
              i=2;
              aux=0;
              aux1=1;
              if(j==0)
              {
                aux1=0;
              }
            }
            else if(((j==(a+2))||(j==(a+1))||(j==(a)))&&(j>=0)&&(j<=7))
            {
              variable=direccion(b);
              j++; 
              i=2;
              aux=0;
              aux1=0;
              if(j==7)
              {
                aux1=1;
              }
            }  
          }
        }
      }  
    } 
    if(variable==0)
    {
      if(i==0)
      {
       contador++;
       aux=0;
       mierdisplay(contador);
      }
    }
    
  }
  while(aux==1); 
}


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
  pinMode(A, OUTPUT);  
  pinMode(B, OUTPUT);  
  pinMode(C, OUTPUT);  
  pinMode(D, OUTPUT);
}

void loop()
{ 
  MDD();
}
