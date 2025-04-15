#ifndef NETWORK_H
#define NETWORK_H

#include <Arduino.h>

// Inicializa la conexión WiFi
bool networkInit();

// Intenta reconectar si se perdió la conexión
bool networkReconnect();

// Envía datos al servidor
bool sendData(String endpoint, String jsonData);

// Recibe datos del servidor
String receiveData(String endpoint);

#endif
EOF

cat > arduino/fingerprint_device/network.cpp << 'EOF'
#include "network.h"
#include "config.h"
#include <WiFi.h>
#include <HTTPClient.h>

bool networkInit() {
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  
  int attempts = 0;
  while (WiFi.status() != WL_CONNECTED && attempts < 20) {
    delay(500);
    attempts++;
  }
  
  return (WiFi.status() == WL_CONNECTED);
}

bool networkReconnect() {
  if (WiFi.status() == WL_CONNECTED) {
    return true;
  }
  
  WiFi.disconnect();
  delay(1000);
  return networkInit();
}

bool sendData(String endpoint, String jsonData) {
  if (WiFi.status() != WL_CONNECTED) {
    return false;
  }
  
  HTTPClient http;
  http.begin(String(SERVER_URL) + endpoint);
  http.addHeader("Content-Type", "application/json");
  http.addHeader("X-API-Key", API_KEY);
  
  int httpCode = http.POST(jsonData);
  http.end();
  
  return (httpCode == 200 || httpCode == 201);
}

String receiveData(String endpoint) {
  if (WiFi.status() != WL_CONNECTED) {
    return "";
  }
  
  HTTPClient http;
  http.begin(String(SERVER_URL) + endpoint);
  http.addHeader("X-API-Key", API_KEY);
  
  int httpCode = http.GET();
  String payload = "";
  
  if (httpCode == 200) {
    payload = http.getString();
  }
  
  http.end();
  return payload;
}