#include <Arduino.h>

#include "../.pio/libdeps/lolin32/Adafruit NeoPixel/Adafruit_NeoPixel.h"
#include "../.pio/libdeps/lolin32/ESP32 BLE Keyboard/BleKeyboard.h"

#define BUTTON_PIN11 5
#define BUTTON_PIN10 18
#define BUTTON_PIN9 19
#define BUTTON_PIN6 21
#define BUTTON_PIN3 22jf
#define BUTTON_PIN4 23

#define BUTTON_PIN7 12
#define BUTTON_PIN8 13
#define BUTTON_PIN5 14
#define BUTTON_PIN2 25
#define BUTTON_PIN1 26
#define BUTTON_PIN12 27

#define LED_PIN 32
#define LED_COUNT 21

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

uint32_t blue = strip.Color(0, 0, 255);
uint32_t green = strip.Color(0, 255, 0);
uint32_t red = strip.Color(255, 0, 0);
uint32_t white = strip.Color(255, 255, 255);
uint32_t black = strip.Color(0, 0, 0);
uint32_t orange = strip.Color(255, 165, 0);
uint32_t yellow = strip.Color(255, 255, 0);
uint32_t purple = strip.Color(128, 0, 128);
uint32_t pink = strip.Color(255, 105, 180);
uint32_t teal = strip.Color(0, 128, 128);
uint32_t cyan = strip.Color(0, 255, 255);
uint32_t brown = strip.Color(165, 42, 42);

bool muted = false;

int startPressed3 = 0;    // the moment the button was pressed
int endPressed3 = 0;      // the moment the button was released
int holdTime3 = 0;        // how long the button was hold
int idleTime3 = 0;        // how long the button was idle

// Variables will change:
int lastState1 = HIGH;
int lastState2 = HIGH;
int lastState3 = HIGH;
int lastState4 = HIGH;
int lastState5 = HIGH;
int lastState6 = HIGH;
int lastState7 = HIGH;
int lastState8 = HIGH;
int lastState9 = HIGH;
int lastState10 = HIGH;
int lastState11 = HIGH;
int lastState12 = HIGH;
int currentState1;
int currentState2;
int currentState3;
int currentState4;
int currentState5;
int currentState6;
int currentState7;
int currentState8;
int currentState9;
int currentState10;
int currentState11;
int currentState12;

BleKeyboard bleKeyboard("Clavier du BG", "By kangapi", 100);

void shortcuts(uint32_t key) {
    bleKeyboard.press(KEY_LEFT_SHIFT);  // press and hold Shift
    bleKeyboard.press(KEY_LEFT_CTRL);
    bleKeyboard.press(KEY_LEFT_GUI);
    bleKeyboard.press(key);
    bleKeyboard.releaseAll();
}

void led(uint32_t color) {
    strip.fill(color, 0, LED_COUNT);
    strip.show();
}

void off() {
    strip.clear();
    strip.show();
}

void setup() {
    Serial.begin(115200);
    pinMode(BUTTON_PIN1, INPUT_PULLUP);
    pinMode(BUTTON_PIN2, INPUT_PULLUP);
    pinMode(BUTTON_PIN3, INPUT_PULLUP);
    pinMode(BUTTON_PIN4, INPUT_PULLUP);
    pinMode(BUTTON_PIN5, INPUT_PULLUP);
    pinMode(BUTTON_PIN6, INPUT_PULLUP);
    pinMode(BUTTON_PIN7, INPUT_PULLUP);
    pinMode(BUTTON_PIN8, INPUT_PULLUP);
    pinMode(BUTTON_PIN9, INPUT_PULLUP);
    pinMode(BUTTON_PIN10, INPUT_PULLUP);
    pinMode(BUTTON_PIN11, INPUT_PULLUP);
    pinMode(BUTTON_PIN12, INPUT_PULLUP);
    Serial.println("Starting BLE work!");
    bleKeyboard.begin();
    strip.begin();
    strip.show(); // Initialize all pixels to 'off'
}

void loop() {


    if(bleKeyboard.isConnected()) {

        currentState1 = digitalRead(BUTTON_PIN1);
        currentState2 = digitalRead(BUTTON_PIN2);
        currentState3 = digitalRead(BUTTON_PIN3);
        currentState4 = digitalRead(BUTTON_PIN4);
        currentState5 = digitalRead(BUTTON_PIN5);
        currentState6 = digitalRead(BUTTON_PIN6);
        currentState7 = digitalRead(BUTTON_PIN7);
        currentState8 = digitalRead(BUTTON_PIN8);
        currentState9 = digitalRead(BUTTON_PIN9);
        currentState10 = digitalRead(BUTTON_PIN10);
        currentState11 = digitalRead(BUTTON_PIN11);
        currentState12 = digitalRead(BUTTON_PIN12);

        if(lastState1 == LOW && currentState1 == HIGH) {
            shortcuts(KEY_F1);
            led(yellow);
        }
        if(lastState2 == LOW && currentState2 == HIGH) {
            shortcuts(KEY_F2);
        }
        if(lastState3 == LOW && currentState3 == HIGH) {

            shortcuts(KEY_F3);

            if (!muted) {
                led(red);
                muted = true;
            } else {
                off();
                muted = false;
            }
        }
        if(lastState4 == LOW && currentState4 == HIGH) {
            shortcuts(KEY_F4);
            led(red);
        }
        if(lastState5 == LOW && currentState5 == HIGH) {
            bleKeyboard.print("c");
            strip.fill(brown, 0, LED_COUNT);
            strip.show();
        }
        if(lastState6 == LOW && currentState6 == HIGH) {
            bleKeyboard.print("d");
            strip.fill(cyan, 0, LED_COUNT);
            strip.show();
        }
        if(lastState7 == LOW && currentState7 == HIGH) {
            bleKeyboard.print("e");
            strip.fill(teal, 0, LED_COUNT);
            strip.show();
        }
        if(lastState8 == LOW && currentState8 == HIGH) {
            bleKeyboard.print("f");
            strip.fill(black, 0, LED_COUNT);
            strip.show();
        }
        if(lastState9 == LOW && currentState9 == HIGH) {
            bleKeyboard.print("g");
            strip.fill(yellow, 0, LED_COUNT);
            strip.show();
        }
        if(lastState10 == LOW && currentState10 == HIGH) {
            bleKeyboard.print("h");
            strip.fill(purple, 0, LED_COUNT);
            strip.show();
        }
        if(lastState11 == LOW && currentState11 == HIGH) {
            bleKeyboard.print("i");
            strip.fill(orange, 0, LED_COUNT);
            strip.show();
        }
        if(lastState12 == LOW && currentState12 == HIGH) {
            bleKeyboard.print("j");
            strip.fill(orange, 0, LED_COUNT);
            strip.show();
        }

        // save the last state
        lastState1 = currentState1;
        lastState2 = currentState2;
        lastState3 = currentState3;
        lastState4 = currentState4;
        lastState5 = currentState5;
        lastState6 = currentState6;
        lastState7 = currentState7;
        lastState8 = currentState8;
        lastState9 = currentState9;
        lastState10 = currentState10;
        lastState11 = currentState11;
        lastState12 = currentState12;

    }
}