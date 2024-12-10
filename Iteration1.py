#Initial Code for the unit
#include <SoftwareSerial.h>

int flx[5] = {A0, A1, A2, A3, A4}; 
int coV[5];
String show = "";

SoftwareSerial bluetooth(10, 11);

void setup() 
{
  Serial.begin(9600);
  bluetooth.begin(9600);
}

void loop() 
{
  inF2();
  int noooo = cng();
  cases(noooo);
  BTcar(show);
  delay(1000); 
}

void inF2() 
{
    coV[0]= (analogRead(flx[0]) < 300) ? 1 :(analogRead(flx[0]) < 600) ? 2 : 0 ;  
    coV[1]= (analogRead(flx[1]) < 300) ? 1 :(analogRead(flx[1]) < 600) ? 2 : 0 ; 
    coV[2]= (analogRead(flx[2]) < 300) ? 1 :(analogRead(flx[2]) < 600) ? 2 : 0 ; 
    coV[3]= (analogRead(flx[3]) < 300) ? 1 :(analogRead(flx[3]) < 600) ? 2 : 0 ; 
    coV[4]= (analogRead(flx[4]) < 300) ? 1 :(analogRead(flx[4]) < 600) ? 2 : 0 ; 
}

int cng() {
  int noooo = 400000;
  for (int i = 0; i < 5; i++) 
  {
    noooo += coV[i] * pow(10, (4 - i));
  }
  return noooo;
}

void cases(int noooo) 
{
  switch (noooo)
   {
    case 411111:
      show = "Hello";
      break;
    case 400000:
      show = "Fist";
      break;
    case 401100:
      show = "Peace";
      break;
    case 400100:
      show = "Fuck You";
      break;
    default:
      show = "Not Assigned Yet";
      break;
  }
}

void BTcar(String message) 
{
  bluetooth.println(message);
}
