#include "logger.h"
#include <Arduino.h>

void logger::enviarCelda(uint8_t celda){
    Serial.write(celda);
}