#include <Servo.h>
Servo u;   
Servo m;
Servo b;
static int t1=200,t2=0,t3=0; 
//t2 is -ve t1or going out multi t2 ot1 python by -1
// change link lengths in the code

void setup() {
  // put your setup code here, to run once:
u.attach(10);
m.attach(12);
b.attach(14);
_delay_ms(1000);

}
void loop()
{

u.write(75+(0));
m.write(90+(-40));
b.write(0+(65));
_delay_ms(t1);

u.write(95+(0));
m.write(90+(-53));
b.write(40+(106));
_delay_ms(t1);

u.write(95+(0));
m.write(90+(-11));
b.write(40+(52));
_delay_ms(t1);

u.write(95+(0));
m.write(90+(-27));
b.write(40+(62));
_delay_ms(t1);
}
