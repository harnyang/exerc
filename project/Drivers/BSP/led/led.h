#ifndef _LED_H_
#define _LED_H_


#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/delay/delay.h"

#define LED1_GPIO_PORT          GPIOB
#define LED1_PIN                GPIO_PIN_1
#define LED1_RCC_CLK_ENABLE()   do{ __HAL_RCC_GPIOB_CLK_ENABLE(); }while(0)

#define LED2_GPIO_PORT          GPIOA
#define LED2_PIN                GPIO_PIN_2
#define LED2_RCC_CLK_ENABLE()   do{ __HAL_RCC_GPIOA_CLK_ENABLE(); }while(0)

#define LED1(x) do{ x ? \
												HAL_GPIO_WritePin(LED1_GPIO_PORT,LED1_PIN,GPIO_PIN_SET): \
												HAL_GPIO_WritePin(LED1_GPIO_PORT,LED1_PIN,GPIO_PIN_RESET);\
								}while(0)
#define LED2(x) do{( x ? \
												HAL_GPIO_WritePin(LED2_GPIO_PORT,LED2_PIN,GPIO_PIN_SET): \
												HAL_GPIO_WritePin(LED2_GPIO_PORT,LED2_PIN,GPIO_PIN_RESET));\
								}while(0)
#define LED1_REVERSE( ) \
            						do {HAL_GPIO_TogglePin(LED1_GPIO_PORT,LED1_PIN);}\
            						while(0)
#define LED2_REVERSE( ) \
									do {HAL_GPIO_TogglePin(LED1_GPIO_PORT,LED1_PIN);}\
									while(0)
								
void led_gpio_init(void);
void led_breath(void);
void led_init(void);
									
#endif					
