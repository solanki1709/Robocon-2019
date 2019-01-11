//t2 is -ve t1or going out multi t2 ot1 python by -1
// change link lengths in the code

// front ---------goes with path smoothened and old code
// back ----------- goes with push motion

#include <Servo.h>

// for front servos
Servo uf;   
Servo mf;
Servo bf;
static int t1=150; 
static int t2=400;
int spoint_u = 105;
int spoint_m = 85;
int spoint_b = 40;

// back servos
Servo ub;   
Servo mb;
Servo bb;
int a=95;
int d=100;
int c=135;


void setup() {
  // put your setup code here, to run once:
// front servo
uf.attach(10);
mf.attach(11);
bf.attach(12);
//back servo
ub.attach(13);
mb.attach(14);
bb.attach(15);

_delay_ms(1000);
}
void loop()
{
//pos_1 combined
//1
uf.write(spoint_u+(0));
mf.write(spoint_m+(-40));
bf.write(spoint_b+(65));
//3 at the front extreme
ub.write(a+(0));
mb.write(d+(55));
bb.write(c-(70));

_delay_ms(t2);

//pos_2 combined
//2
uf.write(spoint_u+(0));
mf.write(spoint_m+(-53));
bf.write(spoint_b+(106));

//4
ub.write(a+(0));
mb.write(d+(53));
bb.write(c-(56));
_delay_ms(t1);
//5
ub.write(a+(0));
mb.write(d+(52));
bb.write(c-(51));
_delay_ms(t1);
//6
ub.write(a+(0));
mb.write(d+(50));
bb.write(c-(57));
_delay_ms(t1);
//7
// half mid of returning back
ub.write(a+(0));
mb.write(d+(50));
bb.write(c-(63));
_delay_ms(t2);

//pos_3 combined
//1
uf.write(spoint_u+(0));
mf.write(spoint_m+(-47));
bf.write(spoint_b+(104));
_delay_ms(t1);

uf.write(spoint_u+(0));
mf.write(spoint_m+(-42));
bf.write(spoint_b+(101));
_delay_ms(t1);

uf.write(spoint_u+(0));
mf.write(spoint_m+(-31));
bf.write(spoint_b+(88));
_delay_ms(t1);

//3
uf.write(spoint_u+(0));
mf.write(spoint_m+(-11));
bf.write(spoint_b+(52));
_delay_ms(t1);

// push motion
//8
ub.write(a+(0));
mb.write(d+(43));
bb.write(c-(57));
_delay_ms(t1);

//9
ub.write(a+(0));
mb.write(d+(41));
bb.write(c-(54));////////////////////////////////////////////// replaced 54 by 64
_delay_ms(t1);

// push mtotion
//10
ub.write(a+(0));
mb.write(d+(38));
bb.write(c-(56));
_delay_ms(t1);

//1 home positiom

ub.write(a+(0));
mb.write(d+(40));
bb.write(c+(-65));
_delay_ms(t2);

//pos_4 combined
//4 points for increaing smoothness of  returning path
uf.write(spoint_u+(0));
mf.write(spoint_m+(-15));
bf.write(spoint_b+(54));
_delay_ms(t1);

//5 points for increaing smoothness of  returning path
uf.write(spoint_u+(0));
mf.write(spoint_m+(-18));
bf.write(spoint_b+(57));
_delay_ms(t1);

//6 points for increaing smoothness of  returning path
uf.write(spoint_u+(0));
mf.write(spoint_m+(-23));
bf.write(spoint_b+(60));
_delay_ms(t1);

//7   half returning path complete 
uf.write(spoint_u+(0));
mf.write(spoint_m+(-27));
bf.write(spoint_b+(62));
_delay_ms(t1);

//2 at the top

ub.write(a+(0));
mb.write(d+(84));
bb.write(c-(108));
_delay_ms(t2);

//pos_5 combined
//8 points for increaing smoothness of  returning path
uf.write(spoint_u+(0));
mf.write(spoint_m+(-38));
bf.write(spoint_b+(65));
_delay_ms(t1);

//9 points for increaing smoothness of  returning path
uf.write(spoint_u+(0));
mf.write(spoint_m+(-35));
bf.write(spoint_b+(65));
_delay_ms(t1);

//10 points for increaing smoothness of  returning path
uf.write(spoint_u+(0));
mf.write(spoint_m+(-31));
bf.write(spoint_b+(64));
_delay_ms(t1);

//3 at the front extreme
ub.write(a+(0));
mb.write(d+(55));
bb.write(c-(70));
_delay_ms(t2);

}

