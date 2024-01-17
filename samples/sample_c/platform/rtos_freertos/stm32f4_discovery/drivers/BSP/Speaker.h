/**
 ********************************************************************
 * @file    Speaker.h
 * @version V2.0.0
 * @date    2024/1/15
 * @brief   This is the header file for "Speaker.c", defining the structure and
 * (exported) function prototypes.
 *
 * @copyright (c) 2024 Senen. All rights reserved.
 */

#ifndef SPEAKER_H
#define SPEAKER_H

#include "uart.h"
#include "stm32f4xx_hal.h"
#include "dji_ringbuffer.h"
#include "FreeRTOS.h"
#include "task.h"
#include "osal.h"
#include "stm32f4xx.h"
#include <stdio.h>

#define DEBUG_USART_BAUDRATE                    9600

//Òý½Å¶¨Òå
/*******************************************************/
#define DEBUG_USART                             UART4
#define DEBUG_USART_CLK_ENABLE()                __UART4_CLK_ENABLE();

#define RCC_PERIPHCLK_UARTx                     RCC_PERIPHCLK_UART4
#define RCC_UARTxCLKSOURCE_SYSCLK               RCC_UART4CLKSOURCE_SYSCLK

#define DEBUG_USART_RX_GPIO_PORT                GPIOA
#define DEBUG_USART_RX_GPIO_CLK_ENABLE()        __GPIOA_CLK_ENABLE()
#define DEBUG_USART_RX_PIN                      GPIO_PIN_1
#define DEBUG_USART_RX_AF                       GPIO_AF8_UART4

#define DEBUG_USART_TX_GPIO_PORT                GPIOA
#define DEBUG_USART_TX_GPIO_CLK_ENABLE()        __GPIOA_CLK_ENABLE()
#define DEBUG_USART_TX_PIN                      GPIO_PIN_0
#define DEBUG_USART_TX_AF                       GPIO_AF8_UART4

#define DEBUG_USART_IRQHandler                  UART4_IRQHandler
#define DEBUG_USART_IRQ                 		    UART4_IRQn
/************************************************************/

void Usart_SendString(uint8_t *str,uint8_t size);
void DEBUG_USART_Config(void);
//int fputc(int ch, FILE *f);
extern UART_HandleTypeDef UartHandle;
#endif /* __USART1_H */
