#include <Arduino.h>
#define GREEN_LED_PIN 5
#define RESOLUTION 10
#define FREQUENCY 5000

int brightness = 0;

void setup() {
	Serial.begin(115200);
	ledcAttach(GREEN_LED_PIN, FREQUENCY, RESOLUTION);
}

void loop() {
	ledcWrite(GREEN_LED_PIN, brightness);
	brightness = (brightness + 1) % (1 << RESOLUTION);
	Serial.printf("Brightness: %d\n", brightness);
}