/*
 * readCommand.c
 *
 *  Created on: Sep 7, 2025
 *      Author: Ivani
 */
#include "stm32f051x8.h"
#include "readCommand.h"
#include "processCommand.h"

// Definir las variables declaradas externas
volatile char uart_buffer[UART_BUFFER_SIZE];//Buffer de 128 caracteres
volatile uint8_t uart_head = 0, uart_tail = 0;//indices del buffer, (storage y reading)
char cmd_buffer[32];//Buffer para el mensaje a procesar
uint8_t idx = 0;//Indice del buffer pequeño

void USART2_IRQHandler(void) {//Algoritmo de buffer circular
    if(USART2->ISR & USART_ISR_RXNE) {//Verifica si se recibe un dato al activarse la flag de interrupción
        uart_buffer[uart_head] = USART2->RDR;//Almacena el último dato recibido en el buffer
        uart_head = (uart_head + 1) % UART_BUFFER_SIZE;//Actualiza el indice y evita desbordamiento
    }
}
void readCommand(void){
while(uart_head != uart_tail) {//Si tenemos datos nuevos
	char c = uart_buffer[uart_tail];//Leemos el dato almacenado en el buffer
	uart_tail = (uart_tail + 1) % UART_BUFFER_SIZE;//Actualizamos posición

	if(c == '\r' || c == '\n') {//Se detecta salto de linea
		cmd_buffer[idx] = '\0';//Cierra la cadena para string válido
		processCommand(cmd_buffer);//Procesa el comando
		idx = 0;//Reinicia el indice
	}
	else if(idx < sizeof(cmd_buffer)-1) {//Evita overflow
		cmd_buffer[idx++] = c;//Guarda caracter en la posición y luego cambia posición
	}
}}
