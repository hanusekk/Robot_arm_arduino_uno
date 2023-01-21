#include <Servo.h>

//Servos
Servo serwo1; 
Servo serwo2;
Servo serwo3;
Servo serwo4;
//LED's
const int LED1 = 12; 
const int LED2 = 13;
//Buttons
const int przycisk1 = 5; 
const int przycisk2 = 3;
//Button value
int przycisk1ilerazy = 0;
int przycisk2ilerazy = 0;
//Potentiometers
const int pot1 = A0; 
const int pot2 = A1; 
const int pot3 = A2;
const int pot4 = A3;
//Potentiometer values
int pot1wart; 
int pot2wart;
int pot3wart;
int pot4wart;
int pot1Kat;
int pot2Kat;
int pot3Kat;
int pot4Kat;
//Save the servo position
int serwo1Poz[] = {1,1,1,1,1,1}; 
int serwo2Poz[] = {1,1,1,1,1,1};
int serwo3Poz[] = {1,1,1,1,1,1};
int serwo4Poz[] = {1,1,1,1,1,1};

void setup() {
  
//Pin setup
serwo1.attach(8); 
serwo2.attach(9);
serwo3.attach(10);
serwo4.attach(11);

pinMode(LED1, OUTPUT);
pinMode(LED2, OUTPUT);

pinMode(przycisk1, INPUT_PULLUP);
pinMode(przycisk2, INPUT_PULLUP);
//interrupt
attachInterrupt(digitalPinToInterrupt(przycisk2), funkcja, FALLING);

Serial.begin(9600);
}

void loop() {
  
pot1wart = analogRead(pot1);//Read value from potentiometer
pot1Kat = map(pot1wart, 0, 1023, 0 , 180); //map the value from potentiometer to angle 
pot2wart = analogRead(pot2);
pot2Kat = map(pot2wart, 0, 1023, 0 , 180);
pot3wart = analogRead(pot3);
pot3Kat = map(pot3wart, 0, 1023, 0 , 180);
pot4wart = analogRead(pot4);
pot4Kat = map(pot4wart, 300, 1000, 0 ,90);
{
  serwo1.write(pot1Kat); //servo motion 
  serwo2.write(pot2Kat);
  serwo3.write(pot3Kat);
  serwo4.write(pot4Kat);
  Serial.println(pot1Kat);
  Serial.println(pot2Kat);
  Serial.println(pot3Kat);
  Serial.println(pot4Kat);
  delay(30);
}
if(digitalRead(przycisk1) == LOW){//checks how many times przycisk1 had been push and saves the servo value to array  
  przycisk1ilerazy++;
  digitalWrite(LED1, HIGH);
  delay(250);
  digitalWrite(LED1, LOW);
  switch(przycisk1ilerazy){
    case 1:
        serwo1Poz[0] = pot1Kat;
        serwo2Poz[0] = pot2Kat;
        serwo3Poz[0] = pot3Kat;
        serwo4Poz[0] = pot4Kat;
        Serial.println("Pozycja 1 zapisana");
        break;
    case 2:
        serwo1Poz[1] = pot1Kat;
        serwo2Poz[1] = pot2Kat;
        serwo3Poz[1] = pot3Kat;
        serwo4Poz[1] = pot4Kat;
        Serial.println("Pozycja 2 zapisana");
        break;
    case 3:
        serwo1Poz[2] = pot1Kat;
        serwo2Poz[2] = pot2Kat;
        serwo3Poz[2] = pot3Kat;
        serwo4Poz[2] = pot4Kat;
        Serial.println("Pozycja 3 zapisana");
        break;
    case 4:
        serwo1Poz[3] = pot1Kat;
        serwo2Poz[3] = pot2Kat;
        serwo3Poz[3] = pot3Kat;
        serwo4Poz[3] = pot4Kat;
        Serial.println("Pozycja 4 zapisana");
        break; 
    case 5:
        serwo1Poz[4] = pot1Kat;
        serwo2Poz[4] = pot2Kat;
        serwo3Poz[4] = pot3Kat;
        serwo4Poz[4] = pot4Kat;
        Serial.println("Pozycja 5 zapisana");
        break;       
    case 6:
        serwo1Poz[5] = pot1Kat;
        serwo2Poz[5] = pot2Kat;
        serwo3Poz[5] = pot3Kat;
        serwo4Poz[5] = pot4Kat;
        Serial.println("Pozycja 6 zapisana");
        break;     
  }
  delay(300);
}
 if(digitalRead(przycisk2) == LOW){
 switch(przycisk2ilerazy){
    case 1: {
      digitalWrite(LED2, HIGH);
  do
  for(int i = 0; i < 6; i++)
    {
      if(przycisk2ilerazy!=1)
      break;
      else{
      serwo1.write(serwo1Poz[i]);
      serwo2.write(serwo2Poz[i]);
      serwo3.write(serwo3Poz[i]);
      serwo4.write(serwo4Poz[i]);
      Serial.println(" Kąty pontecjometrów: ");
      Serial.println(serwo1Poz[i]);
      Serial.println(serwo2Poz[i]);
      Serial.println(serwo3Poz[i]);
      Serial.println(serwo4Poz[i]);
      delay(1050);}
     }
      while(przycisk2ilerazy==1);
     }
    case 2:{
      przycisk2ilerazy=0;
      digitalWrite(LED2, LOW);
      break; 
     }}}
delay(30);
} 
void funkcja()
{
  przycisk2ilerazy++;
  delay(200);
}
