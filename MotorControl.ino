int motor1pin1 = 4;
int motor1pin2 = 5;

int motor2pin1 = 7;
int motor2pin2 = 6;

int motorSpeed1;
int motorSpeed2;


int En1 = 3;
int En2 = 9;
int ch1 ; // Here's where we'll keep our channel values
int ch2 ;
int ch3 ; 
void setup()
{
    pinMode(En1, OUTPUT);   // where the motor is connected to
    pinMode(En2, OUTPUT);   // where the motor is connected to
    pinMode(motor1pin1, OUTPUT);
    pinMode(motor1pin2, OUTPUT);
    pinMode(motor2pin1, OUTPUT);
    pinMode(motor2pin2, OUTPUT);
    Serial.begin(9600);
}
void loop()
{
  int posx,posy;
  ch1 = pulseIn(10, HIGH, 25000); // Read the pulse width of 
  ch2 = pulseIn(11, HIGH, 25000); // each channel
  ch3 = pulseIn(12, HIGH, 25000);
  
  posx =  map(ch1,2030,1050,-255,255);
  posy =  map(ch3, 1870,870,-255,255);
  
  if(ch1>1000){Serial.println("Left Switch: Engaged");} 
  if(ch1<1000){Serial.println("Left Switch: Disengaged");}
  /* I found that Ch1 was my left switch and that it 
  floats around 900 in the off position and jumps to 
  around 1100 in the on position */

//Serial.print("Right Stick X:"); // Ch3 was x-axis 
//Serial.println(map(ch3, 1000,2000,-500,500)); // center at 0
//Serial.print(posy);
Serial.print(posx);
//Serial.print("Right Stick Y:"); // Ch2 was y-axis
//Serial.println(map(ch1, 1000,2000,-500,500)); // center at 0
//go forward
      if(posx > 0 && posx < 9 && posy > -10 && posy < 10)
      {
        Serial.println("S");
        digitalWrite(motor1pin1,LOW);
        digitalWrite(motor1pin2,LOW);
        digitalWrite(motor2pin1,LOW);
        digitalWrite(motor2pin2,LOW);

        
      }
      else if ( posy >=11)
      {
        Serial.println("F");
        motorSpeed1 = map(posy,10,255,0,255);
        motorSpeed2 = map(posy,10,255,0,255);
        
        digitalWrite(motor1pin1,LOW);
        digitalWrite(motor1pin2,HIGH);
        digitalWrite(motor2pin1,LOW);
        digitalWrite(motor2pin2,HIGH);

        if (posx > 9 ){
          motorSpeed1 = motorSpeed1-posx;
        }
        else if (posx < 0){
          motorSpeed2 = motorSpeed2 - abs(posx);
        }
        analogWrite(En1,motorSpeed1);
        analogWrite(En2,motorSpeed2);     
      }
      else if(posy <= -10)
      {
        Serial.println("B");
        motorSpeed1 = map(posy,-10,-255,0,255);
        motorSpeed2 = map(posy,-10,-255,0,255);
        digitalWrite(motor1pin1,HIGH);
        digitalWrite(motor1pin2,LOW);
        digitalWrite(motor2pin1,HIGH);
        digitalWrite(motor2pin2,LOW);
               
        

        if (posx > 9 ){
          motorSpeed1 = motorSpeed1-posx;
        }
        else if (posx < 0){
          motorSpeed2 = motorSpeed2 - abs(posx);
        }
        analogWrite(En1,motorSpeed1);
        analogWrite(En2,motorSpeed2); 
      }
      /*
      else if(posy < 50 && posy >-50 && posx >= 50) 
      { 
        Serial.println("R");
        analogWrite(En1,200);
        analogWrite(En2,0);
        digitalWrite(motor1pin1,LOW);
        digitalWrite(motor1pin2,HIGH);
        digitalWrite(motor2pin1,LOW);
        digitalWrite(motor2pin2,HIGH);
      }
      else if(posy < 20 && posy >-20 && posx <= -20)
      {
        Serial.println("L");
        analogWrite(En1,0);
        analogWrite(En2,200);
        digitalWrite(motor1pin1,LOW);
        digitalWrite(motor1pin2,HIGH);
        digitalWrite(motor2pin1,LOW);
        digitalWrite(motor2pin2,HIGH);       
      }
      */
}
