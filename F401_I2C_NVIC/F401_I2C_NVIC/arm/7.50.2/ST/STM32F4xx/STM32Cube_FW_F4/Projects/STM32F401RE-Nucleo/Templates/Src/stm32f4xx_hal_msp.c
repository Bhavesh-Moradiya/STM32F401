#include "stm32f4xx_hal.h"

uint8_t Temp[2];
uint8_t T_OUT_L[1], T_OUT_H[1];

void DS1621_Read_write(void)
{
    HAL_I2C_IsDeviceReady(&hi2c1, DS1621_ADD_W, 10, TimeOut);
    HAL_DATA_WRITE(&hi2c1, DS1621_ADD_W, DS1621_ACC_CTR, 1, TimeOut);
    HAL_DATA_WRITE(&hi2c1, DS1621_ADD_W, DS1621_CON_MOD, 1, TimeOut);
    HAL_DATA_WRITE(&hi2c1, DS1621_ADD_W, DS1621_CTR_TH_M, 1, TimeOut);
    HAL_DATA_WRITE(&hi2c1, DS1621_ADD_W, DS1621_MAX_TEMP_MSB, 1, TimeOut);        
    HAL_DATA_WRITE(&hi2c1, DS1621_ADD_W, DS1621_MAX_TEMP_LSB, 1, TimeOut);
    HAL_DATA_WRITE(&hi2c1, DS1621_ADD_W, DS1621_CTR_TH_L, 1, TimeOut);
    HAL_DATA_WRITE(&hi2c1, DS1621_ADD_W, DS1621_MIN_TEMP_MSB, 1, TimeOut);
    HAL_DATA_WRITE(&hi2c1, DS1621_ADD_W, DS1621_MIN_TEMP_LSB, 1, TimeOut);
    HAL_DATA_WRITE(&hi2c1, DS1621_ADD_W, DS1621_STR_CONV, 1, TimeOut);
    HAL_DATA_WRITE(&hi2c1, DS1621_ADD_W, DS1621_TEMP_REG, 1, TimeOut);
    HAL_DATA_READ(&hi2c1, DS1621_ADD_R, Temp, 2, TimeOut);
}

void delay__(int i)
{
  for(volatile int y = 0; y <= 60; y++)
  {
    for(volatile int j = i; j >= 0; j--);
  }
}

void HAL_MspInit(void)
{
  HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);
  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}

/**
  * @brief  DeInitializes the Global MSP.
  * @param  None  
  * @retval None
  */
void HAL_MspDeInit(void)
{
  /* NOTE : This function is generated automatically by MicroXplorer and eventually  
            modified by the user
   */
}

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
