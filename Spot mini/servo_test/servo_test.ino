#include<Servo.h>
int servo_1_angle = 90;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  DDRD |= (1<<PD0)|(1<<PD1);
  PORTD |= (1<<0) | (1<<1);
  
  
}

void loop() {
  // put your main code here, to run repeatedly:
  Servo servo_1;
  Servo servo_2;
  Servo servo_3;

  servo_1.attach(10);
  servo_2.attach(12);
  servo_3.attach(14);

  

  //int i=0;
  //float userinput[3];
/*  Servo servo_1;
  Servo servo_2;
  Servo servo_3;

  servo_1.attach(12);
  servo_2.attach(14);
  servo_3.attach(16);*/

  /*int i=0;
  float userinput[3];
   while (Serial.available())
   {
      userinput[i]=Serial.read();
      servo_1.write(userinput[0]);
      servo_2.write(userinput[1]);
      servo_3.write(userinput[2]);
      for (i=0;i<3;i++)
     {
      Serial.print(userinput[i]);
     }
           
    }
   while (Serial.available())
   {
      userinput[i]=Serial.read();
      servo_1.write(userinput[0]);
      servo_2.write(userinput[1]);
      servo_3.write(userinput[2]);
      for (i=0;i<3;i++)
     {
      Serial.print(userinput[i]);
     }*/
      servo_1.write(servo_1_angle);
      //servo_2.write(90);
      //servo_3.write(90);
 
     if (bit_is_clear(PIND,0))
        {
          servo_1_angle += 1;
          while(bit_is_clear(PIND,0)); 
        }
     if (bit_is_clear(PIND,1))
      {
        servo_1_angle -= 1;
        while(bit_is_clear(PIND,1));
      }
           
    }



