#pragma once

#include <arduino.h>
#include "hardware/sensoresDistancia/sensoresDistancia.h"

//=============================
// VARIABLES GLOBALES EXTERN
//=============================
extern sensado sensadoActual;
extern bool salirDelLoop;

void calibrar();
void primerRecorrido();
void segundoRecorrido();

//======================
// ESTADOS DE CALIBRAR
//======================

enum SUBMAQUINA_CALIBRAR {
    SENSOR_IZQ,
    SENSOR_CENT,
    SENSOR_DER,
    QTR,
    MOTOR_IZQ,
    MOTOR_DER
}; SUBMAQUINA_CALIBRAR subestadoActualCalibrar = SENSOR_IZQ;

//=============================
// ESTADOS DE PRIMER RECORRIDO
//=============================

enum SUBMAQUINA_PRIMER_RECORRIDO {
    PARTIDA,
    ENTRE_CELDAS,
    MAPEO,
    LLEGADA,
}; SUBMAQUINA_PRIMER_RECORRIDO subestadoActualPrimerRecorrido = PARTIDA;