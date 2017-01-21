 int motor1Pin1 = 3; // pin 2 on L293D IC
int motor1Pin2 = 7; // pin 7 on L293D IC
//int enable1Pin = 6; // pin 1 on L293D IC
int motor2Pin1 = 8; // pin 10 on L293D IC
int motor2Pin2 = 9; // pin 15 on L293D IC
//int enable2Pin = 11; // pin 9 on L293D IC
char a;
const int pwm1 = 4;         //pin 4 has PWM funtion
const int pwm2 = 5;         //pin 4 has PWM funtion
int motor3pin1 = 22;  //driver 1 pin no.2
int motor3pin2 = 24;  //driver 1 pin no.6
int motor4pin1 = 26;   //driver 8 pin no.2
int motor4pin2 = 28;   //driver 8 pin no.6
 

#include <Servo.h>
// Include the servo library to add servo-control functions
Servo servo1;

void setup() 
{
    // sets the pins as outputs:
    pinMode(motor1Pin1, OUTPUT);
    pinMode(motor1Pin2, OUTPUT);
   // pinMode(enable1Pin, OUTPUT);
    pinMode(motor2Pin1, OUTPUT);
    pinMode(motor2Pin2, OUTPUT);
//    pinMode(enable2Pin, OUTPUT);
    pinMode(motor3pin1, OUTPUT);
    pinMode(motor3pin2, OUTPUT);
    pinMode(motor4pin1, OUTPUT);
    pinMode(motor4pin2, OUTPUT);
    // sets enable1Pin and enable2Pin high so that motor can turn on:
   // digitalWrite(enable1Pin, HIGH);
    //digitalWrite(enable2Pin, HIGH);
  //  pinMode(btvcc,HIGH);
    // initialize serial communication at 9600 bits per second:   

    servo1.attach(10);
    
    Serial.begin(38400);
}

void loop() 
{
    analogWrite(pwm1,125);
    analogWrite(pwm2,125);
    int servoposition;    
 //if some date is sent, reads it and saves in state
    if(Serial.available() > 0)
    {     
      a = Serial.read();   
      //flag=0;
    }
   /* if (a=='w')
    {
    }*/
      switch(a)
      {
          case 'A' :
          analogWrite(motor1Pin1, 128);
          digitalWrite(motor1Pin2, LOW); 
          digitalWrite(motor2Pin1, LOW);
          analogWrite(motor2Pin2, 128);
          //Serial.println("PWM 32");
          break;
          
        case 'B' :
          analogWrite(motor1Pin1, 255);
          digitalWrite(motor1Pin2, LOW); 
          digitalWrite(motor2Pin1, LOW);
          analogWrite(motor2Pin2, 255);
          break;
        
       
        case 'W' :
          digitalWrite(motor1Pin1, LOW); 
          analogWrite(motor1Pin2, 180);
          analogWrite(motor2Pin1, 180);
          digitalWrite(motor2Pin2, LOW);
          break;
          
        case 'X' :
          digitalWrite(motor1Pin1, LOW); 
          analogWrite(motor1Pin2, 250);
          analogWrite(motor2Pin1, 250);
          digitalWrite(motor2Pin2, LOW);
          
        case 'P' :                             //LEFT TURN
          analogWrite(motor1Pin1, 128); 
          digitalWrite(motor1Pin2, LOW); 
          digitalWrite(motor2Pin1, LOW);
          digitalWrite(motor2Pin2, LOW);
          break;
          
        case 'Q' :
          analogWrite(motor1Pin1, 255); 
          digitalWrite(motor1Pin2, LOW); 
          digitalWrite(motor2Pin1, LOW);
          digitalWrite(motor2Pin2, LOW);
          break;
        
        case 'R' :                          //RIGHT TURN
          digitalWrite(motor1Pin1, LOW); 
          digitalWrite(motor1Pin2, LOW); 
          digitalWrite(motor2Pin1, LOW);
          analogWrite(motor2Pin2, 128);
          break;
          
        case 'S' :
          digitalWrite(motor1Pin1, LOW); 
          digitalWrite(motor1Pin2, LOW); 
          digitalWrite(motor2Pin1, LOW);
          analogWrite(motor2Pin2, 255);
          break;
        
        case 's' :
          digitalWrite(motor1Pin1, LOW); 
          digitalWrite(motor1Pin2, LOW); 
          digitalWrite(motor2Pin1, LOW);
          digitalWrite(motor2Pin2, LOW);
          //Serial.println ("stop");
          break;

          case 'E' :
          digitalWrite(motor3pin1,LOW);
          digitalWrite(motor3pin2,LOW);
                    delay(250);
          digitalWrite(motor3pin1,LOW);
          digitalWrite(motor3pin2,LOW);
          break;
      
           case 'F' :
          digitalWrite(motor3pin1,HIGH);
          digitalWrite(motor3pin2,LOW);
                    delay(250);
          digitalWrite(motor3pin1,LOW);
          digitalWrite(motor3pin2,LOW);
          break;

           case 'G' :
          digitalWrite(motor3pin1,LOW);
          digitalWrite(motor3pin2,HIGH);
                    delay(250);
          digitalWrite(motor3pin1,LOW);
          digitalWrite(motor3pin2,LOW);
          break;

          case 'M' :
          digitalWrite(motor4pin1,LOW);
          digitalWrite(motor4pin2,LOW);
          delay(250);
          digitalWrite(motor4pin1,LOW);
          digitalWrite(motor4pin2,LOW);
          break;
      
           case 'O' :
          digitalWrite(motor4pin1,HIGH);
          digitalWrite(motor4pin2,LOW);
          delay(250);
          digitalWrite(motor4pin1,LOW);
          digitalWrite(motor4pin2,LOW);
          break;

           case 'N' :
          digitalWrite(motor4pin1,LOW);
          digitalWrite(motor4pin2,HIGH);
          delay(250);
          digitalWrite(motor4pin1,LOW);
          digitalWrite(motor4pin2,LOW);
          break;
          
          case 'H' :
          servo1.write(0);  
          break;

              case 'I' :
          servo1.write(90);
          break;

          case 'J' :
          servo1.write(180);
          break;
        default :
          break;
   

      }
  }

