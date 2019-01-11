//t2 is -ve t1or going out multi t2 ot1 python by -1
// change link lengths in the code

// front ---------goes with path smoothened and old code
// back ----------- goes with push motion

#include <Servo.h>

// for front servos
Servo uf;   
Servo mf;
Servo bf;
static int t1=100; 
int spoint_u = 105;
int spoint_m = 85;
int spoint_b = 40;

// back servos
Servo ub;   
Servo mb;
Servo bb;
int a=105;
int d=85;
int c=40;


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
//1
uf.write(spoint_u+(0));
mf.write(spoint_m+(-40));
bf.write(spoint_b+(65));
_delay_ms(100);
ub.write(spoint_u+(0));
mb.write(spoint_m+(-11));
bb.write(spoint_b+(52));    //   aaaaaaaaaaaaaaaaaaaa
_delay_ms(100);

//2
uf.write(spoint_u+(0));
mf.write(spoint_m+(-53));
bf.write(spoint_b+(106));
_delay_ms(100);

ub.write(spoint_u+(0));
mb.write(spoint_m+(-15));
bb.write(spoint_b+(54));// aaaaaaaaaaaaaaaaaaaaaaaa
_delay_ms(100);

uf.write(spoint_u+(0));
mf.write(spoint_m+(-47));
bf.write(spoint_b+(104));
_delay_ms(t1);
_delay_ms(100);

ub.write(spoint_u+(0));
mb.write(spoint_m+(-18));
bb.write(spoint_b+(57));//aaaaaaaaaaaaaaaa
_delay_ms(100);

uf.write(spoint_u+(0));
mf.write(spoint_m+(-42));
bf.write(spoint_b+(101));
_delay_ms(t1);
_delay_ms(100);

ub.write(spoint_u+(0));
mb.write(spoint_m+(-23));
bb.write(spoint_b+(60));//aaaaaaaaaaaaaaaaaaaaaa
_delay_ms(100);
uf.write(spoint_u+(0));
mf.write(spoint_m+(-31));
bf.write(spoint_b+(88));
_delay_ms(100);
ub.write(spoint_u+(0));
mb.write(spoint_m+(-27));
bb.write(spoint_b+(62));//aaaaaaaaaaaaaa
_delay_ms(100);

ub.write(spoint_u+(0));
mb.write(spoint_m+(-38));
bb.write(spoint_b+(65));//aaaaaaaaaaaaa
_delay_ms(100);

// push motion


//9 points for increaing smoothness of  returning path
ub.write(spoint_u+(0));
mb.write(spoint_m+(-35));
bb.write(spoint_b+(65));//aaaaaaaaaaaaaa
_delay_ms(100);

// push motion


//10 points for increaing smoothness of  returning path
ub.write(spoint_u+(0));
mb.write(spoint_m+(-31));
bb.write(spoint_b+(64));//aaaaaaaaaaaaaaaaaaa
_delay_ms(100);
//3
uf.write(spoint_u+(0));
mf.write(spoint_m+(-11));
bf.write(spoint_b+(52));
_delay_ms(100);

ub.write(spoint_u+(0));
mb.write(spoint_m+(-40));
bb.write(spoint_b+(65));//aaaaaaaaaaaaaaaaaa
_delay_ms(100);


//4 points for increaing smoothness of  returning path
uf.write(spoint_u+(0));
mf.write(spoint_m+(-15));
bf.write(spoint_b+(54));
_delay_ms(100);
//push motion
ub.write(spoint_u+(0));
mb.write(spoint_m+(-53));
bb.write(spoint_b+(106));//aaaaaaaaaaaaaaaa
_delay_ms(100);

//5 points for increaing smoothness of  returning path
uf.write(spoint_u+(0));
mf.write(spoint_m+(-18));
bf.write(spoint_b+(57));
_delay_ms(100);

// push motion
ub.write(spoint_u+(0));
mb.write(spoint_m+(-53));
bb.write(spoint_b+(106));//aaaaaaaaaaaaa
_delay_ms(100);

//6 points for increaing smoothness of  returning path
uf.write(spoint_u+(0));
mf.write(spoint_m+(-23));
bf.write(spoint_b+(60));
_delay_ms(100);
// push motion
//6
ub.write(spoint_u+(0));
mb.write(spoint_m+(-47));
bb.write(spoint_b+(104));
_delay_ms(100);
//aaaaaaaaaaaaaaa


//7   half returning path complete 
uf.write(spoint_u+(0));
mf.write(spoint_m+(-27));
bf.write(spoint_b+(62));
_delay_ms(100);

ub.write(spoint_u+(0));
mb.write(spoint_m+(-42));
bb.write(spoint_b+(101));
_delay_ms(100);//aaaaaaaaaaaa

// push half complete                               can even decrease the value of servo 2 for an efficient push motion
//7
// half mid of returning back


//8 points for increaing smoothness of  returning path
uf.write(spoint_u+(0));
mf.write(spoint_m+(-38));
bf.write(spoint_b+(65));
_delay_ms(100);

// push motion
ub.write(spoint_u+(0));
mb.write(spoint_m+(-31));
bb.write(spoint_b+(88));
_delay_ms(100);//aaaaaaaaaaaa

//9 points for increaing smoothness of  returning path
uf.write(spoint_u+(0));
mf.write(spoint_m+(-35));
bf.write(spoint_b+(65));
_delay_ms(100);

// push motion


//10 points for increaing smoothness of  returning path
uf.write(spoint_u+(0));
mf.write(spoint_m+(-31));
bf.write(spoint_b+(64));
_delay_ms(100);

ub.write(spoint_u+(0));
mb.write(spoint_m+(-11));
bb.write(spoint_b+(52));//aaaaaaaaaaa
_delay_ms(100);
// push mtotion

}
/*
  //1 home positiom

ub.write(a+(0));
mb.write(d+(40));
bb.write(c+(-65));
_delay_ms(t1);
//2 at the top

ub.write(a+(0));
mb.write(d+(84));
bb.write(c-(108));
_delay_ms(t1);


//3 at the front extreme

ub.write(a+(0));
mb.write(d+(55));
bb.write(c-(70));
_delay_ms(t1);
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
ub.write(a+(0));
mb.write(d+(50));
bb.write(c-(57));
_delay_ms(t1);
ub.write(a+(0));
mb.write(d+(50));
bb.write(c-(63));
_delay_ms(t1);
*/
