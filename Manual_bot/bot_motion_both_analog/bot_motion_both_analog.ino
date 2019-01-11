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

int x_pwm = 0;
int y_pwm = 0;

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
  readVal();
  bot_motion();
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
void readVal()
{
  right_X = jstick.Analog(PSS_RX);
  left_Y = jstick.Analog(PSS_LY);

  mright_X = map(right_X,0,255,-127,128);
  mleft_Y = map(left_Y,0,255,128,-127);
}
void bot_motion()
{

    if(mright_X > 0 && mleft_Y ==0)
    {
      bot_pwm=map(mright_X,0,128,200,500);
      if(jstick.Button(PSB_R1))
        bot_pwm=666;
      setPWM(bot_pwm);
      bot_right();  
      Serial.print("pwm_Right is ");
      Serial.println(bot_pwm);   
    }
    else if(mright_X < 0 && mleft_Y ==0)
    {
      bot_pwm=map(mright_X,0,-127,200,500);
      if(jstick.Button(PSB_R1))
        bot_pwm=666;
      setPWM(bot_pwm);
      bot_left();
      Serial.print("pwm_Left is ");
      Serial.println(bot_pwm);   
  
    }
    else if(mleft_Y >0 && mright_X == 0)
    { 
      bot_pwm=map(mleft_Y,0,128,200,500);
      if(jstick.Button(PSB_R1))
        bot_pwm=666;
      setPWM(bot_pwm);
      bot_forward();
      Serial.print("pwm_Forw is ");
      Serial.println(bot_pwm);   
  
    }
    else if(mleft_Y <0 && mright_X == 0)
    {
      bot_pwm=map(mleft_Y,0,-127,200,500);
      if(jstick.Button(PSB_R1))
        bot_pwm=666;
      setPWM(bot_pwm);
      bot_backward();
      Serial.print("pwm_Back is ");
      Serial.println(bot_pwm);   
    }
    else if(mleft_Y>0 && mright_X>0)
    {
      x_pwm=map(mright_X,0,128,200,500);
      y_pwm=map(mleft_Y,0,128,200,500);
      
    }
    else if(jstick.Button(PSB_R2))
    {
      setPWM(spot_pwm);
      bot_right();
      Serial.print("spot_right is ");
      Serial.println(spot_pwm);
    }
    else if(jstick.Button(PSB_L2))
    {
      setPWM(spot_pwm);
      bot_left();
      Serial.print("spot_left is ");
      Serial.println(spot_pwm);
    }
    else if(mleft_Y==0 && mright_X==0)
    {
      bot_pwm=0;
      bot_stop(); 
      Serial.println("No PWM"); 
    }
}

