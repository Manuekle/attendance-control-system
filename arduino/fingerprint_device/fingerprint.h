#ifndef FINGERPRINT_H
#define FINGERPRINT_H

// Inicializa el sensor de huella digital
bool fingerprintInit();

// Detecta si hay un dedo en el sensor
bool fingerprintDetect();

// Identifica una huella y devuelve su ID
int fingerprintIdentify();

// Registra una nueva huella
bool fingerprintEnroll(int id);

// Elimina una huella
bool fingerprintDelete(int id);

#endif