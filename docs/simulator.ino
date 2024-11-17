#include <WiFi.h>
#include <PubSubClient.h>
#include <LiquidCrystal_I2C.h>

const char* default_SSID = "Wokwi-GUEST";
const char* default_PASSWORD = "";
const char* default_BROKER_MQTT = "3.17.128.88";
const int default_BROKER_PORT = 1883;
const char* default_ID_MQTT = "fiware_001";

WiFiClient espClient;
PubSubClient MQTT(espClient);
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int analogPin = 34;
int CO2Level = 0;

void setup() {
  Serial.begin(115200);
  initWiFi();
  initMQTT();

  lcd.init();
  lcd.backlight();
  delay(2000);
}

void initWiFi() {
  delay(10);
  WiFi.begin(default_SSID, default_PASSWORD);
  Serial.print("Conectando ao WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("Conectado ao WiFi!");
}

void initMQTT() {
  MQTT.setServer(default_BROKER_MQTT, default_BROKER_PORT);
}

void loop() {
  verifyConnections();
  potentiometerReading();
  publishSensorData();
  displayCO2Level();
  MQTT.loop();
  delay(2000);
}

void verifyConnections() {
  if (!MQTT.connected()) {
    while (!MQTT.connected()) {
      Serial.print("Conectando ao broker MQTT...");
      if (MQTT.connect(default_ID_MQTT)) {
        Serial.println("Conectado ao broker MQTT!");
      } else {
        Serial.println("Falha ao conectar ao broker.");
        delay(2000);
      }
    }
  }
}

void potentiometerReading() {
  int sensorReading = analogRead(analogPin);
  CO2Level = map(sensorReading, 0, 4095, 350, 35000);
}

void publishSensorData() {
  String CO2Str = String(CO2Level);
  String CO2Message = CO2Str + " ppm";
  MQTT.publish("/iot/CO2", CO2Message.c_str());
}

void displayCO2Level() {
  lcd.setCursor(0, 0);
  lcd.print("Emissao de CO2:");

  lcd.setCursor(0, 1);
  lcd.print("                ");

  lcd.setCursor(0, 1);
  if (CO2Level <= 350) {
    lcd.print("Ar puro.");
  } else if (CO2Level <= 450) {
    lcd.print("Atmosfera.");
  } else if (CO2Level <= 600) {
    lcd.print("Ótima.");
  } else if (CO2Level <= 800) {
    lcd.print("Aceitavel.");
  } else if (CO2Level <= 1000) {
    lcd.print("Toleravel.");
  } else if (CO2Level <= 1500) {
    lcd.print("Arriscada.");
  } else if (CO2Level <= 2000) {
    lcd.print("Perigosa!");
  } else if (CO2Level <= 5000) {
    lcd.print("Prejudicial!");
  } else if (CO2Level <= 10000) {
    lcd.print("Emergencial!");
  } else if (CO2Level <= 20000) {
    lcd.print("Extrema!");
  } else if (CO2Level <= 30000) {
    lcd.print("Danosa!");
  } else {
    lcd.print("Fatal!");
  }
}