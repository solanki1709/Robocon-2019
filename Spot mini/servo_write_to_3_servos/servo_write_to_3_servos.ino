#include <Servo.h>
Servo u;
Servo m;
Servo b;
long int y;
int t1,t2,t3;
// change link lengths in the code


void setup() {
  // put your setup code here, to run once:
u.write(90+t1);
m.write(90+t2);
b.write(90+t3);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0)
    {
      y=Serial.read();
      Serial.print(y);
      }
  

}
