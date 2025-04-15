# Documentación del Hardware

## Componentes Necesarios

- **Arduino ESP32**: Microcontrolador con WiFi y Bluetooth
- **Sensor de Huella Digital R307/FPM10A**: Para capturar y verificar huellas
- **Pantalla LCD I2C 16x2**: Para mostrar mensajes al usuario
- **LEDs RGB**: Para indicaciones visuales
- **Módulo RTC DS3231**: Para mantener la hora exacta
- **Caja protectora**: Para montar todos los componentes

## Esquema de Conexión

### Conexiones del ESP32

| Componente       | Pin ESP32    | Descripción                    |
| ---------------- | ------------ | ------------------------------ |
| Sensor de Huella | GPIO16 (RX)  | Comunicación serial            |
| Sensor de Huella | GPIO17 (TX)  | Comunicación serial            |
| LCD I2C          | GPIO21 (SDA) | Datos I2C                      |
| LCD I2C          | GPIO22 (SCL) | Reloj I2C                      |
| LED RGB          | GPIO25       | LED Rojo                       |
| LED RGB          | GPIO26       | LED Verde                      |
| LED RGB          | GPIO27       | LED Azul                       |
| RTC DS3231       | GPIO21 (SDA) | Datos I2C (compartido con LCD) |
| RTC DS3231       | GPIO22 (SCL) | Reloj I2C (compartido con LCD) |

## Diagrama del Circuito

```plaintext
+-------------+     +----------------+
|             |     |                |
|   ESP32     |<--->| Sensor Huella  |
|             |     |                |
+-------------+     +----------------+
      ^
      |
      v
+-------------+     +----------------+
|             |     |                |
|  LCD I2C    |<--->|   RTC DS3231   |
|             |     |                |
+-------------+     +----------------+
      ^
      |
      v
+-------------+
|             |
|   LED RGB   |
|             |
+-------------+
```

## Configuración del Sensor de Huella

El sensor de huella digital se comunica con el ESP32 mediante comunicación serial. Es importante configurar correctamente los pines RX y TX.

### Características del Sensor R307/FPM10A

- Voltaje de operación: 3.3V - 5V
- Corriente de operación: 100-150mA
- Capacidad de almacenamiento: 1000 huellas
- Tiempo de verificación: <1s
- Tasa de falsa aceptación (FAR): <0.001%
- Tasa de falso rechazo (FRR): <0.1%

## Montaje Físico

1. Montar el ESP32 en la placa base
2. Conectar el sensor de huella según el diagrama
3. Conectar la pantalla LCD I2C
4. Conectar el módulo RTC
5. Conectar los LEDs RGB con resistencias apropiadas
6. Asegurar todas las conexiones
7. Montar todo en la caja protectora
8. Asegurar la alimentación (5V, 2A recomendado)

## Consideraciones de Instalación

- Colocar el dispositivo a una altura accesible (aproximadamente 1.2m del suelo)
- Asegurar buena iluminación para el sensor de huella
- Proteger de la luz solar directa
- Asegurar conexión WiFi estable
- Proporcionar alimentación ininterrumpida (considerar batería de respaldo)
