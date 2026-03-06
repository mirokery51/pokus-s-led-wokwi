/*
 * pokus-s-led-wokwi
 * Ovládanie LED cez WiFi a MQTT z viacerých zariadení.
 *
 * Konfigurácia:
 *   WIFI_SSID     – názov WiFi siete
 *   WIFI_PASSWORD – heslo WiFi siete
 *   MQTT_BROKER   – adresa MQTT brokera (napr. broker.hivemq.com)
 *   MQTT_PORT     – port MQTT brokera (štandardne 1883)
 *   MQTT_TOPIC    – téma na ovládanie LED (napr. "pokus/led")
 *
 * Správy MQTT:
 *   "ON"   – rozsvieti LED
 *   "OFF"  – zhasne LED
 *   "BLINK"– spustí blikanie LED
 */

#ifndef LED_BUILTIN
#define LED_BUILTIN 2
#endif

#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>

// ── Konfigurácia – zmeňte podľa svojho prostredia ──────────────────────────
#ifndef WIFI_SSID
#define WIFI_SSID     "Wokwi-GUEST"
#endif
#ifndef WIFI_PASSWORD
#define WIFI_PASSWORD ""
#endif
#ifndef MQTT_BROKER
#define MQTT_BROKER   "broker.hivemq.com"
#endif
#ifndef MQTT_PORT
#define MQTT_PORT     1883
#endif
#ifndef MQTT_TOPIC
#define MQTT_TOPIC    "pokus/led"
#endif
// ────────────────────────────────────────────────────────────────────────────

const int LED_PIN = LED_BUILTIN;

// Možné stavy LED
enum LedMode { MODE_OFF, MODE_ON, MODE_BLINK };
LedMode ledMode = MODE_BLINK;

WiFiClient   wifiClient;
PubSubClient mqttClient(wifiClient);

// ── Pomocné funkcie ─────────────────────────────────────────────────────────

void connectWifi() {
  Serial.printf("Pripájam sa na WiFi: %s\n", WIFI_SSID);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  unsigned long start = millis();
  while (WiFi.status() != WL_CONNECTED && millis() - start < 10000) {
    delay(500);
    Serial.print('.');
  }
  if (WiFi.status() == WL_CONNECTED) {
    Serial.printf("\nWiFi pripojené. IP: %s\n", WiFi.localIP().toString().c_str());
  } else {
    Serial.println("\nWiFi – nepodarilo sa pripojiť. Bežím bez siete.");
  }
}

void mqttCallback(char* topic, byte* payload, unsigned int length) {
  String message;
  for (unsigned int i = 0; i < length; i++) {
    message += (char)payload[i];
  }
  message.trim();
  Serial.printf("MQTT [%s]: %s\n", topic, message.c_str());

  if (message.equalsIgnoreCase("ON")) {
    ledMode = MODE_ON;
  } else if (message.equalsIgnoreCase("OFF")) {
    ledMode = MODE_OFF;
  } else if (message.equalsIgnoreCase("BLINK")) {
    ledMode = MODE_BLINK;
  }
}

void connectMqtt() {
  if (WiFi.status() != WL_CONNECTED) return;

  String clientId = "esp32-led-";
  clientId += String(random(0xffff), HEX);

  Serial.printf("Pripájam sa na MQTT broker: %s:%d\n", MQTT_BROKER, MQTT_PORT);
  if (mqttClient.connect(clientId.c_str())) {
    Serial.println("MQTT pripojené.");
    mqttClient.subscribe(MQTT_TOPIC);
    Serial.printf("Odber témy: %s\n", MQTT_TOPIC);
  } else {
    Serial.printf("MQTT – nepodarilo sa pripojiť (stav %d)\n", mqttClient.state());
  }
}

// ── Arduino setup / loop ────────────────────────────────────────────────────

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  connectWifi();

  mqttClient.setServer(MQTT_BROKER, MQTT_PORT);
  mqttClient.setCallback(mqttCallback);
  connectMqtt();
}

void loop() {
  // Udržiavame MQTT spojenie
  if (WiFi.status() == WL_CONNECTED) {
    if (!mqttClient.connected()) {
      static unsigned long lastRetry = 0;
      if (millis() - lastRetry > 5000) {
        lastRetry = millis();
        connectMqtt();
      }
    }
    mqttClient.loop();
  }

  // Ovládanie LED podľa aktuálneho režimu
  switch (ledMode) {
    case MODE_ON:
      digitalWrite(LED_PIN, HIGH);
      break;
    case MODE_OFF:
      digitalWrite(LED_PIN, LOW);
      break;
    case MODE_BLINK: {
      static unsigned long lastBlink = 0;
      static bool blinkState = false;
      if (millis() - lastBlink >= 500) {
        lastBlink = millis();
        blinkState = !blinkState;
        digitalWrite(LED_PIN, blinkState ? HIGH : LOW);
      }
      break;
    }
  }
}




