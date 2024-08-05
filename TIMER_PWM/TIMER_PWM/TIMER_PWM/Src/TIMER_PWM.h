#ifndef _TIMER_PWM_H
#define _TIMER_PWM_H

#define Timer1 1
#define Timer2 2
#define Timer3 3

#define Timer1_Prescalar                2
#define Timer1_Priod                    2
#define Timer1_Pulse                    2

#define Timer2_Prescalar                2
#define Timer2_Priod                    2
#define Timer2_Pulse                    2

#define Timer3_Prescalar                2
#define Timer3_Priod                    2
#define Timer3_Pulse                    2


void HAL_MspInit(void);
void HAL_MspInit(void);
void HAL_MspDeInit(void);
extern int MX_GPIO_Init(void);
extern int MX_TIM1_Init(void);
extern int MX_TIM2_Init(void);
extern int MX_TIM3_Init(void);
extern uint8_t Reset_UIF(uint32_t Timer);

#endif