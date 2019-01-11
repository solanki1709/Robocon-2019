#include <io128.h>
#include <sra128.h>
#include <pinDefsAutoNew.h>
#include "mcp.h"

#define frontSensorCS PF0
#define sideSensorCS PF1

int frontSensorReading[8];
int sideSensorReading[8];

#define numOfSensors 8
void readFrontSensor()
{
  for(int i =0;i<8;i++)
  {
    frontSensorReading[i] = getSensorReading(frontSensorCS,i);
  }
}

void readSideSensor()
{
  for(int i =0;i<8;i++)
  {
     sideSensorReading[i] = getSensorReading(sideSensorCS,i);
  }
}
void displayFrontValues()
{
  Serial.print("FrontSensor : ");
  for(int i=0 ; i<8;i++)
  {
    Serial.print(frontSensorReading[i]);
    Serial.print("\t");
  }
  Serial.println();
}

void displaySideValues()
{
  Serial.print("sideSensor : ");
  for(int i=0 ; i<8;i++)
  {
    Serial.print(sideSensorReading[i]);
    Serial.print("\t");
  }
  Serial.println();
}
void setup()
{
  Serial.begin(115200);
  Serial.println("Setup Start");
  spiMasterInit();
  Serial.println("Setup End");
}
void loop()
{
    readFrontSensor();
    readSideSensor();
    displayFrontValues();
    displaySideValues();
}



