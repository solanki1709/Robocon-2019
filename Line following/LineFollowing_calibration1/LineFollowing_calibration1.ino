//forward and right is front side of bot
#include <pinDefsAutoNew.h>
#include <io128.h>
#include <sra128.h>
#include "mcp.h"

#define frontSensorCS PF0
#define backSensorCS PF1

int frontRaw[8];
//long int averageFrontWhite[8],averageFrontBlack[8],averageBackBlack[8],averageBackWhite[8];

long int averageFrontBlack[8] = {3002 , 2497 , 2732 , 3001 , 2949 , 2792 , 2948 , 2949 };   // 2909 _____-2732
long int averageFrontWhite[8] = {1950  , 667  , 182  , 797  , 216  , 180  , 202  , 432};
long int averageBackBlack[8] = {3007 , 3007 , 3007 , 2884 , 2969 , 2537 , 2969 , 2970};
long int averageBackWhite[8] = {1950  , 667  , 182  , 797  , 216  , 180  , 842 , 1348  };  

int backRaw[8];
int frontMapped[8], BackMapped[8];



// Update the Raw Values (Front)
void updateFrontSensor()
{
  for (int i = 0; i < 8; i++)
  {
    frontRaw[i] = getSensorReading(frontSensorCS, i);
  }
}

// Update the Raw Values (Back)
void updateBackSensor()
{
  for (int i = 0; i < 8; i++)
  {
    backRaw[i] = getSensorReading(backSensorCS, i);

  }
}

void updateAllSensors()
{
  updateFrontSensor();
  updateBackSensor();
}

void calculateThresh_front_black()
{ 
  long int sum[8];

    for (int j = 0; j < 8; j++)
    {   
      sum[j]=0;
      for(int i=1;i<=100;i++)
      {
        updateAllSensors();
        sum[j] += frontRaw[j];
      }

      averageFrontBlack[j]= sum[j]/100; 
    } 
}



void calculateThresh_front_white()
{ 
  long int sum[8];

    for (int j = 0; j < 8; j++)
    {   
      sum[j]=0;
      for(int i=1;i<=100;i++)
      {
        updateAllSensors();
        sum[j] += frontRaw[j];
      }

      averageFrontWhite[j]= sum[j]/100; 
    } 
}

void calculateThresh_back_black()
{ 
  long int sum[8];

    for (int j = 0; j < 8; j++)
    {   
      sum[j]=0;
      for(int i=1;i<=100;i++)
      {
        updateAllSensors();
        sum[j] += backRaw[j];
      }

      averageBackBlack[j]= sum[j]/100; 
    } 
}

void calculateThresh_back_white()
{ 
  long int sum[8];

    for (int j = 0; j < 8; j++)
    {   
      sum[j]=0;
      for(int i=1;i<=100;i++)
      {
        updateAllSensors();
        sum[j] += backRaw[j];
      }

      averageBackWhite[j]= sum[j]/100; 
    } 
}

// Maps the Values with ThreshHolds
void mapFront()
{
  for (int j = 0; j < 8; j++)
  {

    frontMapped[j] = constrain(map(frontRaw[j],averageFrontWhite[j],averageFrontBlack[j], 0, 1000),0,1000); 
  }
}

// Maps the Values with ThreshHolds
void mapBack()
{
  for (int j = 0; j < 8; j++)
  {
    BackMapped[j] = constrain(map(backRaw[j], averageBackWhite[j],averageBackBlack[j], 0, 1000),0,1000);
  }

}

void mapAll()
{
  mapFront();
  mapBack();
}


// 2600 back and front  
int main() {
  //  PORTA |= (1 << PA4);

  //  if(bit_is_clear)
  // while (bit_is_set(PINA, 4));
  //{
  Serial.begin(115200);
  DDRC = 0xFF;
  DDRA = 0x00;
  PORTA=0xFF;
  spiMasterInit();
  DDRD |=  (1 << PD6) | (1 << PD7);
  PORTD |=   (1 << PD6) | (1 << PD7);
  pwm1_init();
  pwm3_init();
  // Main Loop
  while (1)
  {   // Calculate threshold for front_black
      if(bit_is_clear(PINA,5))
      {
        Serial.println("Calibrating front-black");
        calculateThresh_front_black();
        mapAll();
      } 
      // Calculate threshold for front_white
      else if(bit_is_clear(PINA,7))
      {
        Serial.println("Calibrating front-white");
        calculateThresh_front_white();
        mapAll();
      } 
      // Calculate threshold for back_black
      else if(bit_is_clear(PINA,4))
      {
        Serial.println("Calibrating back-black");
        calculateThresh_back_black();
        mapAll();
      } 
      // Calculate threshold for back_white 
      else if(bit_is_clear(PINA,6 ))
      {
        Serial.println("Calibrating back-white");
        calculateThresh_back_white();
        mapAll();
      }
      else
      {
        // Write Print Statements Here
       
        updateAllSensors();
         mapAll();
       displayFrontValuesAll();
      
       displayBackValuesAll();
      displayFrontAverages();
     displayBackAverages();

      Serial.println();
       

      }
  }
}

// Displays Raw Values
void displayFrontValuesAll()
{
  Serial.print("FrontSensor:-- Raw:");
  for(int i=0;i<8;i++)
  {
    Serial.print(frontRaw[i]);
    Serial. print(", ");
  }

  Serial.print("Mapped(0-1000):");
  for (int i = 0 ; i < 8; i++)
  { 
    Serial.print(frontMapped[i]);
    Serial.print(" , ");

  }
  Serial.println();
}

void displayFrontAverages()
{
  Serial.print("Front Average:-- White(Fixed):");
  for(int i=0;i<8;i++)
  {
    Serial.print(averageFrontWhite[i]);
    Serial. print("  , ");
  }

  Serial.print("Back(Fixed):");
  for (int i = 0 ; i < 8; i++)
  { 
    Serial.print(averageFrontBlack[i]);
    Serial.print(" , ");

  }
  Serial.println(); 
}

void displayBackAverages()
{
  Serial.print("Back Average:-- White(Fixed):");
  for(int i=0;i<8;i++)
  {
    Serial.print(averageBackWhite[i]);
    Serial. print(" , ");
  }

  Serial.print("Back(Fixed):");
  for (int i = 0 ; i < 8; i++)
  { 
    Serial.print(averageBackBlack[i]);
    Serial.print(" , ");

  }
  Serial.println(); 
}


void displayBackValuesAll()
{
  Serial.print("BackSensor :-- Raw:");
  for (int l = 0 ; l < 8; l++)
  { 
    Serial.print(backRaw[l]);
    Serial.print(" , ");

  }

  Serial.print("Mapped(0-1000):");
  for (int l = 0 ; l < 8; l++)
  { 
    Serial.print(BackMapped[l]);
    Serial.print(" , ");

  }
  Serial.println();
}



