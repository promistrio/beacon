#include <Arduino.h>

void ledFlash(uint16_t flashes, uint16_t delaymS);

//bluettoth section
bool bluetoothInit(const char name[]);

//GNSS section
void initGPS();
void readGPS();
