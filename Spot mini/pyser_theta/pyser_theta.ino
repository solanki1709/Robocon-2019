#include<Servo.h>
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  }

void loop() {
  // put your main code here, to run repeatedly:
  Servo servo_1;
  Servo servo_2;
  Servo servo_3;

  servo_1.attach(10);
  servo_2.attach(12);
  servo_3.attach(14);

 
  int i=0;
  int userinput[3];
   while (Serial.available()==3)
   {
      for(i=0;i<3;i++)
      {
        userinput[i]=(Serial.read()-'0'cs);
      }
      servo_1.write(userinput[0]);
      //servo_2.write(userinput[1]);
      //servo_3.write(userinput[2]);
      for (i=0;i<3;i++)
     {
      Serial.println(userinput[i]);
     }
           
    }
  

}
