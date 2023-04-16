#include<Wire.h>

int pinArray1[6][8] = {
  {2, 3, 4, 5, 6, 7, 8, 9},
  {10, 11, 12, 13, 22, 23, 24, 25},
  {26, 27, 28, 29, 30, 31, 32, 33},
  {34, 35, 36, 37, 38, 39, 40, 41},
  {42, 43, 44, 45, 46, 47, 48, 49},
  {50, 51, 52, 53, A0, A1, A2, A3}
};

int i = 0; 
int j = 0; 
int w = 0;

void setup() 
{
  Wire.begin(1);
  Wire.onReceive(receiveEvent);

  for (int k=0; k <= 5; k++)
  {
    for (int f=0; f <= 7; f++)
    {
      pinMode(pinArray1[k][f], OUTPUT);
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

  if(i <= 5){
    if(w == 0){
      digitalWrite(pinArray1[0][j], HIGH);
    }
    else if (i < w)
    { 
          digitalWrite(pinArray1[i][j], HIGH);  
          digitalWrite(pinArray1[i+1][j], HIGH);
          digitalWrite(pinArray1[i][j], LOW);
    }
  }
}























