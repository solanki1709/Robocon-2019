void setup() {
  // put your setup code here, to run once:
  DDRC = 0xff;
  PORTC = 0x00;
  Serial.begin(9600);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  int userInput = 0;
  if(Serial.available()>0)
    {
      userInput = Serial.read();
      if(userInput == 3)
        {
          PORTC = 0xff;
        }
       else
        {
          PORTC = 0x00;
        }
    }

}
