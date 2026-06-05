#include "maquinaDeEstados.h"

void calibrar(){
    bool salirDelLoop = false; //Acción bloqueante
    SUBMAQUINA_CALIBRAR subestadoActual = SENSOR_IZQ;
    while (salirDelLoop == false){
        
    }
}

void primerRecorrido(){
    bool salirDelLoop = false; //Acción bloqueante
    SUBMAQUINA_PRIMER_RECORRIDO subestadoActual = PARTIDA;
    while (salirDelLoop == false){
        switch(subestadoActual){
            case PARTIDA: {

            };
            case ENTRE_CELDAS: {
                
            };
        }
    }
}

void segundoRecorrido(){
    bool salirDelLoop = false; //Acción bloqueante
    while (salirDelLoop == false){
        
    }
}