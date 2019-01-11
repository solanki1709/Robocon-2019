#include<Servo.h>
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  }

bool isReceiving=false;
String userInput;
int a,b,c;

void loop() {
  // put your main code here, to run repeatedly:
  Servo servo_1;
  Servo servo_2;
  Servo servo_3;

  servo_1.attach(10);
  servo_2.attach(12);
  servo_3.attach(14);

 
 // int i=0;

   while (Serial.available())
   {
       isReceiving=true;
       char c = Serial.read();
       userInput+=c;
   }

if(isReceiving)
  {
    //Serial.print("Received:");
   // Serial.println(input);
    int theta = userInput.toInt();
   int  servo_no = theta%10;
    theta = theta/10;
    switch(servo_no)
    {
      case 1:
      servo_1.write(78+theta-180);
      a = 78 + theta - 180;
      break; 
      case 2:
      servo_2.write(90+theta);
      b = 90 + theta;
      break; 
      case 3:
      servo_3.write(90+theta);
      c = 90 + theta;
      break; 
    }
    //servo_1.write(theta);
    userInput="";
    isReceiving=false;
  }  
     /* servo_1.write(userinput[0]);
      servo_2.write(userinput[1]);
      servo_3.write(userinput[2]);
      for (i=0;i<3;i++)
     {
      Serial.println(userinput[i]);
     }*/
     delay(3);
     servo_1.write(a);
     servo_2.write(b);
     servo_3.write(c);
}
