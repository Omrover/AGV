/*
 * BluetoothInit.c
 *
 *  Created on: Sep 7, 2025
 *      Author: Ivani
 */
#include "bluetoothInit.h"
#include "stm32f051x8.h"

void bluetoothInit(void){
	RCC->APB1ENR |= RCC_APB1ENR_USART2EN;//Habilitar Reloj para el periférico de comunicación USART

	// Configurar pines PA2 (TX) y PA3 (RX) como función alterna
	GPIOA->MODER |= (GPIO_MODER_MODER2_1 | GPIO_MODER_MODER3_1);
	GPIOA->AFR[0] |= (1 << (2*4)) | (1 << (3*4));//AF1

	USART2->BRR = 8000000 / 9600;  // Baudrate a 9600 (8 MHz clock)
	USART2->CR1 = USART_CR1_TE | USART_CR1_RE | USART_CR1_UE | USART_CR1_RXNEIE;//Habilitar transmisor, receptor, USART y  la interrupción para recepción

	NVIC_SetPriority(USART2_IRQn, 2);//Definir prioridad de interrupción media
	NVIC_EnableIRQ(USART2_IRQn);//Habilitar rutina de interrupción
}



