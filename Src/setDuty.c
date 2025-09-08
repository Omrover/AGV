/*
 * setDuty.c
 *
 *  Created on: Sep 7, 2025
 *      Author: Ivani
 */

#include "setDuty.h";
#include "stm32f051x8.h"

void setDuty(uint8_t channel, uint8_t duty) {//Handler para pwm
    if(duty > PWM_MAX_DUTY) duty = PWM_MAX_DUTY;//Evitamos overflow de ciclo
    uint16_t value = duty * (TIM3->ARR + 1) / 100;//Ponemos el ciclo en escala de 0 a 100

    switch(channel) {//Dependiendo el comando recibido
        case 1: TIM3->CCR1 = value; TIM3->CCR3 = value; break;//Adelante
        case 2: TIM3->CCR2 = value; TIM3->CCR3 = value; break;//Derecha
        case 3: TIM3->CCR1 = value; TIM3->CCR4 = value; break;//Izquierda
        case 4: TIM3->CCR2 = value; TIM3->CCR4 = value; break;//Atras
    }
}
