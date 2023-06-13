#ifndef   __BEEP_H_
#define   __BEEP_H_

#include "./SYSTEM/sys/sys.h"//这个文件夹中包含了stm32f1xx.h头文件，而stm32f1xx.h头文件包含了HAL库头文件，所以有
#include "./SYSTEM/delay/delay.h"
#include "beep.h"
#include "./led/led.h"

#define  BEEP_GPIO_PORT  GPIOA
#define  BEEP_GPIO_PIN   GPIO_PIN_2
#define  BEEP_RCC_CLK_ENABLE()  do { __HAL_RCC_GPIOB_CLK_ENABLE(); }while(0)

#define  BEEP(x)  do{\
    (x ? HAL_GPIO_WritePin(BEEP_GPIO_PORT,BEEP_GPIO_PIN,GPIO_PIN_SET):\
        HAL_GPIO_WritePin(BEEP_GPIO_PORT,BEEP_GPIO_PIN,GPIO_PIN_RESET));\
}while(0)
#define  BEEP_REVERSE()  do{\
    HAL_GPIO_TogglePin(BEEP_GPIO_PORT,BEEP_GPIO_PIN);\
}while(0)


void beep_init(void);
void beep_gpio_init(void);
void beepAndled_breath(void);
void beep_breath(void);

#endif
