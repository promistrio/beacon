#include <BluetoothSerial.h>
#include <ArduinoJson.h>

BluetoothSerial bt;

DynamicJsonDocument doc(1024);

bool bluetoothInit(const char name[])
{
    if (!bt.begin(name))
    {
        Serial.println("An error occurred initializing Bluetooth");
        return false;
    }
    else
    {
        Serial.println("Bluetooth initialized");
        return true;
    }
}

void bluetoothRead()
{

}

void sendInvalid(){
    bt.println(F("INVALID"));
}
void sendCoordinates(double lat, double lon)
{
    doc["sensor"] = "gps";
    doc["lat"] = lat;
    doc["lon"] = lon;

    serializeJson(doc, bt);
}