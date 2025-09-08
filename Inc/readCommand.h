/*
 * readCommand.h
 *
 *  Created on: Sep 7, 2025
 *      Author: Ivani
 */

#ifndef READCOMMAND_H_
#define READCOMMAND_H_
#include <stdint.h>
#define UART_BUFFER_SIZE 128

extern volatile char uart_buffer[]; //Arreglo char para el almacenado de datos bluetooth
extern volatile uint8_t uart_head, uart_tail; //Variables para byte de incio y parada del mensaje USART
extern char cmd_buffer[];//Buffer para lectura de recepción
extern uint8_t idx;//Indice

void readCommand(void);

#endif /* READCOMMAND_H_ */
