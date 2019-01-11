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
void setup() 
  {
  
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
