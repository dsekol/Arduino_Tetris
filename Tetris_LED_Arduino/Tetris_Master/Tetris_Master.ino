#include<Wire.h>

int i = 0; 
int j = 0;
int w = 15;

void setup() 
{

  Serial.begin(9600);

  Wire.begin();

}

void loop() 
{


  Wire.beginTransmission(1);
  Wire.write(i);
  Wire.write(j);
  Wire.write(w);
  Wire.endTransmission();

  Wire.beginTransmission(2);
  Wire.write(i);
  Wire.write(j);
  Wire.write(w);
  Wire.endTransmission();

  Wire.beginTransmission(3); 
  Wire.write(i);
  Wire.write(j);
  Wire.write(w);
  Wire.endTransmission();

  if (j < 7) 
  {
    j++; 
  }
  else if(i < w-1)
  {
    i++;
    j = 0;
    delay(200);
  }
  else if(w > 0){
    w--;
    i = 0;
    j = 0;
    delay(200);
  }
}

















