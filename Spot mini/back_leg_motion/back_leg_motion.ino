#include <Servo.h>
Servo u;   
Servo m;
Servo b;
static int t1=1000,t2=0,t3=0; 
//t2 is -ve t1or going out multi t2 ot1 python by -1
// change link lengths in the code

void setup() {
  // put your setup code here, to run once:
u.attach(10);
m.attach(12);
b.attach(14);
_delay_ms(1000);
u.write(95);
m.write(100);
b.write(50);


}
void loop()
{}
/*
u.write(75+(0));
m.write(90+(40));
b.write(55+(-65));
_delay_ms(t1);

u.write(75+(0));
m.write(90+(84));
b.write(55+(108));
_delay_ms(t1);

u.write(75+(0));
m.write(90+(55));
b.write(55+(70));
_delay_ms(t1);

u.write(75+(0));
m.write(90+(50));
b.write(55+(63));
_delay_ms(t1);
}*/
