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

int right_X = 0;
int left_X = 0;
int right_Y  = 0;
int left_Y = 0;

int mright_X = 0;
int mleft_X = 0;
int mright_Y  = 0;
int mleft_Y = 0;

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
  LeftAnalog();
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
void LeftAnalog()
{
  left_X = jstick.Analog(PSS_LX);
  left_Y = jstick.Analog(PSS_LY);
  mleft_X = map(left_X,0,255,-127,128);
  mleft_Y = map(left_Y,0,255,128,-127);
  if(mleft_X > 0 && mleft_Y ==0)
  {
    int pwm_Right=map(mleft_X,0,128,200,500);
    setPWM(pwm_Right);
    bot_right();  
    Serial.print("pwm_Right is ");
    Serial.println(pwm_Right);   
  }
  if(mleft_X < 0 && mleft_Y==0)
  {
    int pwm_Left=map(mleft_X,0,-127,200,500);
    setPWM(pwm_Left);
    bot_left();
    Serial.print("pwm_Left is ");
    Serial.println(pwm_Left);   

  }
  if(mleft_Y >0 && mleft_X==0)
  { 
    int pwm_Forw=map(mleft_Y,0,128,200,500);
    setPWM(pwm_Forw);
    bot_forward();
    Serial.print("pwm_Forw is ");
    Serial.println(pwm_Forw);   

  }
  if(mleft_Y <0 && mleft_X==0)
  {
    int pwm_Back=map(mleft_Y,0,-127,200,500);
    setPWM(pwm_Back);
    bot_backward();
    Serial.print("pwm_Back is ");
    Serial.println(pwm_Back);   

  }
  if(mleft_X==0 && mleft_Y==0)
  {
    bot_stop(); 
    Serial.println("No PWM");   
  }
 // PrintPWM(pwm_Forw,pwm_Back,pwm_Right,pwm_Left);
}
void PrintRawVal()
{
  Serial.print("left_X is ");
  Serial.print(mleft_X);
  Serial.print("\t");
  Serial.print("left_Y is ");
  Serial.println(mleft_Y);
}
void PrintPWM(int forw,int back,int right,int left)
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

  Serial.print("Left Y:");
  Serial.println(mleft_Y);
}

  


