/**
 * Sistema de Control de Asistencia - Dispositivo de Huella Digital
 * 
 * Este sketch se ejecuta en un ESP32 con un sensor de huella digital
 * para registrar la asistencia de los empleados.
 */

#include "config.h"
#include "fingerprint.h"
#include "network.h"
#include "display.h"

// Variables globales
bool isConnected = false;
String deviceId = "";

void setup() {
  Serial.begin(115200);
  Serial.println("Iniciando dispositivo de control de asistencia...");
  
  // Inicializar pantalla
  displayInit();
  displayMessage("Iniciando...");
  
  // Inicializar sensor de huella
  if (!fingerprintInit()) {
    displayMessage("Error: Sensor");
    while (1) { delay(1000); }
  }
  
  // Inicializar conexión WiFi
  displayMessage("Conectando WiFi");
  isConnected = networkInit();
  if (!isConnected) {
    displayMessage("Error: WiFi");
    // Continuar en modo offline
  }
  
  // Obtener ID del dispositivo
  deviceId = getDeviceId();
  
  // Registrar dispositivo en el servidor
  if (isConnected) {
    if (registerDevice()) {
      displayMessage("Dispositivo listo");
    } else {
      displayMessage("Error: Registro");
    }
  } else {
    displayMessage("Modo sin conexión");
  }
  
  delay(2000);
  displayMessage("Coloque su dedo");
}

void loop() {
  // Verificar conexión periódicamente
  if (!isConnected) {
    isConnected = networkReconnect();
    if (isConnected) {
      // Intentar sincronizar registros pendientes
      syncPendingRecords();
    }
  }
  
  // Verificar si hay un dedo en el sensor
  if (fingerprintDetect()) {
    displayMessage("Procesando...");
    
    // Identificar huella
    int fingerprintId = fingerprintIdentify();
    
    if (fingerprintId >= 0) {
      // Huella reconocida
      displayMessage("Bienvenido!");
      
      // Registrar asistencia
      if (isConnected) {
        if (recordAttendance(fingerprintId)) {
          displayMessage("Registro exitoso");
        } else {
          displayMessage("Error de registro");
          // Guardar registro localmente
          saveLocalRecord(fingerprintId);
        }
      } else {
        // Guardar registro localmente
        saveLocalRecord(fingerprintId);
        displayMessage("Guardado local");
      }
    } else {
      // Huella no reconocida
      displayMessage("No reconocido");
    }
    
    delay(2000);
    displayMessage("Coloque su dedo");
  }
  
  delay(100);
}

// Función para registrar asistencia en el servidor
bool recordAttendance(int fingerprintId) {
  // Implementar lógica para enviar registro al servidor
  return true;
}

// Función para guardar registro localmente cuando no hay conexión
void saveLocalRecord(int fingerprintId) {
  // Implementar lógica para guardar en memoria local
}

// Función para sincronizar registros pendientes
void syncPendingRecords() {
  // Implementar lógica para sincronizar registros guardados localmente
}

// Función para obtener ID único del dispositivo
String getDeviceId() {
  // Implementar lógica para obtener ID único
  return "DEV001";
}

// Función para registrar el dispositivo en el servidor
bool registerDevice() {
  // Implementar lógica para registrar el dispositivo
  return true;
}