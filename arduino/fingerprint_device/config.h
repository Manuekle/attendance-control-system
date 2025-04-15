#ifndef CONFIG_H
#define CONFIG_H

// Configuración WiFi
#define WIFI_SSID "TuRedWiFi"
#define WIFI_PASSWORD "TuContraseña"

// Configuración del servidor
#define SERVER_URL "https://tu-servidor.com/api"
#define API_KEY "tu-api-key"

// Configuración del sensor de huella
#define FINGERPRINT_RX 16
#define FINGERPRINT_TX 17

// Configuración de la pantalla LCD
#define LCD_ADDRESS 0x27
#define LCD_COLS 16
#define LCD_ROWS 2

// Configuración de LEDs
#define LED_RED 25
#define LED_GREEN 26
#define LED_BLUE 27

// Configuración del RTC
#define RTC_SDA 21
#define RTC_SCL 22

#endif