/*
 * processCommand.c
 *
 *  Created on: Sep 7, 2025
 *      Author: Ivani
 */
#include "processCommand.h"
#include <stdio.h>
#include "setDuty.h"


void processCommand(const char* cmd) {//Función para procesar comando de acción
    int duty, channel;
    if(sscanf(cmd, "%d %d", &duty, &channel) == 2) {//Escanea del buffer los argumentos para el set duty
        if(channel >= 1 && channel <= 4) {//Validación de comando
            setDuty(channel, duty);//Call a set duty
        }
    }
}
