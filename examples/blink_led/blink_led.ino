// Use as Public domain
// Original author: Mitsumine Suzu 2023

// 基板上のLEDは PA5 ピンに接続されています。HIGHで点灯
const static uint8_t PIN_LED_BUILTIN = PA5;

void setup() {
    pinMode(PIN_LED_BUILTIN, OUTPUT);
}

void loop() {
    digitalWrite(PIN_LED_BUILTIN, HIGH);
    delay(500);
    digitalWrite(PIN_LED_BUILTIN, LOW);
    delay(500);
}
