#include <sra128.h>
#include <PS2X_lib.h>
#include <pinDefsAutoNew.h>

#define data_pin 26
#define clock_pin 16
#define command_pin 27
#define attention_pin 36

boolean press_sens = false;  //disabled pressure sensitivity
boolean rumble_motor = false;  //disabled rumble motor

PS2X jstick;

//int left_X = 0;
int right_X = 0;
int left_Y  = 0;
//int right_Y = 0;

//int mleft_X = 0;
int mright_X = 0;
int mleft_Y  = 0;
//int mright_Y = 0;

int bot_pwm = 0;
int max_PWM = 500;
int min_PWM = 200;
int spot_pwm = 300;

int pmotorA = 0;
int pmotorB = 0;

void setup()
{
  jstick.config_gamepad(clock_pin, command_pin, attention_pin, data_pin, press_sens, rumble_motor);
  DDRC |= 0xFF;
  Serial.begin(57600);
  pwm1_init();
  pwm3_init();
}

void loop()
{
  jstick.read_gamepad();
  readVal();
  bot_motion();
  delay(50);

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
void bot_stop()
{
  MOTORFF = 0;
  MOTORFB = 0;
  MOTORLF = 0;
  MOTORLB = 0;
  MOTORBF = 0;
  MOTORBB = 0;
  MOTORRF = 0;
  MOTORRB = 0;
}
void setPWM(int pwm_val)
{
  set_pwm1a(pwm_val);
  set_pwm1b(pwm_val);
  set_pwm3a(pwm_val);
  set_pwm3b(pwm_val);
}
void readVal()
{
  right_X = jstick.Analog(PSS_RX);
  left_Y = jstick.Analog(PSS_LY);

  mright_X = map(right_X, 0, 255, -127, 128);
  mleft_Y = map(left_Y, 0, 255, 128, -127);
}
void bot_motion()
{
  int motorA = mleft_Y + mright_X;
  int motorB = mleft_Y - mright_X;

  if(motorA)
     pmotorA = map(constrain(abs(motorA),0,127),0,127,200,500);
  else
    pmotorA = 0;
  if(motorB)    
     pmotorB = map(constrain(abs(motorB),0,127),0,127,200,500);
  else
    pmotorB = 0;
    
  set_pwm1a(pmotorA);
  set_pwm3a(pmotorA);
  set_pwm1b(pmotorB);
  set_pwm3b(pmotorB);
  if (motorA > 0)
  {
    MOTORRF = MOTORLF = 0;
    MOTORRB = MOTORLB = 1;
  }
  else if (motorA < 0)
  {
    MOTORRF = MOTORLF = 1;
    MOTORRB = MOTORLB = 0;
  }
  else if (motorA == 0)
  {
    Serial.println("1 and 3 stop");
    MOTORRF = MOTORLF = 0;
    MOTORRB = MOTORLB = 0;
  }
  if (motorB > 0)
  {
    MOTORFF = MOTORBF = 0;
    MOTORFB = MOTORBB = 1;
  }
  else if (motorB < 0)
  {
    MOTORFF = MOTORBF = 1;
    MOTORFB = MOTORBB = 0;
  }
  else if (motorB == 0)
  {
    Serial.println("2 and 4 stop");
    MOTORFF = MOTORBF = 0;
    MOTORFB = MOTORBB = 0;
  }
  


//  Serial.print(mleft_Y);
//  Serial.print("\t");
//  Serial.print(mright_X);
//  Serial.print("\t");
//  Serial.print(motorA);
//  Serial.print("\t");
//  Serial.print(motorB);
//  Serial.print("\t");
  Serial.print(pmotorA);
  Serial.print("\t");
  Serial.println(pmotorB);
  
//    if (bot_pwm != 0 && jstick.Button(PSB_R1))
//    {
//      bot_pwm = 666;
//      setPWM(bot_pwm);
//    }
  }

