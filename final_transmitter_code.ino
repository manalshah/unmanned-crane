
// Accelerometer calibrate
const int XPin = A0;
const int YPin = A1;
const int ZPin = A2;
unsigned long XSum;
unsigned long YSum;
unsigned long ZSum;
unsigned long X;
unsigned long Y;
unsigned long Z;
int pos_X;
int pos_Y;
int pos_Z;

int       flexth = A5;      // flex pin USED as controling switch for arm/vehicle flex 38 
const int flexPin1 = A3;    //pin A3 to read analog input of flex 3  (Driver 1) base motor 
const int flexPin2 = A4;    //pin A4 to read analog input of flex 22  (Driver 8)
const int flexPin3 = A6;    //pin A7 to read analog input of flex 1  (gripper)

int val=0;                   // used to store flex value from flex sensor         
int fth = 200;             // used to set flex threshold value 
int value=0;                 //save analog value
int value1=0;                 
int value2=0;                 
//int led = 9;

void auto_calibrate();
void new1_pos();

// Raw analog values for -1g and +1g.  Position carefully and look for min and max values.
// These are from an accelerometer running on 3.3V measured agains a 5V analog reference.
// You would expect (3.3V/2-0.33V)*1024/5V = 270 for -1g and (3.3V/2+0.33V)*1024/5V = 405 for +1g.
// As you can see, my accelerometer does not match the nominal values.
//const int XMin = 180;
//const int XMax = 507;
//const int YMin = 199;
//const int YMax = 542;
   
//  pinMode(led, OUTPUT);
  void setup()
{
  Serial.begin(38400);
  auto_calibrate();
  //delay(1000);
  

}

void loop() 
{
  
new1_pos();
pos_X = XSum-X;
pos_Y = YSum-Y;
pos_Z = ZSum-Z;
/*Serial.print(pos_X);
Serial.print("\t");
Serial.print(pos_Y);
Serial.print("\t");
Serial.print(pos_Z);
Serial.print("\n");*/

  val = analogRead(flexth);          //Read and save analog value from potentiometer
  val = map(val, 447,700,0,255); //Map value 0-1023 to 0-255 (PWM)
  Serial.println();                //Print value
  if   (val < fth)
  {
         if((pos_X>=-10 && pos_X<=10) && (pos_Y>=-10 && pos_Y<=10))
              {
               Serial.write ('s');
              }
          else if(pos_X>=11 && pos_X<=75)
             {
              forward();
             }
          else if(pos_X<=-11 && pos_X>=-75 && pos_Y>=-14)
            {
              reverse();
            }
          else if((pos_Y<=-14)&&(pos_Z>=-10))      //for turn right
            {
              right();
            }
          else if((pos_Y>=15)&&(pos_Z>=-5))   // for turn left
            {
              left();
            }
          
   }
 else 
   {
                value = analogRead(flexPin1);         //Read and save analog value from flex-3
                value = map(value, 370, 700, 0, 255); //Map value 0-1023 to 0-255 (PWM)
                Serial.print("flex1 ");                  
                Serial.print(value);                  //Print value  
                Serial.print("\t");
            
                        
            
                
              if (value<120)  //flex-3
              { 
                Serial.write('M');
              } 
                else if (value>=120 && value<200)
              { 
                Serial.write('N');
              }                  
              else if (value>=200)
              { 
                Serial.write('O');
              }  
            
               value1 = analogRead(flexPin2);         //Read and save analog value from potentiometer
                value1 = map(value1, 340, 700, 0, 255);//Map value 0-1023 to 0-255 (PWM)
                Serial.print("flex2 ");                  
                Serial.println(value1);                  //Print value  

            
            if (value1<130)  //flex-22
              { 
                Serial.write('E');
              } 
                else if (value1>=130 && value1<200)
              { 
                Serial.write('F');
              }                  
              else if(value1>=200 )
              { 
                Serial.write('G');
              }  
        
                value2 = analogRead(flexPin3);         //Read and save analog value from potentiometer
                value2 = map(value2, 340, 700, 0, 255);//Map value 0-1023 to 0-255 (PWM)
                Serial.print("flex3 ");                  
                Serial.println(value2);                  //Print value  
             
               if (value2<130)  //flex-22
              { 
                Serial.write('H');
              } 
                else if (value2>=130 && value2<200)
              { 
                Serial.write('I');
              }                  
              else if(value2>=200 )
              { 
                Serial.write('J');
              }  

    
   }

}
void auto_calibrate()
{
  delay(2000);
  XSum=0;
  YSum=0;
  ZSum=0;
  for(int i=0;i<100;i++)
  {
    XSum += analogRead(XPin);
    YSum += analogRead(YPin);
    ZSum += analogRead(ZPin);
  }
  XSum = XSum/100;
  YSum = YSum/100;
  ZSum = ZSum/100;
  /*Serial.print(XSum);
  Serial.print("\t");
  Serial.print(YSum);
  Serial.print("\t");
  Serial.print(ZSum);
  Serial.print("\n");*/
  
  //return(0);
}

void new1_pos()
{
  X=0;
  Y=0;
  Z=0;
  for(int i=0;i<100;i++)
  {
    X += analogRead(XPin);
    Y += analogRead(YPin);
    Z += analogRead(ZPin);
  }
  X = X/100;
  Y = Y/100;
  Z = Z/100;
  /*Serial.print(X);
  Serial.print("\t");
  Serial.print(Y);
  Serial.print("\t");
  Serial.print(Z);
  Serial.print("\n");*/
  //delay(2000);
}



void forward()
{
  if(pos_X>=11 && pos_X<=30)
  {
    Serial.write('A');
  }
  else if(pos_X>=31 && pos_X<=75)
  {
    Serial.write('B');
  }
}

void reverse()
{
   if(pos_X<=-18 && pos_X>=-35)
  {
    Serial.write('W');
  }
  else if(pos_X<=-35 && pos_X>=-75)
  {
    Serial.write('X');
  }
}
 
void left()
{
  if((pos_Z>=-5)&&(pos_Z<=14))
  {
     Serial.write('P');
  }
  else if((pos_Z>=15)&&(pos_Z<=75))
  {
     Serial.write('Q');
  }
}
void right()
{
  if((pos_Z>=5)&&(pos_Z<=9))
  {
     Serial.write('R');
  }
  else if((pos_Z>=10)&&(pos_Z<=75))
  {
     Serial.write('S');
  }
}
