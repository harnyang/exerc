#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/usart/usart.h"
#include "./SYSTEM/delay/delay.h"
#include "./BSP/led/led.h"
void led_init(void); /* LED ??????? */
//int main(void)
//{
// HAL_Init(); /* ??? HAL ? */
// sys_stm32_clock_init(RCC_PLL_MUL9); /* ????, 72Mhz */
// delay_init(72); /* ????? */
// led_init(); /* LED ??? */
// while(1)
// {
// HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,GPIO_PIN_SET); /* PB5 ? 1 */
// HAL_GPIO_WritePin(GPIOE,GPIO_PIN_5,GPIO_PIN_RESET); /* PE5 ? 0 */
// delay_ms(500);
// HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,GPIO_PIN_SET); /* PB5 ? 1 */
// HAL_GPIO_WritePin(GPIOE,GPIO_PIN_5,GPIO_PIN_RESET); /* PE5 ? 0 */
// delay_ms(500);
// }
//}
/**
* @brief ??? LED ?? IO ?, ?????
* @param ?
* @retval ?
*/

int main(void)
{
	HAL_Init();
	sys_stm32_clock_init(RCC_PLL_MUL9);//将锁相环倍频系数设置为9倍
	delay_init(72);
	led_init();
	led_breath();
}
