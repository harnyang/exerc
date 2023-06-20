#ifndef  __USART_
#define  __USART_

#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/delay/delay.h"

#define USART1_RX_GPIO_PORT GPIOA //根据需求进行更改
#define USART1_RX_GPIO_PIN GPIO_PIN_2///
#define USART1_RX_GPIO_ENABLE() do\
{\
    __HAL_RCC_GPIOA_CLK_ENABLE();\///
} while (0);


#define USART1_TX_GPIO_PORT GPIOA
#define USART1_TX_GPIO_PIN GPIO_PIN_3///
#define USART1_TX_GPIO_ENABLE() do\
{\
    __HAL_RCC_GPIOA_CLK_ENABLE();\ ///
} while (0);

#define USART_UX_IRQn  USART1_IRQn 
#define USART_UX_Handler() USART1_IRQHandler()
#define USART_UX  USART1

#define BUFFERSIZE 1
#define USART_RECIVE_LENGTH  200 //最大接受字节数

#define USART_CLK_ENBALE() do\
{\
    __HAL_RCC_USART1_CLK_ENABLE();\
} while (0);

#endif
