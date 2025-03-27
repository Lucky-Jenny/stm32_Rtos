/**
 * @file    Os_Cyclic.c
 * @version 1.0.0
 *
 * @brief    
 * @details This file defines all tasks with different periods.
 *
 * @author  Shawn Liu
 * @date    2025.03.25
 *   
 */

#ifdef __cplusplus
extern "C" {
#endif

/*==================[inclusions]============================================*/
#include "Os_Task.h"
#include "usart.h"
/*==================[internal constants]====================================*/
/*==================[internal macros]=======================================*/
/*==================[internal type definitions]=============================*/
/*==================[internal function declarations]========================*/
/*==================[internal data]=========================================*/
/*==================[external function definitions]=========================*/
void Task_Init(void)
{
    //StateM_Init();
}

void Task_5msTask(void)
{

}

void Task_10msTask(void)
{
    //BswM_MainFunction();
}

void Task_20msTask(void)
{

}

void Task_50msTask(void)
{

}

void Task_100msTask(void)
{
    //HAL_UART_Transmit(&huart1, (uint8_t*) "Task_100ms Runing.\n", 20, 10);
}

void Task_500msTask(void)
{
    HAL_UART_Transmit(&huart1, (uint8_t*) "Task_500ms Runing.", 18, 10);
}

#ifdef __cplusplus
}
#endif

