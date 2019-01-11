#include <Servo.h>
Servo u;
Servo m;
Servo b;
int t1=0,t2=0,t3=0  ;              //t2 is -ve for going out multi t2 of python by -1
// change link lengths in the code


void setup() {
  // put your setup code here, to run once:
u.attach(10);
m.attach(12);
b.attach(14);

u.write(78+(0));
m.write(90+(10));
b.write(90+(-65));
_delay_ms(1500);

u.write(78+(0));
m.write(90+(-12.5));
b.write(90+(-58));
_delay_ms(1500);

u.write(78+(0));
m.write(90+(-15));
b.write(90+(-50));
_delay_ms(1500);




u.write(78+(0));
m.write(90+(-16.5));
b.write(90+(-35));
_delay_ms(1500);

u.write(78+(0));
m.write(90+(-16));
b.write(90+(-23));
_delay_ms(1500);

u.write(78+(0));
m.write(90+(-8));
b.write(90+(-11));
_delay_ms(1500);

u.write(78+(0));
m.write(90+(-4));
b.write(90+(-5));
_delay_ms(1500);

u.write(78+(0));
m.write(90+(0));
b.write(90+(0));
_delay_ms(1500);

u.write(78+(0));
m.write(90+(3));
b.write(90+(-20));
_delay_ms(1500);

u.write(78+(0));
m.write(90+(6));
b.write(90+(-40));
_delay_ms(1500);

u.write(78+(0));
m.write(90+(8));
b.write(90+(-55));
_delay_ms(1500);

u.write(78+(0));
m.write(90+(10));
b.write(90+(-65));
_delay_ms(1500);
}

void loop() {
  // put your main code here, to run repeatedly:
}
