

void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

void loop() 
{
  float pot_res;
  pot_res=analogRead(A0);
  Serial.println(pot_res);

}
