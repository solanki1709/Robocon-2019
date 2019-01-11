#include <io128.h>
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

int left_X = 0;
int right_X = 0;
int left_Y  = 0;
int right_Y = 0;

int mleft_X = 0;
int mright_X = 0;
int mleft_Y  = 0;
int mright_Y = 0;

void setup() 
{
  jstick.config_gamepad(clock_pin,command_pin,attention_pin,data_pin,press_sens,rumble_motor);
  DDRC |= 0xFF;
  Serial.begin(57600); 
  pwm1_init();
  pwm3_init();
}


void loop() 
{
  jstick.read_gamepad();
  RightAnalog();
 // PrintRawVal();
  delay(50);
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
//void PrintPWM(int ,int ,int ,int );
void RightAnalog()
{
  right_X = jstick.Analog(PSS_RX);
  right_Y = jstick.Analog(PSS_RY);
  mright_X = map(right_X,0,255,-127,128);
  mright_Y = map(right_Y,0,255,128,-127);
  if(mright_X > 0 && mright_Y ==0)
  {
    int pwm_Right=map(mright_X,0,128,200,500);
    setPWM(pwm_Right);
    bot_right();  
    Serial.print("pwm_Right is ");
    Serial.println(pwm_Right);   
  }
  if(mright_X < 0 && mright_Y==0)
  {
    int pwm_Left=map(mright_X,0,-127,200,500);
    setPWM(pwm_Left);
    bot_left();
    Serial.print("pwm_Left is ");
    Serial.println(pwm_Left);   

  }
  if(mright_Y >0 && mright_X==0)
  { 
    int pwm_Forw=map(mright_Y,0,128,200,500);
    setPWM(pwm_Forw);
    bot_forward();
    Serial.print("pwm_Forw is ");
    Serial.println(pwm_Forw);   

  }
  if(mright_Y <0 && mright_X==0)
  {
    int pwm_Back=map(mright_Y,0,-127,200,500);
    setPWM(pwm_Back);
    bot_backward();
    Serial.print("pwm_Back is ");
    Serial.println(pwm_Back);   

  }
  if(mright_X==0 && mright_Y==0)
  {
    bot_stop(); 
    Serial.println("No PWM");   
  }
 // PrintPWM(pwm_Forw,pwm_Back,pwm_Right,pwm_Right);
}
void PrintRawVal()
{
  Serial.print("right_X is ");
  Serial.print(mright_X);
  Serial.print("\t");
  Serial.print("right_Y is ");
  Serial.println(mright_Y);
}
void PrintPWM(int forw,int back,int left,int right)
{
  Serial.print("Forward:");
  Serial.print(forw);
  Serial.print("\t");

  Serial.print("Backward:");
  Serial.print(back);
  Serial.print("\t");

  Serial.print("Left:");
  Serial.print(left);
  Serial.print("\t");

  Serial.print("Right:");
  Serial.println(right);
}
void PrintAnalog()
{
  Serial.print("Right X:");
  Serial.print(mright_X);
  Serial.print("\t");

  Serial.print("Right Y:");
  Serial.print(mright_Y);
  Serial.print("\t");

  Serial.print("Left X:");
  Serial.print(mleft_X);
  Serial.print("\t");

  Serial.print("left Y:");
  Serial.println(mleft_Y);
}

  


