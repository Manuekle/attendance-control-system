# Sistema de Control de Asistencia

Sistema completo para el control de asistencia de empleados utilizando tecnología de huella digital y una plataforma web.

## Características

- Registro de entrada/salida mediante huella digital
- Panel de administración web
- Reportes de asistencia
- Gestión de empleados y departamentos
- Soporte para múltiples empresas
- Funcionamiento offline con sincronización posterior

## Estructura del Proyecto

- `arduino/`: Código para el hardware (ESP32 + sensor de huella)
- `web/`: Aplicación web (Next.js)
- `docs/`: Documentación
- `scripts/`: Scripts de utilidad

## Requisitos

### Hardware

- ESP32
- Sensor de huella digital (R307 o FPM10A)
- Pantalla LCD (opcional)
- LEDs indicadores
- Módulo RTC

### Software

- Node.js 18+
- PostgreSQL 14+
- Arduino IDE

## Instalación

### Configuración de la Base de Datos

1. Crea una base de datos PostgreSQL
2. Actualiza la variable de entorno `DATABASE_URL` en el archivo `.env`
3. Ejecuta las migraciones de Prisma:

```bash
cd web
npx prisma migrate dev
```

### Configuración de la Aplicación Web

1. Instala las dependencias:

```bash
cd web
npm install
```

2. Configura las variables de entorno:

```bash
cp .env.example .env
```

3. Inicia el servidor de desarrollo:

```bash
npm run dev
```

### Configuración del Hardware

1. Abre el proyecto en Arduino IDE
2. Instala las bibliotecas necesarias:

   - Adafruit Fingerprint Sensor
   - LiquidCrystal_I2C
   - ArduinoJson
   - RTClib

3. Actualiza la configuración en `config.h`
4. Compila y carga el sketch en el ESP32

## Uso

1. Accede a la aplicación web en `http://localhost:3000`
2. Inicia sesión con las credenciales de administrador
3. Configura tu empresa y departamentos
4. Registra empleados y sus huellas digitales
5. Configura los dispositivos de asistencia
6. Comienza a registrar la asistencia
