#include <sra128.h>
#include <pinDefsAutoNew.h>
void setup() {
  // put your setup code here, to run once:
DDRC |= 0xFF;
pwm1_init();
pwm3_init();
}

void loop() {
  // put your main code here, to run repeatedly:
  MOTORFF = 1;
  MOTORFB = 0;
  MOTORLF = 0;
  MOTORLB = 1;
  MOTORBF = 0;
  MOTORBB = 1;
  MOTORRF = 1;
  MOTORRB = 0;
  
//  set_pwm1a(500)
//  set_pwm1b(500);
//  set_pwm3a(500);
set_pwm3b(500);
}
