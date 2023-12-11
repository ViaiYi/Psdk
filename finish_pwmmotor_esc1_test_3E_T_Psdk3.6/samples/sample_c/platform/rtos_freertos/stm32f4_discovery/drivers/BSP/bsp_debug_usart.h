#ifndef __DEBUG_USART_H
#define	__DEBUG_USART_H

#include "stm32f4xx.h"
#include <stdio.h>

//串口波特率
#define DEBUG_USART_BAUDRATE                    9600

//引脚定义
/*******************************************************/
#define DEBUG_USART                             UART4
#define DEBUG_USART_CLK_ENABLE()                __UART4_CLK_ENABLE();

#define RCC_PERIPHCLK_UARTx                     RCC_PERIPHCLK_UART4
#define RCC_UARTxCLKSOURCE_SYSCLK               RCC_UART4CLKSOURCE_SYSCLK

#define DEBUG_USART_RX_GPIO_PORT                GPIOC
#define DEBUG_USART_RX_GPIO_CLK_ENABLE()        __GPIOC_CLK_ENABLE()
#define DEBUG_USART_RX_PIN                      GPIO_PIN_11
#define DEBUG_USART_RX_AF                       GPIO_AF8_UART4

#define DEBUG_USART_TX_GPIO_PORT                GPIOC
#define DEBUG_USART_TX_GPIO_CLK_ENABLE()        __GPIOC_CLK_ENABLE()
#define DEBUG_USART_TX_PIN                      GPIO_PIN_10
#define DEBUG_USART_TX_AF                       GPIO_AF8_UART4

#define DEBUG_USART_IRQHandler                  UART4_IRQHandler
#define DEBUG_USART_IRQ                 		    UART4_IRQn
/************************************************************/

void Usart_SendString(uint8_t *str,uint8_t size);
void DEBUG_USART_Config(void);
//int fputc(int ch, FILE *f);
extern UART_HandleTypeDef UartHandle;
#endif /* __USART1_H */
