#include "main.h"
#include <Arduino.h>
#include "hardware/logger/logger.h"
#include "hardware/sensoresDistancia/sensoresDistancia.h"
#include "hardware/sensorPiso/sensorPiso.h"
#include "config.h"
#include "hardware/movimiento/puenteH.h"

//====================
// VARIABLES GLOBALES
//====================

sensado lecturaActual = {0,0,0};
ORIENTACION orientacionActual = NORTE;
POSICION posicionActual = {X_START,Y_START, NORTE};
POSICION posicionContigua = {(X_START), (Y_START - 1), NORTE};
//Las posiciones de MOVIMIENTOS son ABSOLUTAS, es realmente lo que están haciendo los motores
MOVIMIENTOS movimientoAnterior = FRENO_F;
ESTADOS_ETAPA_1 estadoActual = PARTIDA;

void setup(){
  inicializacionSensoresDist();
  inicializarLogger();
}

void loop(){
  switch (estadoActual){
    case PARTIDA: {
      actualizarSensado();
      
      break;
    };
    case ENTRE_CELDAS: {
      break;
    };
    case FIN_CELDA: {
      break;
    };
    case FIN:{
      break;
    };
  }
}