#include "fingerprint.h"
#include "config.h"
#include <Adafruit_Fingerprint.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(FINGERPRINT_RX, FINGERPRINT_TX);
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

bool fingerprintInit() {
  finger.begin(57600);
  
  if (finger.verifyPassword()) {
    return true;
  } else {
    return false;
  }
}

bool fingerprintDetect() {
  finger.getTemplateCount();
  return (finger.templateCount > 0);
}

int fingerprintIdentify() {
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK) return -1;

  p = finger.image2Tz();
  if (p != FINGERPRINT_OK) return -1;

  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK) return -1;
  
  return finger.fingerID;
}

bool fingerprintEnroll(int id) {
  // Implementación del proceso de registro de huella
  return true;
}

bool fingerprintDelete(int id) {
  // Implementación del proceso de eliminación de huella
  return true;
}