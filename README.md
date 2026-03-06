# pokus-s-led-wokwi

ESP32 projekt so simuláciou v prostredí [Wokwi](https://wokwi.com).  
Ovládanie LED cez **WiFi + MQTT** – prístup z tejto aplikácie aj vzdialene z viacerých zariadení.

## Funkcie

| Správa MQTT | Akcia               |
|-------------|---------------------|
| `ON`        | Rozsvieti LED       |
| `OFF`       | Zhasne LED          |
| `BLINK`     | Blikanie LED (predvolené) |

## Konfigurácia

Upravte konštanty v `src/main.cpp` (alebo definujte cez build flags v `platformio.ini`):

| Konštanta       | Predvolená hodnota      | Popis                          |
|-----------------|-------------------------|--------------------------------|
| `WIFI_SSID`     | `Wokwi-GUEST`           | Názov WiFi siete               |
| `WIFI_PASSWORD` | *(prázdne)*             | Heslo WiFi siete               |
| `MQTT_BROKER`   | `broker.hivemq.com`     | Adresa verejného MQTT brokera  |
| `MQTT_PORT`     | `1883`                  | Port MQTT brokera              |
| `MQTT_TOPIC`    | `pokus/led`             | Téma na ovládanie LED          |

> **Tip:** Pre simuláciu vo Wokwi použite SSID `Wokwi-GUEST` bez hesla.  
> Pre reálne zariadenie nastavte vlastné WiFi prihlasovacie údaje.

## Vzdialené ovládanie

Akékoľvek zariadenie (mobil, PC, iný mikrokontrolér) môže ovládať LED publikovaním správy na tému `pokus/led`:

```bash
# Príklad pomocou mosquitto_pub
mosquitto_pub -h broker.hivemq.com -t pokus/led -m ON
mosquitto_pub -h broker.hivemq.com -t pokus/led -m OFF
mosquitto_pub -h broker.hivemq.com -t pokus/led -m BLINK
```

## Zapojenie (Wokwi)

- **ESP32 D2** → Anóda externej červenej LED  
- **LED katóda** → GND

## Závislosti

- [PubSubClient](https://github.com/knolleary/pubsubclient) – MQTT klient
- WiFi (vstavaná knižnica ESP32 Arduino)
