#include "stm32f4xx_hal.h"
#include "TIMER_PWM.h"

int main(void)
{
  HAL_Init();
  MX_GPIO_Init();
  MX_TIM1_Init();
  MX_TIM2_Init();
  MX_TIM3_Init();

  while (1)
  {
    Reset_UIF(Timer1);
    Reset_UIF(Timer2);
    Reset_UIF(Timer3);
  }
}

#ifdef USE_FULL_ASSERT

void assert_failed(uint8_t* file, uint32_t line)
{
}

#endif

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
