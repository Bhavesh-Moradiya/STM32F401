#include "stm32f4xx_hal.h"
#include "LSM6Ds0.h"

uint16_t tmp = 0;

uint8_t OUT_6D_X_L_G[1], OUT_6D_X_H_G[1], OUT_6D_Y_L_G[1];
uint8_t OUT_6D_Y_H_G[1], OUT_6D_Z_H_G[1], OUT_6D_Z_L_G[1];
uint8_t OUT_6D_X_L_A[1], OUT_6D_X_H_A[1], OUT_6D_Y_L_A[1];
uint8_t OUT_6D_Y_H_A[1], OUT_6D_Z_H_A[1], OUT_6D_Z_L_A[1];

float GYRO_OUT_X = 0, GYRO_OUT_Y = 0, GYRO_OUT_Z = 0;
float ACCE_OUT_X = 0, ACCE_OUT_Y = 0, ACCE_OUT_Z = 0;

void LSM6Ds0_AG_Reg_RW(void)
{
  HAL_I2C_IsDeviceReady(&hi2c1, LSM6Ds0_ADD_W, 10, TimeOut);
  HAL_REG_WRITE(&hi2c1, LSM6Ds0_ADD_W, CTRL_REG8, 0x44, 2, TimeOut);
  HAL_REG_WRITE(&hi2c1, LSM6Ds0_ADD_W, CTRL_REG1_G, 0x60, 2, TimeOut);
  HAL_REG_WRITE(&hi2c1, LSM6Ds0_ADD_W, CTRL_REG2_G, 0x00, 2, TimeOut);
  HAL_REG_WRITE(&hi2c1, LSM6Ds0_ADD_W, CTRL_REG3_G, 0x00, 2, TimeOut);
  HAL_REG_WRITE(&hi2c1, LSM6Ds0_ADD_W, CTRL_REG2_G, 0x00, 2, TimeOut);
  HAL_REG_WRITE(&hi2c1, LSM6Ds0_ADD_W, ORIENT_CFG_G, 0x00, 2, TimeOut);
  HAL_REG_WRITE(&hi2c1, LSM6Ds0_ADD_W, CTRL_REG4, 0xE0, 2, TimeOut);
  HAL_REG_WRITE(&hi2c1, LSM6Ds0_ADD_W, CTRL_REG9, 0x00, 2, TimeOut);
  HAL_REG_WRITE(&hi2c1, LSM6Ds0_ADD_W, CTRL_REG5_XL, 0x38, 2, TimeOut);
  HAL_REG_WRITE(&hi2c1, LSM6Ds0_ADD_W, CTRL_REG6_XL, 0x70, 2, TimeOut);
  HAL_REG_WRITE(&hi2c1, LSM6Ds0_ADD_W, CTRL_REG7_XL, 0x00, 2, TimeOut);
}
  
