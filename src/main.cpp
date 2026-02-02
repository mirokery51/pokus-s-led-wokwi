#include <Arduino.h>

#define LED_PIN 2
const bool INVERTED = true;

// put function declarations here:
int myFunction(int, int);

void setup() {
  Serial.begin(115200);
  // Nastavíme pin ako výstupný a použijeme pomocnú funkciu
  pinMode(LED_PIN, OUTPUT);
  Serial.println("Start");
  int result = myFunction(2, 3);
}

void loop() {
  // Blikanie LED (podporuje invertovanú logiku)
  digitalWrite(LED_PIN, INVERTED ? LOW : HIGH);
  Serial.println("LED ON");
  delay(500);
  digitalWrite(LED_PIN, INVERTED ? HIGH : LOW);
  Serial.println("LED OFF");
  delay(500);
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}