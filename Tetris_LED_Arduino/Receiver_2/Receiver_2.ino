#include<Wire.h>

int pinArray2[5][8] = {
  {2, 3, 4, 5, 6, 7, 8, 9},
  {10, 11, 12, 13, 22, 23, 24, 25},
  {26, 27, 28, 29, 30, 31, 32, 33},
  {34, 35, 36, 37, 38, 39, 40, 41},
  {42, 43, 44, 45, 46, 47, 48, 49},
};

int i = 0; 
int j = 0; 
int w = 0;

void setup() 
{
  Serial.begin(9600);

  Wire.begin(2);
  Wire.onReceive(receiveEvent);

  for (int k=0; k <= 4; k++)
  {
    for (int f=0; f <= 7; f++)
    {
      pinMode(pinArray2[k][f], OUTPUT);
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:



}

void receiveEvent(int bytes)
{
  i = Wire.read();
  j = Wire.read(); 
  w = Wire.read();


  

  if(i >= 5 && i <= 10){
    
    if (i <= w)
    { 
      if(w == 6){
        digitalWrite(pinArray2[0][j], HIGH);
      }
      digitalWrite(pinArray2[i - 6][j], HIGH);  
      digitalWrite(pinArray2[(i+1) - 6][j], HIGH);
      digitalWrite(pinArray2[i - 6][j], LOW);

    }  
    
  }
}