void LSM6Ds0_AG_Reg_R(void)
{
  HAL_DATA_WRITE(&hi2c1, LSM6Ds0_ADD_W, OUT_X_H_G, 1, TimeOut);
  HAL_DATA_READ(&hi2c1, LSM6Ds0_ADD_R, OUT_6D_X_H_G, 1, TimeOut);
  HAL_I2C_IsDeviceReady(&hi2c1, LSM6Ds0_ADD_W, 10, TimeOut);
  HAL_DATA_WRITE(&hi2c1, LSM6Ds0_ADD_W, OUT_X_L_G, 1, TimeOut);
  HAL_DATA_READ(&hi2c1, LSM6Ds0_ADD_R, OUT_6D_X_L_G, 1, TimeOut);
  HAL_I2C_IsDeviceReady(&hi2c1, LSM6Ds0_ADD_W, 10, TimeOut);
  if((OUT_6D_X_H_G[1] & MASK) == MASK)
  {
    tmp = ~((OUT_6D_X_H_G[1] << LSHF) | OUT_6D_X_L_G[1]);
    GYRO_OUT_X = tmp * GRES;
  }
  else
  {
    tmp = ((OUT_6D_X_H_G[1] << LSHF) | OUT_6D_X_L_G[1]);
    GYRO_OUT_X = tmp * GRES;
  }
  
  HAL_DATA_WRITE(&hi2c1, LSM6Ds0_ADD_W, OUT_Y_H_G, 1, TimeOut);
  HAL_DATA_READ(&hi2c1, LSM6Ds0_ADD_R, OUT_6D_Y_H_G, 1, TimeOut);
  HAL_I2C_IsDeviceReady(&hi2c1, LSM6Ds0_ADD_W, 10, TimeOut);
  HAL_DATA_WRITE(&hi2c1, LSM6Ds0_ADD_W, OUT_Y_L_G, 1, TimeOut);
  HAL_DATA_READ(&hi2c1, LSM6Ds0_ADD_R, OUT_6D_Y_L_G, 1, TimeOut);
  HAL_I2C_IsDeviceReady(&hi2c1, LSM6Ds0_ADD_W, 10, TimeOut);
  if((OUT_6D_Y_H_G[1] & MASK) == MASK)
  {
    tmp = ~((OUT_6D_Y_H_G[1] << LSHF) | OUT_6D_Y_L_G[1]);
    GYRO_OUT_Y = tmp * GRES;
  }
  else
  {
    tmp = ((OUT_6D_Y_H_G[1] << LSHF) | OUT_6D_Y_L_G[1]);
    GYRO_OUT_Y = tmp * GRES;
  }
  
  HAL_DATA_WRITE(&hi2c1, LSM6Ds0_ADD_W, OUT_Z_H_G, 1, TimeOut);
  HAL_DATA_READ(&hi2c1, LSM6Ds0_ADD_R, OUT_6D_Z_H_G, 1, TimeOut);
  HAL_I2C_IsDeviceReady(&hi2c1, LSM6Ds0_ADD_W, 10, TimeOut);
  HAL_DATA_WRITE(&hi2c1, LSM6Ds0_ADD_W, OUT_Z_L_G, 1, TimeOut);
  HAL_DATA_READ(&hi2c1, LSM6Ds0_ADD_R, OUT_6D_Z_L_G, 1, TimeOut);
  HAL_I2C_IsDeviceReady(&hi2c1, LSM6Ds0_ADD_W, 10, TimeOut);
  if((OUT_6D_Z_H_G[1] & MASK) == MASK)
  {
    tmp = ~((OUT_6D_Z_H_G[1] << LSHF) | OUT_6D_Z_L_G[1]);
    GYRO_OUT_Z = tmp * GRES;
  }
  else
  {
    tmp = ((OUT_6D_Z_H_G[1] << LSHF) | OUT_6D_Z_L_G[1]);
    GYRO_OUT_Z = tmp * GRES;
  }
  
  HAL_DATA_WRITE(&hi2c1, LSM6Ds0_ADD_W, OUT_X_H_G, 1, TimeOut);
  HAL_DATA_READ(&hi2c1, LSM6Ds0_ADD_R, OUT_6D_X_H_G, 1, TimeOut);
  HAL_I2C_IsDeviceReady(&hi2c1, LSM6Ds0_ADD_W, 10, TimeOut);
  HAL_DATA_WRITE(&hi2c1, LSM6Ds0_ADD_W, OUT_X_L_G, 1, TimeOut);
  HAL_DATA_READ(&hi2c1, LSM6Ds0_ADD_R, OUT_6D_X_L_G, 1, TimeOut);
  HAL_I2C_IsDeviceReady(&hi2c1, LSM6Ds0_ADD_W, 10, TimeOut);
  if((OUT_6D_X_H_G[1] & MASK) == MASK)
  {
    tmp = ~((OUT_6D_X_H_G[1] << LSHF) | OUT_6D_X_L_G[1]);
    GYRO_OUT_X = tmp * GRES;
  }
  else
  {
    tmp = ((OUT_6D_X_H_G[1] << LSHF) | OUT_6D_X_L_G[1]);
    GYRO_OUT_X = tmp * GRES;
  }
  
  /****************************************************************************/
  
  HAL_DATA_WRITE(&hi2c1, LSM6Ds0_ADD_W, OUT_X_H_XL, 1, TimeOut);
  HAL_DATA_READ(&hi2c1, LSM6Ds0_ADD_R, OUT_6D_X_H_A, 1, TimeOut);
  HAL_I2C_IsDeviceReady(&hi2c1, LSM6Ds0_ADD_W, 10, TimeOut);
  HAL_DATA_WRITE(&hi2c1, LSM6Ds0_ADD_W, OUT_X_L_XL, 1, TimeOut);
  HAL_DATA_READ(&hi2c1, LSM6Ds0_ADD_R, OUT_6D_X_L_A, 1, TimeOut);
  HAL_I2C_IsDeviceReady(&hi2c1, LSM6Ds0_ADD_W, 10, TimeOut);
  if((OUT_6D_X_H_A[1] & MASK) == MASK)
  {
    tmp = ~((OUT_6D_X_H_A[1] << LSHF) | OUT_6D_X_L_A[1]);
    ACCE_OUT_X = tmp * ARES;
  }
  else
  {
    tmp = ((OUT_6D_X_H_A[1] << LSHF) | OUT_6D_X_L_A[1]);
    ACCE_OUT_X = tmp * ARES;
  }
  
  HAL_DATA_WRITE(&hi2c1, LSM6Ds0_ADD_W, OUT_Y_H_XL, 1, TimeOut);
  HAL_DATA_READ(&hi2c1, LSM6Ds0_ADD_R, OUT_6D_Y_H_A, 1, TimeOut);
  HAL_I2C_IsDeviceReady(&hi2c1, LSM6Ds0_ADD_W, 10, TimeOut);
  HAL_DATA_WRITE(&hi2c1, LSM6Ds0_ADD_W, OUT_Y_L_XL, 1, TimeOut);
  HAL_DATA_READ(&hi2c1, LSM6Ds0_ADD_R, OUT_6D_Y_L_A, 1, TimeOut);
  HAL_I2C_IsDeviceReady(&hi2c1, LSM6Ds0_ADD_W, 10, TimeOut);
  if((OUT_6D_Y_H_A[1] & MASK) == MASK)
  {
    tmp = ~((OUT_6D_Y_H_A[1] << LSHF) | OUT_6D_Y_L_A[1]);
    ACCE_OUT_Y = tmp * ARES;
  }
  else
  {
    tmp = ((OUT_6D_Y_H_A[1] << LSHF) | OUT_6D_Y_L_A[1]);
    ACCE_OUT_Y = tmp * ARES;
  }
  
  HAL_DATA_WRITE(&hi2c1, LSM6Ds0_ADD_W, OUT_Z_H_XL, 1, TimeOut);
  HAL_DATA_READ(&hi2c1, LSM6Ds0_ADD_R, OUT_6D_Z_H_A, 1, TimeOut);
  HAL_I2C_IsDeviceReady(&hi2c1, LSM6Ds0_ADD_W, 10, TimeOut);
  HAL_DATA_WRITE(&hi2c1, LSM6Ds0_ADD_W, OUT_Z_L_XL, 1, TimeOut);
  HAL_DATA_READ(&hi2c1, LSM6Ds0_ADD_R, OUT_6D_Z_L_A, 1, TimeOut);
  HAL_I2C_IsDeviceReady(&hi2c1, LSM6Ds0_ADD_W, 10, TimeOut);
  if((OUT_6D_Z_H_A[1] & MASK) == MASK)
  {
    tmp = ~((OUT_6D_Z_H_A[1] << LSHF) | OUT_6D_Z_L_A[1]);
    ACCE_OUT_Z = tmp * ARES;
  }
  else
  {
    tmp = ((OUT_6D_Z_H_A[1] << LSHF) | OUT_6D_Z_L_A[1]);
    ACCE_OUT_Z = tmp * ARES;
  }
}