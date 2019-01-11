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
_delay_ms(600);

}
void loop()
{

u.write(78+(0));
m.write(90+(10));
b.write(90+(-65));
_delay_ms(t1);

u.write(78+(0));
m.write(90+(-10));
b.write(90+(-70));
_delay_ms(t1);

u.write(78+(0));
m.write(90+(-30));
b.write(90+(-80));
_delay_ms(t1);

u.write(78+(0));
m.write(90+(-60));
b.write(90+(-30));
_delay_ms(t1);

u.write(78+(0));
m.write(90+(-50));
b.write(90+(-20));
_delay_ms(t1);

u.write(78+(0));
m.write(90+(-40));
b.write(90+(0));
_delay_ms(t1);

u.write(78+(0));
m.write(90+(-30));
b.write(90+(10));
_delay_ms(t1);

  }


