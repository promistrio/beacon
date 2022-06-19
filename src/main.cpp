/*******************************************************************************************************
  Programs for Arduino - Copyright of the author Stuart Robinson - 04/04/20

  This program is supplied as is, it is up to the user of the program to decide if the program is
  suitable for the intended purpose and free from errors.
*******************************************************************************************************/


/*******************************************************************************************************
  Program Operation - This is a program that demonstrates the detailed setup of a LoRa test transmitter.
  A packet containing ASCII text is sent according to the frequency and LoRa settings specified in the
  'Settings.h' file. The pins to access the lora device need to be defined in the 'Settings.h' file also.

  The details of the packet sent and any errors are shown on the Arduino IDE Serial Monitor, together with
  the transmit power used, the packet length and the CRC of the packet. The matching receive program,
  '104_LoRa_Receiver' can be used to check the packets are being sent correctly, the frequency and LoRa
  settings (in Settings.h) must be the same for the transmitter and receiver programs. Sample Serial
  Monitor output;

  10dBm Packet> Hello World 1234567890*  BytesSent,23  CRC,DAAB  TransmitTime,64mS  PacketsSent,2

  Serial monitor baud rate is set at 9600
*******************************************************************************************************/

#define Program_Version "V1.1"  //include the appropriate library  

#include "main.h"
#define LED1 2   


void loop()
{
  readGPS();
}

void setup()
{
  //init section
  initGPS();
  bluetoothInit("Collar");

  pinMode(LED1, OUTPUT);                                   //setup pin as output for indicator LED
  //ledFlash(2, 125);                                       //two quick LED flashes to indicate program start

  Serial.begin(9600);
  Serial.println();
  Serial.print(F(__TIME__));
  Serial.print(F(" "));
  Serial.println(F(__DATE__));
  Serial.println(F(Program_Version));
  Serial.println();
  Serial.println(F("103_LoRa_Transmitter_Detailed_Setup Starting"));

}
