#include <Arduino.h>
#include <unity.h>
#include "test_apputils.hpp"

void setup()
{
    delay(2000);

    UNITY_BEGIN(); // IMPORTANT LINE!
    test_apputils();
    UNITY_END(); // stop unit testing
}

void loop()
{
}
