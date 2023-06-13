#include "beep.h"

void beep_gpio_init(void)
{
    GPIO_InitTypeDef beep_InitStructure;
    BEEP_RCC_CLK_ENABLE();

    beep_InitStructure.Mode=GPIO_MODE_OUTPUT_PP;
    beep_InitStructure.Pin=BEEP_GPIO_PIN;
    beep_InitStructure.Pull=GPIO_NOPULL;
    beep_InitStructure.Speed=GPIO_SPEED_FREQ_MEDIUM;

    HAL_GPIO_Init(BEEP_GPIO_PORT,&beep_InitStructure);

}
void beep_init(void)
{
    beep_gpio_init();
}
void beep_breath()
{
    BEEP(1);
    delay_ms(500);
    BEEP(0);
    delay_ms(500);

}
void beepAndled_breath(void)
{
    BEEP(1);
    LED1(0);
    LED2(0);
    delay_ms(500);
    BEEP(0);
    LED1(1);
    LED2(1);
    delay_ms(500);
}
