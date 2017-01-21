/* How to use a flex sensor/resistro - Arduino Tutorial
   Fade an LED with a flex sensor
   More info: http://www.ardumotive.com/how-to-use-a-flex-sensor-en.html
   Dev: Michalis Vasilakis // Date: 9/7/2015 // www.ardumotive.com  */
   

//Constants:
const int pwm1 = 3;         //pin 3 has PWM funtion
const int pwm2 = 5;         //pin 5 has PWM funtion
const int flexPin1 = A0;   //pin A0 to read analog input of flex 3  (Driver 1)
const int flexPin2 = A5;   //pin A1 to read analog input of flex 22  (Driver 8)
const int motor1pin1 = 2;  //driver 1 pin no.2
const int motor1pin2 = 4;  //driver 1 pin no.6
const int motor2pin1 = 7;   //driver 8 pin no.2
const int motor2pin2 = 8;   //driver 8 pin no.6

int value=0;                 //save analog value
int value1=0;                 

void setup(){
  
  
  pinMode(pwm1, OUTPUT);  //Set pin 3 as 'output' driver 1 (pwm pin no. 4)
  pinMode(pwm2, OUTPUT);  //Set pin 5 as 'output' driver 8 (pwm pin no. 4)
  pinMode(motor1pin1 , OUTPUT);  
  pinMode(motor1pin2 , OUTPUT);  
  pinMode(motor2pin1 , OUTPUT);  
  pinMode(motor2pin2 , OUTPUT);  
  Serial.begin(9600);     //Begin serial communication

}

void loop()

{
    digitalWrite(pwm1,HIGH);
    digitalWrite(pwm2,HIGH);
    value = analogRead(flexPin1);         //Read and save analog value from flex-3
    value = map(value, 370, 700, 0, 255); //Map value 0-1023 to 0-255 (PWM)
    Serial.print("flex1 ");                  
    Serial.print(value);                  //Print value  
    Serial.print("\t");

    value1 = analogRead(flexPin2);         //Read and save analog value from potentiometer
    
   value1 = map(value1, 340, 700, 0, 255);//Map value 0-1023 to 0-255 (PWM)
    Serial.print("flex2 ");                  
    Serial.println(value1);                  //Print value  

  
  if (value<120)  //flex-3
  { 
    digitalWrite(motor1pin1,LOW);
    digitalWrite(motor1pin2,LOW);
  } 
    else if (value>=120 && value<200)
  { 
    digitalWrite(motor1pin1,HIGH);
    digitalWrite(motor1pin2,LOW);
  }                  
  else if (value>=200)
  { 
    digitalWrite(motor1pin1,LOW);
    digitalWrite(motor1pin2,HIGH);
  }  

if (value1<130)  //flex-22
  { 
    digitalWrite(motor2pin1,HIGH);
    digitalWrite(motor2pin2,HIGH);
  } 
    else if (value1>=130 && value1<200)
  { 
    digitalWrite(motor2pin1,HIGH);
    digitalWrite(motor2pin2,LOW);
  }                  
  else if(value1>=200 )
  { 
    digitalWrite(motor2pin1,LOW);
    digitalWrite(motor2pin2,HIGH);
  }  

}





