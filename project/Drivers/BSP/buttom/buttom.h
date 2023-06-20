#ifndef __BUT_H_
#define __BUT_H_

#define __BUTTOM_

#include "./SYSTEM/sys/sys.h"
#include "led.h"

#define KEY0_GPIO_PORT  GPIOE
#define KEY0_GPIO_PIN GPIO_PIN_4

#define KEY1_GPIO_PORT GPIOE
#define KEY1_GPIO_PIN GPIO_PIN_3

#define KEY2_GPIO_PORT GPIOE
#define KEY2_GPIO_PIN GPIO_PIN_2

#define KEY0_RCC_CLK_ENABLE()   do\
{\
    __HAL_RCC_GPIOE_CLK_ENABLE();\
} while (0);


#define KEY0_Handler() do
{
    EXTI4_IRQHandler();

} while (0);
#define KEY0_IRQn EXTI4_IRQn
#define KEY0_IRQHandler()  EXTI4_IRQHandler()


void KEY0_IRQHandler(void);

void Buttom_Init(void);
void Buttom_GPIO_Init(void);
void Buttom_NVIV_Init(void);
void Buttom_Control_LED(void);


#endif