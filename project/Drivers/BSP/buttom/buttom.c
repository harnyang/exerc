#include "buttom.h"

void Buttom_NVIV_Init(void)
{
    KEY0_RCC_CLK_ENABLE();   
    GPIO_InitTypeDef Buttom_InitStrute;
    Buttom_InitStrute.Mode=GPIO_MODE_EVT_FALLING;
    Buttom_InitStrute.Pin=KEY0_GPIO_PIN;
    Buttom_InitStrute.Pull=GPIO_PULLUP;
    Buttom_InitStrute.Speed=GPIO_SPEED_FREQ_MEDIUM;

    HAL_GPIO_Init(KEY0_GPIO_PORT,&Buttom_InitStrute);
    HAL_NVIC_SetPriority(KEY0_IRQn,2,2);
    HAL_NVIC_EnableIRQ(KEY0_IRQn);
}

void Buttom_GPIO_Init(void)
{
    KEY0_RCC_CLK_ENABLE();   
    GPIO_InitTypeDef Buttom_InitStrute;
    Buttom_InitStrute.Mode=GPIO_MODE_INPUT;
    Buttom_InitStrute.Pin=KEY0_GPIO_PIN;
    Buttom_InitStrute.Pull=GPIO_PULLUP;
    Buttom_InitStrute.Speed=GPIO_SPEED_FREQ_MEDIUM;

    HAL_GPIO_Init(KEY0_GPIO_PORT,&Buttom_InitStrute);
}

void Buttom_Init(void)
{
    #ifdef  __BUTTOM_NVIC_
    Buttom_NVIV_Init();
    #elif  __BUTTOM_
    Buttom_GPIO_Init();
    #endif
}
void EXTI4_IRQHandler(void)
{
    if (__HAL_GPIO_EXTI_GET_IT(KEY0_GPIO_PIN)!=0)
    {
        LED2(0);
        __HAL_GPIO_EXTI_CLEAR_IT(KEY0_GPIO_PIN);
    }
    
}

void Buttom_Control_LED(void)
{
    if(HAL_GPIO_ReadPin(KEY0_GPIO_PIN)!=1)
    {
        delay_ms(20);//延迟用于消抖
        if (HAL_GPIO_ReadPin(KEY0_GPIO_PIN)!=1)
        {
            LED1(1);
        }
        
    }
}