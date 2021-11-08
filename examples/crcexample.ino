
#include <Arduino.h>
#include <apputils.hpp>

void setup()
{
    String mystr = "123456789";
    auto crc16 = crc16_CCITT(mystr);
    String msg = "my str: " + mystr + "; sizeof my str : " + mystr.length();
    String res = "crc16 ress : " + String(crc16);
    Serial.println(msg.c_str());
    Serial.println(res.c_str());
    if (crc16 == 10673)
    {
        Serial.println("CRC OK");
    }
    else
    {
        Serial.println("CRC ERROR. Please report to maintener");
    }
    //Verify result on https://crccalc.com/
}

void loop()
{
}