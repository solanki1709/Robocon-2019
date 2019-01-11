 #include <io128.h>
#include <sra128.h>

#include <pinDefsAutoNew.h>
int x = 400 ;
void setup() 
{
  DDRC |= 0xFF;
  pwm1_init();
  pwm3_init();
  set_pwm1a(x);
 // set_pwm1b(x);
 // set_pwm3a(x);
 // set_pwm3b(x);
}
void bot_backward()
{
  MOTORFF = 1;
  MOTORFB = 0;
  MOTORLF = 1;
  MOTORLB = 0;
  MOTORBF = 1;
  MOTORBB = 0;
  MOTORRF = 1;
  MOTORRB = 0; 
}
void bot_forward()
{
 
  MOTORFF = 0;
  MOTORFB = 1;
  MOTORLF = 0;
  MOTORLB = 1;
  MOTORBF = 0;
  MOTORBB = 1;
  MOTORRF = 0;
  MOTORRB = 1;  
}
void bot_right()
{
  MOTORFF = 1;
  MOTORFB = 0;
  MOTORLF = 0;
  MOTORLB = 1;
  MOTORBF = 1;
  MOTORBB = 0;
  MOTORRF = 0;
  MOTORRB = 1; 
}
void bot_left()
{
  MOTORFF = 0;
  MOTORFB = 1;
  MOTORLF = 1;
  MOTORLB = 0;
  MOTORBF = 0;
  MOTORBB = 1;
  MOTORRF = 1;
  MOTORRB = 0;
}
void spot_right()
{
  MOTORFF = 1;
  MOTORFB = 0;
  MOTORLF = 0;
  MOTORLB = 1;
  MOTORBF = 0;
  MOTORBB = 1;
  MOTORRF = 1;
  MOTORRB = 0;  
}
void spot_left()
{
  MOTORFF = 0;
  MOTORFB = 1;
  MOTORLF = 1;
  MOTORLB = 0;
  MOTORBF = 1;
  MOTORBB = 0;
  MOTORRF = 0;
  MOTORRB = 1;  
}

void loop() 
{
//bot_forward();
//delay(5000);
//bot_backward();
//delay(5000);
bot_right();
//delay(5000);
//bot_left();
//delay(5000);
//spot_right();
//delay(5000);
//spot_left();
//delay(5000);

}
