#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>

// Inicializa la pantalla LCD
void displayInit();

// Muestra un mensaje en la pantalla
void displayMessage(String message);

// Muestra un mensaje con dos líneas
void displayMessage(String line1, String line2);

#endif