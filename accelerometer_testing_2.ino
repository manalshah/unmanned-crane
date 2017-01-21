const int XPin = A3;                  // x-axis of the accelerometer
const int YPin = A2;                  // y-axis
const int ZPin = A1;                  // z-axis (only on 3-axis models)
unsigned long XSum;
unsigned long YSum;
unsigned long ZSum;
unsigned long X;
unsigned long Y;
unsigned long Z;
int pos_X;
int pos_Y;
int pos_Z;

int val=0;                   // used to store flex value from flex sensor         
//int fth = 200;             // used to set flex threshold value 

void auto_calibrate();
void new1_pos();
  void setup()
{
  Serial.begin(38400);
  auto_calibrate();
  delay(5000);
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

//  val = analogRead(flexth);          //Read and save analog value from potentiometer
  //val = map(val, 447,700,0,255); //Map value 0-1023 to 0-255 (PWM)
  Serial.print(pos_X);                //Print value
  Serial.print("\t");
  Serial.print(pos_Y);                //Print value
  Serial.print("\t");                //Print value
  Serial.println(pos_Z); 
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
void auto_calibrate()
{
  delay(1000);
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
  delay(1000);
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
  delay(1000);
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

