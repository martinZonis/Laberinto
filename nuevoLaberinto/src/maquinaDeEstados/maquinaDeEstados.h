#pragma once

#include <arduino.h>

//=============================
// VARIABLES GLOBALES EXTERN
//=============================
extern sensado sensadoActual;

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
};

//=============================
// ESTADOS DE PRIMER RECORRIDO
//=============================

enum SUBMAQUINA_PRIMER_RECORRIDO {
    PARTIDA,
    ENTRE_CELDAS,
    MAPEO,
    LLEGADA,
};