/*
 * pwmInit.c
 *
 *  Created on: Sep 7, 2025
 *      Author: Ivani
 */
#include "pwmInit.h";
#include "stm32f051x8.h"

void pwmInit (void){
	RCC->AHBENR |= RCC_AHBENR_GPIOCEN;
	RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
	for (int i = 6;i<=9;i++){
		GPIOC->MODER &=~(0x3<<i*2);//Máscara para limpieza de los bits
		GPIOC->MODER |=(0x2<<i*2);// 0x2 = 1 0, modo alternativo
	}
	for (int i = 6;i<=7;i++){
		GPIOC->AFR[0]&=~(0xF<<6*4);//Función alternativa pwm
		GPIOC->AFR[1]&=~(0xF<<(i-6)*4);//Función alternativa pwm
		}
	TIM3->PSC=7;//(8MHz /(7+1)
	TIM3->ARR=999;//Alto hasta contar 1000 veces, depués inicia overflow count
	TIM3->CCMR1|=(0x6<<4)|(0x6<<12);//Mode PWM1
	TIM3->CCMR2|=(0x6<<4)|(0x6<<12);
    TIM3->CCER = TIM_CCER_CC1E | TIM_CCER_CC2E | TIM_CCER_CC3E | TIM_CCER_CC4E;//Hablitar los cuatro channels
	//Iniciar en 0% el dutycycle
    TIM3->CCR1=0;
	TIM3->CCR2=0;
	TIM3->CCR3=0;
	TIM3->CCR4=0;
    TIM3->CR1|=(1<<0);//Habilitar el conteo

}

