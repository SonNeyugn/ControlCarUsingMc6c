//Setup output pins
int motor1pin1 = 4;
int motor1pin2 = 5;

int motor2pin1 = 7;
int motor2pin2 = 6;

float motorSpeed1;
float motorSpeed2;

int speed1;
int speed2;

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

  ch3 = pulseIn(12, HIGH, 25000);
  //Serial.println(ch1);
  posx =  map(ch1,2020,1034,-255,255);
  posy =  map(ch3, 1870,870,-255,255);

  //Check for posx and posy values
  /*
  Serial.println("Posx: ");
  Serial.println(posx);
  Serial.println("Posy: ");
  Serial.println(posy);
  */
  

  if(posx >= -7 && posx <= 7 && posy > -10 && posy < 10)
  {
    
    digitalWrite(motor1pin1,LOW);
    digitalWrite(motor1pin2,LOW);
    digitalWrite(motor2pin1,LOW);
    digitalWrite(motor2pin2,LOW);

    
  }
  else if ( posy >=11)
  {
    //Serial.println("F");
    
    motorSpeed1 = map(posy,11,260,0,255);
    motorSpeed2 = map(posy,11,260,0,255);
    
    digitalWrite(motor1pin1,LOW);
    digitalWrite(motor1pin2,HIGH);
    digitalWrite(motor2pin1,LOW);
    digitalWrite(motor2pin2,HIGH);

    if (posx > 7 ){
      motorSpeed2 = motorSpeed2 - ((posx)/(255.0)*motorSpeed2);
      Serial.println("Speed1: ");
      Serial.println(motorSpeed1);
      Serial.println("Speed2: ");
      Serial.println(motorSpeed2);
     
    }
    else if (posx < -7){
      motorSpeed1 = motorSpeed1-(-(posx)/(255.0)*motorSpeed1);
      Serial.println("Speed1: ");
      Serial.println(motorSpeed1);
      Serial.println("Speed2: ");
      Serial.println(motorSpeed2);
    }
    analogWrite(En1,motorSpeed1);
    analogWrite(En2,motorSpeed2);     
  }
  else if(posy <= -10)
  {
    //Serial.println("B");
    motorSpeed1 = map(posy,-10,-255,0,255);
    motorSpeed2 = map(posy,-10,-255,0,255);
    digitalWrite(motor1pin1,HIGH);
    digitalWrite(motor1pin2,LOW);
    digitalWrite(motor2pin1,HIGH);
    digitalWrite(motor2pin2,LOW);
           
    

     if (posx > 7 ){
      motorSpeed2 = motorSpeed2 - ((posx)/(255.0)*motorSpeed2);
      Serial.println("Speed1: ");
      Serial.println(motorSpeed1);
      Serial.println("Speed2: ");
      Serial.println(motorSpeed2);
     
    }
    else if (posx < -7){
      motorSpeed1 = motorSpeed1-(-(posx)/(255.0)*motorSpeed1);
      Serial.println("Speed1: ");
      Serial.println(motorSpeed1);
      Serial.println("Speed2: ");
      Serial.println(motorSpeed2);
    }
    analogWrite(En1,motorSpeed1);
    analogWrite(En2,motorSpeed2);     
  }
  else if(posy > -10 && posy < 10){
     if (posx > 7 ){
      digitalWrite(motor1pin1,LOW);
      digitalWrite(motor1pin2,HIGH);
      digitalWrite(motor2pin1,HIGH);
      digitalWrite(motor2pin2,LOW);
      motorSpeed1 = map(posx, 7,265, 0, 255);
      motorSpeed2 = map(posx, 7,265, 0, 255);
      
    }
    else if (posx < -7){
      digitalWrite(motor1pin1,HIGH);
      digitalWrite(motor1pin2,LOW);
      digitalWrite(motor2pin1,LOW);
      digitalWrite(motor2pin2,HIGH);
      
      
      motorSpeed1 = map(posx, -7,-258, 0, 255);
      motorSpeed2 = map(posx, -7,-258, 0, 255);
    }
    analogWrite(En1,motorSpeed1);
    analogWrite(En2,motorSpeed2);     
      }
  }
