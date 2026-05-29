#include "main.h"
#include <Arduino.h>
#include "hardware/logger/logger.h"
#include "hardware/sensoresDistancia/sensoresDistancia.h"
#include "hardware/sensorPiso/sensorPiso.h"
#include "memoria/funcionesMapeo.h"
#include "hardware/movimiento/PID.h"

//==============================================================
//                CREAMOS EL MANEJO DE TAREAS
//==============================================================

TaskHandle_t taskOneMovimiento = NULL;
TaskHandle_t taskTwoDecision = NULL;
TaskHandle_t taskThreeUART = NULL;

//==============================================================
//                CREACIÓN DE VARIABLES GLOBALES
//==============================================================

sensado sensadoActual = {0,0,0};
POSICION posicionActual = {X_START,Y_START, NORTE};


//==============================================================
//                     VOID SETUP
//==============================================================

void setup (){
  inicializarLogger();
  inicializacionSensoresDist();
}

//==============================================================
//    ANULAMOS VOID LOOP DE ARDUINO PARA NO CONSUMIR RECURSOS
//==============================================================

void loop(){
  vTaskDelete(NULL);
}

//==============================================================
//  TAREA 1: Principal, es un loop infinito con un secuencial
/*      SECUENCIA:
         * "Lee" los sensores de distancia y piso
         *  A partir de la lectura de "sensado sensadoAct" calcula el dif de PID
         *  Lee la queue de movimientos
         *  Realiza los cambios en el puente H (hardware/movimiento)
*/
//==============================================================

void taskOneMovimiento(void *parameter){
  for(;;){
    //Actualiza sensores
    sensadoActual = actualizarSensado(); //Falta la lectura del sensor de piso
    calcularDiferencialPID();
    
    //Lee queue de movimiento
    //Cambio en el puente H
  }
}

void taskTwoDecision(void *parameter){
  //Lee ultimo sensado (es global la variable)

}