#include <Arduino.h>
#include <unity.h>
//pio  test -e uno --verbose

void setup() {
    delay(2000);

    UNITY_BEGIN();

    pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {

}