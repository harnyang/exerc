#include "led.h"			
void led_init(void)
{
	led_gpio_init();
}	

void led_gpio_init(void)
{
	LED1_RCC_CLK_ENABLE();//_这里时钟开启两次的  原因是因为这里的两个GPIO_PORT可能不一样
	LED2_RCC_CLK_ENABLE();//_如果这里的端口和上面的端口分组一样那么就不能重复开启。

	GPIO_InitTypeDef LED_GPIO_InitStructure;
	LED_GPIO_InitStructure.Mode=GPIO_MODE_OUTPUT_PP;
	LED_GPIO_InitStructure.Pin=LED1_PIN;
	LED_GPIO_InitStructure.Pull=GPIO_NOPULL;
	LED_GPIO_InitStructure.Speed=GPIO_SPEED_FREQ_MEDIUM;
	HAL_GPIO_Init(LED1_GPIO_PORT, &LED_GPIO_InitStructure);
	
	LED_GPIO_InitStructure.Pin=LED2_PIN;
	HAL_GPIO_Init(LED2_GPIO_PORT, &LED_GPIO_InitStructure);
	LED1(0);
	LED2(0);
}

void led_breath(void)
{
	LED1(0);
	LED2(1);
	delay_us(500);
	LED1(1);
	LED2(0);
}
