

//Flex Sensor Pin (flexPin)
//the analog pin the Flex Sensor is connected to
int flexPin = A0;  
int value;                 
int flexPin1 = A5;  
int value1;                 
void setup() {
  //  pinMode(2, OUTPUT); //sets the led pins 4 to 13 to output
    Serial.begin(9600);       
}

void loop(){

    value = analogRead(flexPin);         //Read and save analog value from potentiometer
    
    value = map(value, 370, 695, 0, 255);//Map value 0-1023 to 0-255 (PWM)
    Serial.print(value);
    Serial.print("\t");
    value1 = analogRead(flexPin1);         //Read and save analog value from potentiometer
    
   value1 = map(value1, 340, 700, 0, 255);//Map value 0-1023 to 0-255 (PWM)
    Serial.println(value1);
//  analogWrite(ledPin, value);          //Send PWM value to led 
  //  digitalWrite(2, LOW); 
 delay(1000); 
  }
//-113 to 80   30;50;



