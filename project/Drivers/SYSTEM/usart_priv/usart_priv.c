#include "usart_priv.h"

void USART(uint32_t BaudRate)
{
    USART_InitTypeDef USART1_InitStructure;
    USART1_InitStructure.BaudRate=BaudRate;
    USART1_InitStructure.CLKLastBit=
}