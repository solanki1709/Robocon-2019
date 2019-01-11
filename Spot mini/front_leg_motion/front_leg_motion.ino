#include <Servo.h>
Servo u;   
Servo m;
Servo b;
static int t1=200,t2=0,t3=0; 
int spoint_u = 105;
int spoint_m = 85;
int spoint_b = 40;
//t2 is -ve t1or going out multi t2 ot1 python by -1
// change link lengths in the code

void setup() {
  // put your setup code here, to run once:
u.attach(10);
m.attach(11);
b.attach(12);

_delay_ms(1000);

}
void loop()
{
//1
u.write(spoint_u+(0));
m.write(spoint_m+(-40));
b.write(spoint_b+(65));
_delay_ms(t1);

//2
u.write(spoint_u+(0));
m.write(spoint_m+(-53));
b.write(spoint_b+(106));
_delay_ms(t1);

u.write(spoint_u+(0));
m.write(spoint_m+(-50));
b.write(spoint_b+(103));
_delay_ms(t1);

u.write(spoint_u+(0));
m.write(spoint_m+(-43));
b.write(spoint_b+(94));
_delay_ms(t1);

u.write(spoint_u+(0));
m.write(spoint_m+(-24));
b.write(spoint_b+(67));
_delay_ms(t1);
//3
u.write(spoint_u+(0));
m.write(spoint_m+(-11));
b.write(spoint_b+(52));
_delay_ms(t1);
//4
u.write(spoint_u+(0));
m.write(spoint_m+(-15));
b.write(spoint_b+(54));
_delay_ms(t1);
//5
u.write(spoint_u+(0));
m.write(spoint_m+(-18));
b.write(spoint_b+(57));
_delay_ms(t1);
//6
u.write(spoint_u+(0));
m.write(spoint_m+(-23));
b.write(spoint_b+(60));
_delay_ms(t1);
//7
u.write(spoint_u+(0));
m.write(spoint_m+(-27));
b.write(spoint_b+(62));
_delay_ms(t1);

}
