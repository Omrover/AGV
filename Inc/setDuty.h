/*
 * setDuty.h
 *
 *  Created on: Sep 7, 2025
 *      Author: Ivani
 */

#ifndef SETDUTY_H_
#define SETDUTY_H_
#define PWM_MAX_DUTY 100 //Ciclo de trabajo máximo
#include <stdint.h>

void setDuty(uint8_t channel, uint8_t duty);

#endif /* SETDUTY_H_ */
