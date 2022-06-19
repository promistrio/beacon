#include <TinyGPSPlus.h>

void sendCoordinates(double lat, double lon);
void ledFlash(uint16_t flashes, uint16_t delaymS);
void sendInvalid();

#define RXD2 16
#define TXD2 17

TinyGPSPlus gps;

void displayInfo();

void initGPS()
{ // ToDo change bool and check serial connection
  Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);
  ;
}

void readGPS()
{
  while (Serial2.available() > 0)
  {
    if (gps.encode(Serial2.read()))
    {
      displayInfo();
    }
  }
}

void displayInfo()
{

  Serial.print(F("Location: "));
  if (gps.location.isValid())
  {
    Serial.print(gps.location.lat(), 6);
    Serial.print(F(","));
    Serial.print(gps.location.lng(), 6);

    sendCoordinates(gps.location.lat(), gps.location.lng());
    ledFlash(5, 5);
  }
  else
  {
    Serial.print(F("INVALID"));
    sendInvalid();
  }

  Serial.print(F("  Date/Time: "));
  if (gps.date.isValid())
  {
    Serial.print(gps.date.month());
    Serial.print(F("/"));
    Serial.print(gps.date.day());
    Serial.print(F("/"));
    Serial.print(gps.date.year());
  }
  else
  {
    Serial.print(F("INVALID"));
  }

  Serial.print(F(" "));
  if (gps.time.isValid())
  {
    if (gps.time.hour() < 10)
      Serial.print(F("0"));
    Serial.print(gps.time.hour());
    Serial.print(F(":"));
    if (gps.time.minute() < 10)
      Serial.print(F("0"));
    Serial.print(gps.time.minute());
    Serial.print(F(":"));
    if (gps.time.second() < 10)
      Serial.print(F("0"));
    Serial.print(gps.time.second());
    Serial.print(F("."));
    if (gps.time.centisecond() < 10)
      Serial.print(F("0"));
    Serial.print(gps.time.centisecond());
  }
  else
  {
    Serial.print(F("INVALID"));
  }

  Serial.println();
}

#define RXD2 16
#define TXD2 17