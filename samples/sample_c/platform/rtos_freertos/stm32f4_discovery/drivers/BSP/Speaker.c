#include "Speaker.h"
void SYN_FrameInfo(uint8_t *HZdata)
{
/****************SYN8086**********************************/ 
		 unsigned  char Frame_Info[50]; 
		 unsigned  int  HZ_Length;  
		 //uint8_t word;
	     uint8_t i=0; 
		 HZ_Length =strlen(HZdata); 			
 		 
/*****************头帧**************************************/           
		 Frame_Info[0] = 0xFD ; 			
		 Frame_Info[1] = 0x00 ; 			
		 Frame_Info[2] = 0x0A; 		
		 Frame_Info[3] = 0x01 ; 				 		 
		 Frame_Info[4] = 0x05;       
 	  
         memcpy(&Frame_Info[5], HZdata, HZ_Length);
		 Usart_SendString((uint8_t *)Frame_Info,5+HZ_Length);
		 //for(i=0;i<HZ_Length;i++){
			//word = Frame_Info[i];
			//Usart_SendString(word);
		 //}
		 //Usart_SendString(&Frame_Info); 
}



UART_HandleTypeDef UartHandle;
 
void DEBUG_USART_Config(void)
{ 
  HAL_UART4_MspInit(UartHandle);
	
	
  UartHandle.Instance          = DEBUG_USART;
  
  UartHandle.Init.BaudRate     = DEBUG_USART_BAUDRATE;
  UartHandle.Init.WordLength   = UART_WORDLENGTH_8B;
  UartHandle.Init.StopBits     = UART_STOPBITS_1;
  UartHandle.Init.Parity       = UART_PARITY_NONE;
  UartHandle.Init.HwFlowCtl    = UART_HWCONTROL_NONE;
  UartHandle.Init.Mode         = UART_MODE_TX_RX;
  
  HAL_UART_Init(&UartHandle);
    

  __HAL_UART_ENABLE_IT(&UartHandle,UART_IT_RXNE);  
	
	
}



void HAL_UART4_MspInit(UART_HandleTypeDef *huart)
{  
  GPIO_InitTypeDef  GPIO_InitStruct;
  
  DEBUG_USART_CLK_ENABLE();
	
  DEBUG_USART_RX_GPIO_CLK_ENABLE();
  DEBUG_USART_TX_GPIO_CLK_ENABLE();
  
/**USART1 GPIO Configuration    
  PA10     ------> USART1_TX
  PA11    ------> USART1_RX 
  */
  /* ����Tx����Ϊ���ù���  */
  GPIO_InitStruct.Pin = DEBUG_USART_TX_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = DEBUG_USART_TX_AF;
  HAL_GPIO_Init(DEBUG_USART_TX_GPIO_PORT, &GPIO_InitStruct);
  
  /* ����Rx����Ϊ���ù��� */
  GPIO_InitStruct.Pin = DEBUG_USART_RX_PIN;
  GPIO_InitStruct.Alternate = DEBUG_USART_RX_AF;
  HAL_GPIO_Init(DEBUG_USART_RX_GPIO_PORT, &GPIO_InitStruct); 
 
  HAL_NVIC_SetPriority(DEBUG_USART_IRQ ,0,1);	//��ռ���ȼ�0�������ȼ�1
  HAL_NVIC_EnableIRQ(DEBUG_USART_IRQ );		    //ʹ��USART1�ж�ͨ��  
}


/*****************  �����ַ��� **********************/
void Usart_SendString(uint8_t *str,uint8_t size)
{
	uint8_t k=0;
  do 
  {
      HAL_UART_Transmit(&UartHandle,(uint8_t *)(str + k) ,1,1000);
      k++;
  } while(k < size);
  
}
///�ض���c�⺯��printf������DEBUG_USART���ض�����ʹ��printf����
int fputc1(int ch, FILE *f)
{
	/* ����һ���ֽ����ݵ�����DEBUG_USART */
	HAL_UART_Transmit(&UartHandle, (uint8_t *)&ch, 1, 1000);	
	
	return (ch);
}

///�ض���c�⺯��scanf������DEBUG_USART����д����ʹ��scanf��getchar�Ⱥ���
int fgetc1(FILE *f)
{
		
	int ch;
	HAL_UART_Receive(&UartHandle, (uint8_t *)&ch, 1, 1000);	
	return (ch);
}
/*********************************************END OF FILE**********************/
